#ifndef GLPP_TEXTURE_H
#define GLPP_TEXTURE_H

#include <GL/glew.h>

namespace glpp
{
class texture
{
public:
    enum class target : GLenum {
        tex_1d                   = GL_TEXTURE_1D,
        tex_2d                   = GL_TEXTURE_2D,
        tex_3d                   = GL_TEXTURE_3D,
        tex_1d_array             = GL_TEXTURE_1D_ARRAY,
        tex_2d_array             = GL_TEXTURE_2D_ARRAY,
        tex_rectangle            = GL_TEXTURE_RECTANGLE,
        tex_cube_map             = GL_TEXTURE_CUBE_MAP,
        tex_cube_map_array       = GL_TEXTURE_CUBE_MAP_ARRAY,
        tex_buffer               = GL_TEXTURE_BUFFER,
        tex_2d_multisample       = GL_TEXTURE_2D_MULTISAMPLE,
        tex_2d_multisample_array = GL_TEXTURE_2D_MULTISAMPLE_ARRAY
    };

    enum class internal_format : GLint {
        depth_component = GL_DEPTH_COMPONENT,
        depth_stencil   = GL_DEPTH_STENCIL,
        red             = GL_RED,
        rg              = GL_RG,
        rgb             = GL_RGB,
        rgba            = GL_RGBA
    };

    texture( enum target target );

    texture( texture&& move );

    texture( const texture& copy ) = delete;

    virtual ~texture();

    texture& operator=( texture&& move );

    texture& operator=( const texture& copy ) = delete;


    GLuint      handle() const;

    enum target target() const;

    texture&    bind();

    void        unbind();

private:
    GLuint _handle;

    enum target _target;
};
}

#endif // ifndef GLPP_TEXTURE_H
