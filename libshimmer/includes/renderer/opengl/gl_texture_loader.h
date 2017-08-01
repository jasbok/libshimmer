#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_TEXTURE_LOADER_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_TEXTURE_LOADER_H

#include "gl_texture.h"

#include <memory>

namespace shimmer
{
class gl_texture_loader
{
public:
    explicit gl_texture_loader( unsigned int buffer_count = 2 );

    virtual ~gl_texture_loader();

    void upload ( const std::shared_ptr<gl_texture>& texture,
                  GLenum                             format,
                  GLenum                             type,
                  const GLvoid*                      data );

    void upload ( const std::shared_ptr<gl_texture>& texture,
                  GLenum                             format,
                  GLenum                             type,
                  const GLvoid*                      data,
                  GLint                              x_offset,
                  GLint                              y_offset,
                  GLsizei                            width,
                  GLsizei                            height );

private:
    GLuint* _pbo_array;
    unsigned int _pbo_count;
    unsigned int _pbo_index;

    GLuint _next_pbo();

    void*  _map_buffer ( GLuint     pbo,
                         GLenum     target,
                         GLsizeiptr size,
                         GLenum     access,
                         GLenum     usage );
};
}

#endif // ifndef LIBSHIMMER_RENDERER_OPENGL_GL_TEXTURE_LOADER_H
