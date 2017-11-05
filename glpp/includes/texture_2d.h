#ifndef GLPP_TEXTURE_2D_H
#define GLPP_TEXTURE_2D_H

#include "specs.h"
#include "texture.h"

#include <vector>

namespace glpp
{
class pixels;

class texture_2d : public texture
{
public:
    enum class min_filter : GLenum {
        nearest                = GL_NEAREST,
        linear                 = GL_LINEAR,
        nearest_mipmap_nearest = GL_NEAREST_MIPMAP_NEAREST,
        linear_mipmap_nearest  = GL_LINEAR_MIPMAP_NEAREST,
        nearest_mipmap_linear  = GL_NEAREST_MIPMAP_LINEAR,
        linear_mipmap_linear   = GL_LINEAR_MIPMAP_LINEAR,
    };

    enum class mag_filter : GLenum {
        nearest = GL_NEAREST,
        linear  = GL_LINEAR
    };

    enum class texture_wrap : GLenum {
        clamp_to_edge   = GL_CLAMP_TO_EDGE,
        mirrored_repeat = GL_MIRRORED_REPEAT,
        repeat          = GL_REPEAT
    };

    texture_2d( enum internal_format internal_format );

    texture_2d( texture_2d&& move );

    texture_2d( const texture_2d& copy ) = delete;

    virtual ~texture_2d();

    texture_2d& operator=( texture_2d&& move );

    texture_2d& operator=( const texture_2d& copy ) = delete;


    dims_2u dims() const;


    texture_2d& image ( const pixels& pixels,
                        GLint         level = 0 );

    texture_2d& sub_image ( const coords_2i& offset,
                            const pixels&    pixels,
                            GLint            level = 0 );

    texture_2d& generate_mipmaps();

    texture_2d& bind_texture_unit ( unsigned int unit );


    texture_2d& min_filter ( enum min_filter filter );

    texture_2d& mag_filter ( enum mag_filter filter );

    texture_2d& wrap_s ( enum texture_wrap wrap );

    texture_2d& wrap_t ( enum texture_wrap wrap );

private:
    dims_2u _dims;
};
}

#endif // ifndef GLPP_TEXTURE_2D_H
