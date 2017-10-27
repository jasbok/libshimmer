#ifndef GLPP_TEXTURE_H
#define GLPP_TEXTURE_H

#include <GL/glew.h>

namespace glpp
{
class texture
{
public:
    enum class target : GLenum {
        gl_texture_1d                   = GL_TEXTURE_1D,
        gl_texture_2d                   = GL_TEXTURE_2D,
        gl_texture_3d                   = GL_TEXTURE_3D,
        gl_texture_1d_array             = GL_TEXTURE_1D_ARRAY,
        gl_texture_2d_array             = GL_TEXTURE_2D_ARRAY,
        gl_texture_rectangle            = GL_TEXTURE_RECTANGLE,
        gl_texture_cube_map             = GL_TEXTURE_CUBE_MAP,
        gl_texture_cube_map_array       = GL_TEXTURE_CUBE_MAP_ARRAY,
        gl_texture_buffer               = GL_TEXTURE_BUFFER,
        gl_texture_2d_multisample       = GL_TEXTURE_2D_MULTISAMPLE,
        gl_texture_2d_multisample_array = GL_TEXTURE_2D_MULTISAMPLE_ARRAY
    };

    texture( enum target target );

    texture( texture&& move );

    texture( const texture& copy ) = delete;

    virtual ~texture();

    texture&             operator=( texture&& move );

    texture&             operator=( const texture& copy ) = delete;

    GLuint               handle() const;

    enum target          target() const;

    void                 bind() const;

    void                 unbind() const;

private:
    GLuint _handle;

    enum target _target;
};
}

#endif // ifndef GLPP_TEXTURE_H
