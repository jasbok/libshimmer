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
vertex_array::attribute_pointers ( gl_type                  type,
                                   const vertex_attributes& attribs,
                                   bool                     normalised ) {
    auto type_size      = size_of ( type );
    unsigned int stride = 0;

    for ( const auto& a : attribs ) {
        stride += a.dimensions * type_size;
    }

    auto gl_enum          = static_cast<GLenum>(type);
    unsigned char* offset = 0;

    for ( const auto& a : attribs ) {
        if ( a.location > -1 ) {
            glVertexAttribPointer ( a.location,
                                    a.dimensions,
                                    gl_enum,
                                    normalised,
                                    stride,
                                    offset );
        }

        offset += a.dimensions * type_size;
    }

    return *this;
}

vertex_array&
vertex_array::enable_attribute_arrays ( const vector<int>& locations ){
    for(const auto& location : locations){
        glEnableVertexAttribArray ( location );
    }

    return *this;
}

vertex_array&
vertex_array::disable_attribute_arrays ( const vector<int>& locations ){
    for(const auto& location : locations){
        glDisableVertexAttribArray ( location );
    }

    return *this;
}
