#include "gl_vertex_array.h"

using namespace shimmer;

gl_vertex_array::gl_vertex_array()
    : _handle()
{
    glGenVertexArrays ( 1, &_handle );
}

gl_vertex_array::~gl_vertex_array() {
    glDeleteVertexArrays ( 1, &_handle );
}

void gl_vertex_array::bind()
{
    glBindVertexArray ( _handle );
}

void gl_vertex_array::unbind()
{
    glBindVertexArray ( 0 );
}
