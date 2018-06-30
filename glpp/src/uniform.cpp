#include "uniform.h"

using namespace glpp;
using namespace std;

uniform::uniform( GLint              location,
                  const std::string& name )
    : _location ( location ),
      _name ( name )
{}

uniform::uniform( uniform&& move )
    : _location ( move._location ),
      _name ( std::move ( move._name ) )
{
    move._location = -1;
}

uniform::~uniform() {}

uniform& uniform::operator=( uniform&& move ) {
    _location = move._location;
    _name     = std::move ( move._name );

    move._location = -1;

    return *this;
}

GLint uniform::location() const {
    return _location;
}

std::string uniform::name() const {
    return _name;
}

void uniform::set ( GLfloat v0 ) {
    glUniform1f ( _location, v0 );
}

void uniform::set ( GLfloat v0,
                    GLfloat v1 ) {
    glUniform2f ( _location, v0, v1 );
}

void uniform::set ( GLfloat v0,
                    GLfloat v1,
                    GLfloat v2 ) {
    glUniform3f ( _location, v0, v1, v2 );
}

void uniform::set ( GLfloat v0,
                    GLfloat v1,
                    GLfloat v2,
                    GLfloat v3 ) {
    glUniform4f ( _location, v0, v1, v2, v3 );
}

void uniform::set ( GLint v0 ) {
    glUniform1i ( _location, v0 );
}

void uniform::set ( GLint v0,
                    GLint v1 ) {
    glUniform2i ( _location, v0, v1 );
}

void uniform::set ( GLint v0,
                    GLint v1,
                    GLint v2 ) {
    glUniform3i ( _location, v0, v1, v2 );
}

void uniform::set ( GLint v0,
                    GLint v1,
                    GLint v2,
                    GLint v3 ) {
    glUniform4i ( _location, v0, v1, v2, v3 );
}

void uniform::set ( GLuint v0 ) {
    glUniform1ui ( _location, v0 );
}

void uniform::set ( GLuint v0,
                    GLuint v1 ) {
    glUniform2ui ( _location, v0, v1 );
}

void uniform::set ( GLuint v0,
                    GLuint v1,
                    GLuint v2 ) {
    glUniform3ui ( _location, v0, v1, v2 );
}

void uniform::set ( GLuint v0,
                    GLuint v1,
                    GLuint v2,
                    GLuint v3 ) {
    glUniform4ui ( _location, v0, v1, v2, v3 );
}

void uniform::set ( const std::vector<GLfloat>& value ) {
    switch ( value.size() ) {
    case 1:
        glUniform1fv ( _location, value.size(), &value[0] );
        break;

    case 2:
        glUniform2fv ( _location, value.size(), &value[0] );
        break;

    case 3:
        glUniform3fv ( _location, value.size(), &value[0] );
        break;

    case 4:
        glUniform4fv ( _location, value.size(), &value[0] );
        break;
    }
}

void uniform::set ( const std::vector<GLint>& value )  {
    switch ( value.size() ) {
    case 1:
        glUniform1iv ( _location, value.size(), &value[0] );
        break;

    case 2:
        glUniform2iv ( _location, value.size(), &value[0] );
        break;

    case 3:
        glUniform3iv ( _location, value.size(), &value[0] );
        break;

    case 4:
        glUniform4iv ( _location, value.size(), &value[0] );
        break;
    }
}

void uniform::set ( const std::vector<GLuint>& value ) {
    switch ( value.size() ) {
    case 1:
        glUniform1uiv ( _location, value.size(), &value[0] );
        break;

    case 2:
        glUniform2uiv ( _location, value.size(), &value[0] );
        break;

    case 3:
        glUniform3uiv ( _location, value.size(), &value[0] );
        break;

    case 4:
        glUniform4uiv ( _location, value.size(), &value[0] );
        break;
    }
}

void uniform::set ( const std::vector<GLfloat>& value,
                    unsigned int                cols,
                    bool                        transpose
                    ) {
    unsigned int rows = value.size() / cols;

    switch ( cols ) {
    case 2:

        switch ( rows ) {
        case 2:
            glUniformMatrix2fv ( _location,
                                 value.size(),
                                 transpose,
                                 &value[0] );
            break;

        case 3:
            glUniformMatrix2x3fv ( _location,
                                   value.size(),
                                   transpose,
                                   &value[0] );
            break;

        case 4:
            glUniformMatrix2x4fv ( _location,
                                   value.size(),
                                   transpose,
                                   &value[0] );
            break;
        }
        break;

    case 3:

        switch ( rows ) {
        case 2:
            glUniformMatrix3x2fv ( _location,
                                   value.size(),
                                   transpose,
                                   &value[0] );
            break;

        case 3:
            glUniformMatrix3fv ( _location,
                                 value.size(),
                                 transpose,
                                 &value[0] );
            break;

        case 4:
            glUniformMatrix3x4fv ( _location,
                                   value.size(),
                                   transpose,
                                   &value[0] );
            break;
        }
        break;

    case 4:

        switch ( rows ) {
        case 2:
            glUniformMatrix4x2fv ( _location,
                                   value.size(),
                                   transpose,
                                   &value[0] );
            break;

        case 3:
            glUniformMatrix4x3fv ( _location,
                                   value.size(),
                                   transpose,
                                   &value[0] );
            break;

        case 4:
            glUniformMatrix4fv ( _location,
                                 value.size(),
                                 transpose,
                                 &value[0] );
            break;
        }
        break;
    }
}
