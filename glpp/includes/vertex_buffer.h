#ifndef GLPP_VERTEX_BUFFER_H
#define GLPP_VERTEX_BUFFER_H

#include "mbuffer.h"

#include "gsl/gsl"

namespace glpp
{
class vertex_buffer : public _mbuffer<GL_ARRAY_BUFFER, vertex_buffer>
{
    typedef _mbuffer<GL_ARRAY_BUFFER, vertex_buffer> parent;

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
};
}

#endif // ifndef GLPP_VERTEX_BUFFER_H
