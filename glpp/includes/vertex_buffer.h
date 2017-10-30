#ifndef GLPP_VERTEX_BUFFER_H
#define GLPP_VERTEX_BUFFER_H

#include "buffer.h"

#include "gsl/gsl"

namespace glpp
{
template<typename T, size_t T_SIZE = sizeof ( T ), GLenum T_ENUM = to_glenum<T>()>
class vertex_buffer : public _buffer<GL_ARRAY_BUFFER, vertex_buffer<T>>
{
    static_assert (is_gltype<T>(), "Unsupported TYPE for vertex buffer." );

    typedef _buffer<GL_ARRAY_BUFFER, vertex_buffer<T>> super;

public:
    struct vertex_attribute {
        int    location;
        size_t dimensions;
    };

    typedef std::vector<vertex_attribute> vertex_attributes;

    vertex_buffer&
    attribute_pointers ( const vertex_attributes& attribs,
                         bool                     normalised = false ) {
        unsigned int   stride = get_stride ( attribs );
        unsigned char* offset = 0;

        Expects ( super::size() != 0 );
        Expects ( super::size() % stride == 0 );

        for ( const auto& a : attribs ) {
            if ( a.location > -1 ) {
                glVertexAttribPointer ( a.location,
                                        a.dimensions,
                                        T_ENUM,
                                        normalised,
                                        stride,
                                        offset );
            }

            offset += a.dimensions * T_SIZE;
        }

        return *this;
    }

    unsigned int get_stride ( const vertex_attributes& attribs ) {
        unsigned int stride = 0;

        for ( const auto& a : attribs ) {
            stride += a.dimensions * T_SIZE;
        }

        return stride;
    }

    vertex_buffer& data ( const std::vector<T>& vec ) {
        return super::data( vec );
    }

    vertex_buffer& data ( const std::vector<T>& vec,
                          enum usage            usage ) {
        return super::data( vec, usage );
    }
};
}

#endif // ifndef GLPP_VERTEX_BUFFER_H
