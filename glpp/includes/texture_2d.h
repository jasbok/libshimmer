#ifndef GLPP_TEXTURE_2D_H
#define GLPP_TEXTURE_2D_H

#include "pixel.h"
#include "texture.h"

namespace glpp
{
class texture_2d : public texture
{
public:
    enum class target : GLenum {
        gl_texture_2d                  = GL_TEXTURE_2D,
        gl_proxy_texture_2d            = GL_PROXY_TEXTURE_2D,
        gl_texture_1d_array            = GL_TEXTURE_1D_ARRAY,
        gl_proxy_texture_1d_array      = GL_PROXY_TEXTURE_1D_ARRAY,
        gl_texture_rectangle           = GL_TEXTURE_RECTANGLE,
        gl_proxy_texture_rectangle     = GL_PROXY_TEXTURE_RECTANGLE,
        gl_texture_cube_map_positive_x = GL_TEXTURE_CUBE_MAP_POSITIVE_X,
        gl_texture_cube_map_negative_x = GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
        gl_texture_cube_map_positive_y = GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
        gl_texture_cube_map_negative_y = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
        gl_texture_cube_map_positive_z = GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
        gl_texture_cube_map_negative_z = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
        gl_proxy_texture_cube_map      = GL_PROXY_TEXTURE_CUBE_MAP
    };

    texture_2d( enum target          target,
                GLsizei              width,
                GLsizei              height,
                enum internal_format internal_format );

    texture_2d( texture_2d&& move );

    texture_2d( const texture_2d& copy ) = delete;

    virtual ~texture_2d();

    texture_2d& operator=( texture_2d&& move );

    texture_2d& operator=( const texture_2d& copy ) = delete;


    GLsizei              width() const;

    GLsizei              height() const;

    enum internal_format internal_format() const;


    void tex_image ( GLint              level,
                     enum pixel::format format,
                     enum pixel::type   type,
                     const GLvoid*      data );

    void tex_sub_image ( GLint              level,
                         GLint              xoffset,
                         GLint              yoffset,
                         GLsizei            width,
                         GLsizei            height,
                         enum pixel::format format,
                         enum pixel::type   type,
                         const GLvoid*      pixels );

private:
    GLsizei _width, _height;

    enum internal_format _internal_format;
};
}

#endif // ifndef GLPP_TEXTURE_2D_H
