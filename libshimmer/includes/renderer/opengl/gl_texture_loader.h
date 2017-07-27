#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_TEXTURE_LOADER_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_TEXTURE_LOADER_H

#include "gl_texture.h"
#include <memory>

namespace shimmer
{
class gl_texture_loader
{
public:
    gl_texture_loader ( unsigned int write_buffer_count = 2,
                        unsigned int read_buffer_count = 1 );

    virtual ~gl_texture_loader();

    void upload ( const std::shared_ptr<gl_texture>& texture,
                  GLenum format,
                  GLenum type,
                  const GLvoid* data );

    void upload ( const std::shared_ptr<gl_texture>& texture,
                  GLenum format,
                  GLenum type,
                  const GLvoid* data,
                  GLint x_offset,
                  GLint y_offset,
                  GLsizei width,
                  GLsizei height );

    void download ( const std::shared_ptr<gl_texture>& texture,
                    GLenum format,
                    GLenum type,
                    GLvoid* data );

private:
    //
    // In / Upload
    //
    GLuint* _wo_pbo_array;
    unsigned int _wo_pbo_count;
    unsigned int _wo_pbo_index;

    GLuint _next_wo_pbo();

    //
    // Out / Download
    //
    GLuint* _ro_pbo_array;
    unsigned int _ro_pbo_count;
    unsigned int _ro_pbo_index;

    GLuint _next_ro_pbo();

    void* _map_buffer ( GLuint pbo,
                        GLenum target,
                        GLsizeiptr size,
                        GLenum access,
                        GLenum usage );
};
}

#endif
