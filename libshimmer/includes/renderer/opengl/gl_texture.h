#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_TEXTURE_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_TEXTURE_H

#include "texture.h"

#include <GL/glew.h>

#include <memory>
#include <vector>

namespace shimmer
{
class gl_texture : public texture
{
public:
    gl_texture( GLenum        target,
                GLint         level,
                GLint         internal_format,
                GLsizei       width,
                GLsizei       height,
                GLenum        format,
                GLenum        type,
                const GLvoid* data );

    virtual ~gl_texture();

    void bind() const;

    void upload ( GLenum        format,
                  GLenum        type,
                  const GLvoid* data );

    void upload ( GLenum        format,
                  GLenum        type,
                  const GLvoid* data,
                  GLint         x_offset,
                  GLint         y_offset,
                  GLsizei       width,
                  GLsizei       height );

    void download ( GLenum  format,
                    GLenum  type,
                    GLvoid* data ) const;

private:
    GETTER ( GLuint, handle );

    GETTER ( GLenum, target );

    GETTER ( GLint,  level );

    GETTER ( GLint,  internal_format );
};

namespace opengl
{
void bind_texture_units (
    const std::vector<std::shared_ptr<gl_texture>>& textures );
}
}

#endif // ifndef LIBSHIMMER_RENDERER_OPENGL_GL_TEXTURE_H
