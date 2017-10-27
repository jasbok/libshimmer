#include "vertex_array.h"

using namespace glpp;

vertex_array::vertex_array()
    : _handle ( 0 )
{
    glGenVertexArrays ( 1, &_handle );
}

vertex_array::vertex_array( vertex_array&& move )
    : _handle ( move._handle )
{
    move._handle = 0;
}

vertex_array::~vertex_array() {
    glDeleteVertexArrays ( 1, &_handle );
}

vertex_array& vertex_array::operator=( vertex_array&& move ) {
    _handle = move._handle;

    move._handle = 0;

    return *this;
}

GLuint vertex_array::handle() const {
    return _handle;
}

vertex_array& vertex_array::bind() {
    glBindVertexArray ( _handle );

    return *this;
}

void vertex_array::unbind() {
    glBindVertexArray ( 0 );
}
