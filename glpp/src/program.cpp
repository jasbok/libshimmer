#include "program.h"
#include "shader.h"

#include <glm/gtc/type_ptr.hpp>

using namespace glpp;
using namespace std;

program::program()
    : _handle ( glCreateProgram() )
{}

program::program( program&& move )
    : _handle ( move._handle )
{
    move._handle = 0;
}

program::~program() {
    glDeleteProgram ( _handle );
}

program& program::operator=( program&& move ) {
    _handle      = move._handle;
    move._handle = 0;

    return *this;
}

program& program::attach ( const glpp::shader& shader ) {
    glAttachShader ( _handle, shader.handle() );

    return *this;
}

program& program::detach ( const glpp::shader& shader ) {
    glDetachShader ( _handle, shader.handle() );

    return *this;
}

program& program::link() {
    glLinkProgram ( _handle );

    return *this;
}

bool program::link_status() const {
    GLint success;

    glGetProgramiv ( _handle, GL_LINK_STATUS, &success );

    return success;
}

string program::info_log ( size_t size ) const {
    vector<GLchar> buffer ( size );
    glGetProgramInfoLog ( _handle, size, nullptr, &buffer[0] );

    return string ( &buffer[0] );
}

program& program::link_and_throw ( size_t log_size ) {
    if ( link().link_status() ) return *this;

    throw link_exception ( info_log ( log_size ) );
}

program& program::use() {
    glUseProgram ( _handle );

    return *this;
}

void program::unbind() {
    glUseProgram ( 0 );
}

GLint program::attribute_location ( const string& name ) const {
    const auto& item = _attrib_locations.find ( name );

    if ( item != _attrib_locations.end() ) {
        return item->second;
    }

    GLint location = glGetAttribLocation ( _handle, name.c_str() );
    _attrib_locations.insert ( { name, location } );

    return location;
}

GLint program::uniform_location ( const string& name ) const {
    const auto& item = _uniform_locations.find ( name );

    if ( item != _uniform_locations.end() ) {
        return item->second;
    }

    GLint location = glGetUniformLocation ( _handle, name.c_str() );
    _uniform_locations.insert ( { name, location } );

    return location;
}

program& program::uniform ( const string& name, GLfloat v0 ) {
    glUniform1f ( uniform_location ( name ), v0 );

    return *this;
}

program& program::uniform ( const string& name, GLfloat v0,
                            GLfloat v1 ) {
    glUniform2f ( uniform_location ( name ), v0, v1 );

    return *this;
}

program& program::uniform ( const string& name, GLfloat v0,
                            GLfloat v1,
                            GLfloat v2 ) {
    glUniform3f ( uniform_location ( name ), v0, v1, v2 );

    return *this;
}

program& program::uniform ( const string& name, GLfloat v0,
                            GLfloat v1,
                            GLfloat v2,
                            GLfloat v3 ) {
    glUniform4f ( uniform_location ( name ), v0, v1, v2, v3 );

    return *this;
}

program& program::uniform ( const string& name, GLint v0 ) {
    glUniform1i ( uniform_location ( name ), v0 );

    return *this;
}

program& program::uniform ( const string& name, GLint v0,
                            GLint v1 ) {
    glUniform2i ( uniform_location ( name ), v0, v1 );

    return *this;
}

program& program::uniform ( const string& name, GLint v0,
                            GLint v1,
                            GLint v2 ) {
    glUniform3i ( uniform_location ( name ), v0, v1, v2 );

    return *this;
}

program& program::uniform ( const string& name, GLint v0,
                            GLint v1,
                            GLint v2,
                            GLint v3 ) {
    glUniform4i ( uniform_location ( name ), v0, v1, v2, v3 );

    return *this;
}

program& program::uniform ( const string& name, GLuint v0 ) {
    glUniform1ui ( uniform_location ( name ), v0 );

    return *this;
}

program& program::uniform ( const string& name, GLuint v0,
                            GLuint v1 ) {
    glUniform2ui ( uniform_location ( name ), v0, v1 );

    return *this;
}

program& program::uniform ( const string& name, GLuint v0,
                            GLuint v1,
                            GLuint v2 ) {
    glUniform3ui ( uniform_location ( name ), v0, v1, v2 );

    return *this;
}

program& program::uniform ( const string& name, GLuint v0,
                            GLuint v1,
                            GLuint v2,
                            GLuint v3 ) {
    glUniform4ui ( uniform_location ( name ), v0, v1, v2, v3 );

    return *this;
}

program& program::uniform ( const string&          name,
                            const vector<GLfloat>& value ) {
    switch ( value.size() ) {
    case 1:
        glUniform1fv ( uniform_location ( name ), value.size(), &value[0] );
        break;

    case 2:
        glUniform2fv ( uniform_location ( name ), value.size(), &value[0] );
        break;

    case 3:
        glUniform3fv ( uniform_location ( name ), value.size(), &value[0] );
        break;

    case 4:
        glUniform4fv ( uniform_location ( name ), value.size(), &value[0] );
        break;
    }

    return *this;
}

program& program::uniform ( const string&        name,
                            const vector<GLint>& value )  {
    switch ( value.size() ) {
    case 1:
        glUniform1iv ( uniform_location ( name ), value.size(), &value[0] );
        break;

    case 2:
        glUniform2iv ( uniform_location ( name ), value.size(), &value[0] );
        break;

    case 3:
        glUniform3iv ( uniform_location ( name ), value.size(), &value[0] );
        break;

    case 4:
        glUniform4iv ( uniform_location ( name ), value.size(), &value[0] );
        break;
    }

    return *this;
}

program& program::uniform ( const string&         name,
                            const vector<GLuint>& value ) {
    switch ( value.size() ) {
    case 1:
        glUniform1uiv ( uniform_location ( name ), value.size(), &value[0] );
        break;

    case 2:
        glUniform2uiv ( uniform_location ( name ), value.size(), &value[0] );
        break;

    case 3:
        glUniform3uiv ( uniform_location ( name ), value.size(), &value[0] );
        break;

    case 4:
        glUniform4uiv ( uniform_location ( name ), value.size(), &value[0] );
        break;
    }

    return *this;
}

program& program::uniform ( const string&          name,
                            const vector<GLfloat>& value,
                            unsigned int           cols,
                            bool                   transpose
                            ) {
    unsigned int rows = static_cast<unsigned int>( value.size() / cols );

    switch ( cols ) {
    case 2:

        switch ( rows ) {
        case 2:
            glUniformMatrix2fv ( uniform_location ( name ),
                                 value.size(),
                                 transpose,
                                 &value[0] );
            break;

        case 3:
            glUniformMatrix2x3fv ( uniform_location ( name ),
                                   value.size(),
                                   transpose,
                                   &value[0] );
            break;

        case 4:
            glUniformMatrix2x4fv ( uniform_location ( name ),
                                   value.size(),
                                   transpose,
                                   &value[0] );
            break;
        }
        break;

    case 3:

        switch ( rows ) {
        case 2:
            glUniformMatrix3x2fv ( uniform_location ( name ),
                                   value.size(),
                                   transpose,
                                   &value[0] );
            break;

        case 3:
            glUniformMatrix3fv ( uniform_location ( name ),
                                 value.size(),
                                 transpose,
                                 &value[0] );
            break;

        case 4:
            glUniformMatrix3x4fv ( uniform_location ( name ),
                                   value.size(),
                                   transpose,
                                   &value[0] );
            break;
        }
        break;

    case 4:

        switch ( rows ) {
        case 2:
            glUniformMatrix4x2fv ( uniform_location ( name ),
                                   value.size(),
                                   transpose,
                                   &value[0] );
            break;

        case 3:
            glUniformMatrix4x3fv ( uniform_location ( name ),
                                   value.size(),
                                   transpose,
                                   &value[0] );
            break;

        case 4:
            glUniformMatrix4fv ( uniform_location ( name ),
                                 value.size(),
                                 transpose,
                                 &value[0] );
            break;
        }
        break;
    }

    return *this;
}

program& program::uniform ( const std::string& name,
                            const glm::mat2&   value,
                            bool               transpose ) {
    glUniformMatrix2fv ( uniform_location ( name ),
                         1,
                         transpose,
                         glm::value_ptr ( value ) );

    return *this;
}

program& program::uniform ( const std::string& name,
                            const glm::mat3&   value,
                            bool               transpose ) {
    glUniformMatrix3fv ( uniform_location ( name ),
                         1,
                         transpose,
                         glm::value_ptr ( value ) );

    return *this;
}

program& program::uniform ( const std::string& name,
                            const glm::mat4&   value,
                            bool               transpose ) {
    glUniformMatrix4fv ( uniform_location ( name ),
                         1,
                         transpose,
                         glm::value_ptr ( value ) );

    return *this;
}

program::link_exception::link_exception( const string& log )
    : runtime_error (
          std::string ( "Failed to link program. " )
          + std::string ( "Log: " ) + log )
{}

program::link_exception::~link_exception() {}
