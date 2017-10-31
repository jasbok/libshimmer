#ifndef GLPP_VERTEX_BUFFER_H
#define GLPP_VERTEX_BUFFER_H

#include "mbuffer.h"

#include "gsl/gsl"

namespace glpp
{
template<typename T, size_t T_SIZE = sizeof(T), GLenum T_ENUM = to_glenum<T>()>
class vertex_buffer : public _mbuffer<GL_ARRAY_BUFFER,
                                      vertex_buffer<T, T_SIZE, T_ENUM>>
{
    static_assert ( is_gltype<T>(), "Unsupported TYPE for vertex buffer." );

    typedef _mbuffer<GL_ARRAY_BUFFER, vertex_buffer<T>> parent;

public:
    struct vertex_attribute {
        int    location;
        size_t dimensions;
    };

    typedef std::vector<vertex_attribute> vertex_attributes;

    vertex_buffer() : parent() {}

    vertex_buffer( vertex_buffer&& move )
        : parent ( std::move ( move ) )
    {}

    vertex_buffer( const vertex_buffer& copy ) = delete;

    ~vertex_buffer() {}

    vertex_buffer& operator=( vertex_buffer&& move )
    {
        parent::operator=( std::move(move) );

        return *this;
    }

    vertex_buffer& operator=( const vertex_buffer& copy ) = delete;

    vertex_buffer& bind(){
        return *this;
    }

    vertex_buffer&
    attribute_pointers ( const vertex_attributes& attribs,
                         bool                     normalised = false ) {
        unsigned int   stride = get_stride ( attribs );
        unsigned char* offset = 0;

        Expects ( parent::size() != 0 );
        Expects ( parent::size() % stride == 0 );

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
        return parent::data ( vec );
    }

    vertex_buffer& data ( const std::vector<T>& vec,
                          enum usage            usage ) {
        return parent::data ( vec, usage );
    }

    gsl::span<T> map ( enum access access ) {
        return parent::template map<T>( access );
    }
};
}

#endif // ifndef GLPP_VERTEX_BUFFER_H
