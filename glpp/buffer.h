#ifndef GLPP_BUFFER_H
#define GLPP_BUFFER_H

#include "enums.h"

#include <GL/glew.h>

#include <cstdint>
#include <memory>
#include <vector>

namespace glpp
{
template<GLenum TARGET, typename THIS>
class _buffer
{
    static_assert (
        TARGET == GL_ARRAY_BUFFER
        || TARGET == GL_ATOMIC_COUNTER_BUFFER
        || TARGET == GL_COPY_READ_BUFFER
        || TARGET == GL_COPY_WRITE_BUFFER
        || TARGET == GL_DISPATCH_INDIRECT_BUFFER
        || TARGET == GL_DRAW_INDIRECT_BUFFER
        || TARGET == GL_ELEMENT_ARRAY_BUFFER
        || TARGET == GL_PIXEL_PACK_BUFFER
        || TARGET == GL_PIXEL_UNPACK_BUFFER
        || TARGET == GL_QUERY_BUFFER
        || TARGET == GL_SHADER_STORAGE_BUFFER
        || TARGET == GL_TEXTURE_BUFFER
        || TARGET == GL_TRANSFORM_FEEDBACK_BUFFER
        || TARGET == GL_UNIFORM_BUFFER,
        "Unsupported TARGET for buffer." );

public:
    explicit _buffer( enum usage usage = usage::static_draw )
        : _handle ( 0 ),
          _usage ( usage ),
          _elements ( 0 ),
          _size ( 0 )
    {
        glGenBuffers ( 1, &_handle );
    }

    _buffer( _buffer&& move )
        : _handle ( move._handle ),
          _usage ( move._usage ),
          _elements ( move._elements ),
          _size ( move._size )
    {
        move._handle = 0;
    }

    _buffer( const _buffer& copy ) = delete;

    virtual ~_buffer() {
        glDeleteBuffers ( 1, &_handle );
    }

    _buffer& operator=( _buffer&& move ) {
        glDeleteBuffers ( 1, &_handle );

        _handle   = move._handle;
        _usage    = move._usage;
        _elements = move._elements;
        _size     = move._size;

        move._handle = 0;

        return static_cast<THIS&>( *this );
    }

    _buffer& operator=( const _buffer& copy ) = delete;


    GLuint handle() const {
        return _handle;
    }

    enum usage usage() const {
        return _usage;
    }

    size_t elements() const {
        return _elements;
    }

    size_t size() const {
        return _size;
    }

    THIS& bind() {
        glBindBuffer ( static_cast<GLenum>( TARGET ), _handle );

        return static_cast<THIS&>( *this );
    }

    static void unbind() {
        glBindBuffer ( static_cast<GLenum>( TARGET ), 0 );
    }

    template<typename T, size_t T_SIZE = sizeof( T )>
    THIS& data ( const std::vector<T>& vec ) {
        _elements = vec.size();
        _size     = T_SIZE * _elements;

        glBufferData ( static_cast<GLenum>( TARGET ),
                       _size,
                       &vec[0],
                       static_cast<GLenum>( _usage ) );

        return static_cast<THIS&>( *this );
    }

    template<typename T, size_t T_SIZE = sizeof( T )>
    THIS& data ( const std::vector<T>& vec,
                 enum usage            usage ) {
        _elements = vec.size();
        _size     = T_SIZE * _elements;
        _usage    = usage;

        glBufferData ( static_cast<GLenum>( TARGET ),
                       _size,
                       &vec[0],
                       static_cast<GLenum>( _usage ) );

        return static_cast<THIS&>( *this );
    }

private:
    GLuint _handle;

    enum usage _usage;

    size_t _elements;

    size_t _size;
};

template<GLenum TARGET>
class buffer : public _buffer<TARGET, buffer<TARGET>>
{};
}

#endif // ifndef GLPP_BUFFER_H
