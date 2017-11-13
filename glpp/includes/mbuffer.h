#ifndef GLPP_MBUFFER_H
#define GLPP_MBUFFER_H

#include "buffer.h"

#include "gsl/span"

namespace glpp
{
struct buffer_data
{
    void*  ptr;
    size_t size;
};

template<GLenum TARGET, typename THIS>
class _mbuffer : public _buffer<TARGET, THIS>
{
    static_assert (
        TARGET == GL_ARRAY_BUFFER
        || TARGET == GL_ELEMENT_ARRAY_BUFFER
        || TARGET == GL_PIXEL_PACK_BUFFER
        || TARGET == GL_PIXEL_UNPACK_BUFFER,
        "Unsupported TARGET for mbuffer." );

    typedef _buffer<TARGET, THIS> parent;

public:
    explicit _mbuffer( enum usage usage = usage::static_draw )
        : parent ( usage )
    {}

    _mbuffer( _mbuffer&& move )
        :  parent ( std::move ( move ) )
    {}

    _mbuffer( const _mbuffer& copy ) = delete;

    ~_mbuffer() {}

    _mbuffer& operator=( _mbuffer&& move ) {
        parent::operator=( std::move ( move ) );

        return *this;
    }

    _mbuffer& operator=( const _mbuffer& copy ) = delete;

    template<typename T, size_t T_SIZE = sizeof( T )>
    gsl::span<T> map ( enum access access ) {
        auto ptr = glMapBuffer ( TARGET, static_cast<GLenum>( access ) );

        return gsl::span<T>( static_cast<T*>( ptr ),
                             static_cast<long>( parent::size() / T_SIZE ) );
    }

    bool unmap() {
        return glUnmapBuffer ( TARGET );
    }
};

template<GLenum TARGET>
class mbuffer : public _mbuffer<TARGET, mbuffer<TARGET>>
{};
}

#endif // ifndef GLPP_MBUFFER_H
