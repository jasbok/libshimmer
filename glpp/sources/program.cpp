#include "program.h"

#include <vector>

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

void program::attach ( const glpp::shader& shader ) {
    glAttachShader ( _handle, shader.handle() );
}

void program::detach ( const glpp::shader& shader ) {
    glDetachShader ( _handle, shader.handle() );
}

void program::link() {
    glLinkProgram ( _handle );
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

void program::use() const {
    glUseProgram ( _handle );
}

GLint program::attribute_location ( const std::string& name ) const {
    return glGetAttribLocation ( _handle, name.c_str() );
}

GLint program::uniform_location ( const std::string& name ) const {
    return glGetUniformLocation ( _handle, name.c_str() );
}
