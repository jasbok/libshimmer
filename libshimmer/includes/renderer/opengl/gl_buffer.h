#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_BUFFER_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_BUFFER_H

#include "memory_block.h"

#include "accessor_macros.h"

#include <GL/glew.h>

namespace shimmer
{
class gl_buffer : public memory_block
{
public:
    gl_buffer( GLenum     target,
               GLsizeiptr size,
               GLenum     usage,
               GLenum     access );

    virtual ~gl_buffer();

    void  bind();

    void* map();

    void  unmap();

private:
    GETTER ( GLuint, handle );

    GETTER ( GLenum, target );

    GETTER_OVERRIDE ( std::size_t, size );

    GETTER ( GLenum, usage );

    GETTER ( GLenum, access );

    GETTER_OVERRIDE ( void*, data );
};
}

#endif // ifndef LIBSHIMMER_RENDERER_OPENGL_GL_BUFFER_H
