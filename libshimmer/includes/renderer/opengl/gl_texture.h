#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_TEXTURE_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_TEXTURE_H

#include "texture.h"
#include <GL/glew.h>

namespace shimmer
{
class gl_texture : public texture
{
public:
    gl_texture (
        unsigned int width,
        unsigned int height,
        GLenum target = GL_TEXTURE_2D,
        GLint level = 0,
        GLint internal_format = GL_RGB );

    virtual ~gl_texture();

    void bind();

    void upload ( GLenum format,
                  GLenum type,
                  const GLvoid* data );

    void upload ( GLenum format,
                  GLenum type,
                  const GLvoid* data,
                  GLint x_offset,
                  GLint y_offset,
                  GLsizei width,
                  GLsizei height );

    void download ( GLenum format,
                    GLenum type,
                    GLvoid* data );

private:
    GETTER ( gl_texture, GLuint, handle );

    GETTER ( gl_texture, GLenum, target );

    GETTER ( gl_texture, GLint, level );
};
}

#endif
