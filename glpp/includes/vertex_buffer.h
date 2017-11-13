#ifndef GLPP_VERTEX_BUFFER_H
#define GLPP_VERTEX_BUFFER_H

#include "mbuffer.h"

#include "gsl/gsl"

namespace glpp
{
template<typename T,
         size_t T_SIZE = sizeof( T ),
         GLenum T_ENUM = to_glenum<T>( )>
class vertex_buffer : public _mbuffer<GL_ARRAY_BUFFER,
                                      vertex_buffer<T, T_SIZE, T_ENUM>>
{
    static_assert ( is_gltype<T>(), "Unsupported TYPE for vertex buffer." );

    typedef _mbuffer<GL_ARRAY_BUFFER, vertex_buffer<T>> parent;

public:
    explicit vertex_buffer( enum usage usage = usage::static_draw )
        : parent ( usage )
    {}

    vertex_buffer( vertex_buffer&& move )
        : parent ( std::move ( move ) )
    {}

    vertex_buffer( const vertex_buffer& copy ) = delete;

    ~vertex_buffer() {}

    vertex_buffer& operator=( vertex_buffer&& move )
    {
                   parent::operator=( std::move( move ) );

        return *this;
    }

    vertex_buffer& operator=( const vertex_buffer& copy ) = delete;

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
