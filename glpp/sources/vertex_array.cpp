#include "vertex_array.h"

#include "program.h"

using namespace glpp;
using namespace std;

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
    glDeleteVertexArrays ( 1, &_handle );

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

vertex_array&
vertex_array::enable_attribute_arrays ( const vector<GLint>& locations ) {
    for ( const auto& location : locations ) {
        glEnableVertexAttribArray ( location );
    }

    return *this;
}

vertex_array&
vertex_array::disable_attribute_arrays ( const vector<GLint>& locations ) {
    for ( const auto& location : locations ) {
        glDisableVertexAttribArray ( location );
    }

    return *this;
}
