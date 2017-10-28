#ifndef GLPP_BUFFER_H
#define GLPP_BUFFER_H

#include <GL/glew.h>

#include <cstdint>
#include <memory>
#include <vector>

namespace glpp
{
struct buffer_data
{
    void*  ptr;
    size_t size;
};

class buffer
{
public:
    enum class target : GLenum {
        gl_array_buffer              = GL_ARRAY_BUFFER,
        gl_atomic_counter_buffer     = GL_ATOMIC_COUNTER_BUFFER,
        gl_copy_read_buffer          = GL_COPY_READ_BUFFER,
        gl_copy_write_buffer         = GL_COPY_WRITE_BUFFER,
        gl_dispatch_indirect_buffer  = GL_DISPATCH_INDIRECT_BUFFER,
        gl_draw_indirect_buffer      = GL_DRAW_INDIRECT_BUFFER,
        gl_element_array_buffer      = GL_ELEMENT_ARRAY_BUFFER,
        gl_pixel_pack_buffer         = GL_PIXEL_PACK_BUFFER,
        gl_pixel_unpack_buffer       = GL_PIXEL_UNPACK_BUFFER,
        gl_query_buffer              = GL_QUERY_BUFFER,
        gl_shader_storage_buffer     = GL_SHADER_STORAGE_BUFFER,
        gl_texture_buffer            = GL_TEXTURE_BUFFER,
        gl_transform_feedback_buffer = GL_TRANSFORM_FEEDBACK_BUFFER,
        gl_uniform_buffer            = GL_UNIFORM_BUFFER
    };

    enum class usage : GLenum {
        gl_stream_draw  = GL_STREAM_DRAW,
        gl_stream_read  = GL_STREAM_READ,
        gl_stream_copy  = GL_STREAM_COPY,
        gl_static_draw  = GL_STATIC_DRAW,
        gl_static_read  = GL_STATIC_READ,
        gl_static_copy  = GL_STATIC_COPY,
        gl_dynamic_draw = GL_DYNAMIC_DRAW,
        gl_dynamic_read = GL_DYNAMIC_READ,
        gl_dynamic_copy = GL_DYNAMIC_COPY
    };

    buffer( enum target target,
            enum usage  usage = usage::gl_static_draw );

    buffer( buffer&& move );

    buffer( const buffer& copy ) = delete;

    virtual ~buffer();

    buffer& operator=( buffer&& move );

    buffer& operator=( const buffer& copy ) = delete;


    GLuint      handle() const;

    enum target target() const;

    enum usage usage() const;

    size_t     size() const;


    buffer& bind();

    void    unbind();


    buffer& data (  const void* data,
                    size_t      size );

    buffer& data (  const void* data,
                    size_t      size,
                    enum usage  usage );

    template<typename T, size_t S = sizeof(T)>
    buffer& data ( const std::vector<T>& vec ) {
        return data ( &vec[0], S * vec.size() );
    }

    template<typename T, size_t S = sizeof(T)>
    buffer& data ( const std::vector<T>& vec,
                   enum usage            usage ) {
        return data ( &vec[0], S * vec.size(), usage );
    }

private:
    GLuint _handle;

    enum target _target;

    enum usage _usage;

    size_t _size;
};
}

#endif // ifndef GLPP_BUFFER_H
