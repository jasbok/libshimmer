#ifndef LIBSHIMMER_RENDERER_OPENGL_PIXEL_BUFFER_H
#define LIBSHIMMER_RENDERER_OPENGL_PIXEL_BUFFER_H

#include "gl_buffer.h"

namespace shimmer
{
class gl_pixel_buffer : public gl_buffer
{
public:
    gl_pixel_buffer( GLenum     target,
                     GLsizeiptr size,
                     GLenum     access,
                     GLenum     usage,
                     GLenum     format,
                     GLenum     type );

    virtual ~gl_pixel_buffer() {}

private:
    GETTER ( GLenum, format );

    GETTER ( GLenum, type );
};
}

#endif // ifndef LIBSHIMMER_RENDERER_OPENGL_PIXEL_BUFFER_H
