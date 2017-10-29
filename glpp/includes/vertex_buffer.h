#ifndef GLPP_VERTEX_BUFFER_H
#define GLPP_VERTEX_BUFFER_H

#include "buffer.h"

namespace glpp
{
template<GLenum TYPE>
class vertex_buffer : public _buffer<GL_ARRAY_BUFFER, vertex_buffer<TYPE>>
{
    static_assert (
        TYPE == GL_BYTE
        || TYPE == GL_FIXED
        || TYPE == GL_FLOAT
        || TYPE == GL_SHORT
        || TYPE == GL_UNSIGNED_BYTE
        || TYPE == GL_UNSIGNED_SHORT,
        "Unsupported TYPE for vertex buffer." );

public:
    struct vertex_attribute {
        int    location;
        size_t dimensions;
    };

    typedef std::vector<vertex_attribute> vertex_attributes;

    vertex_buffer&
    attribute_pointers ( const vertex_attributes& attribs,
                         bool                     normalised = false ) {
        auto type_size      = size_of ( TYPE );
        unsigned int stride = 0;

        for ( const auto& a : attribs ) {
            stride += a.dimensions * type_size;
        }

        unsigned char* offset = 0;

        for ( const auto& a : attribs ) {
            if ( a.location > -1 ) {
                glVertexAttribPointer ( a.location,
                                        a.dimensions,
                                        TYPE,
                                        normalised,
                                        stride,
                                        offset );
            }

            offset += a.dimensions * type_size;
        }

        return *this;
    }

private:
};
}

#endif // ifndef GLPP_VERTEX_BUFFER_H
