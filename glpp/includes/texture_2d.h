#ifndef GLPP_TEXTURE_2D_H
#define GLPP_TEXTURE_2D_H

#include "pixels.h"
#include "specs.h"
#include "texture.h"

#include <memory>
#include <vector>

namespace glpp
{
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

    enum class filter : GLenum {
        nearest = GL_NEAREST,
        linear  = GL_LINEAR
    };

    enum class texture_wrap : GLenum {
        clamp_to_edge   = GL_CLAMP_TO_EDGE,
        mirrored_repeat = GL_MIRRORED_REPEAT,
        repeat          = GL_REPEAT
    };

    explicit texture_2d( enum internal_format internal_format );

    explicit texture_2d( GLuint               handle,
                         dims_2u              dims,
                         enum internal_format internal_format );

    texture_2d( texture_2d&& move );

    texture_2d( const texture_2d& copy ) = delete;

    virtual ~texture_2d();

    texture_2d& operator=( texture_2d&& move );

    texture_2d& operator=( const texture_2d& copy ) = delete;


    static std::shared_ptr<texture_2d> make_shared (
        enum internal_format internal_format );

    static std::shared_ptr<texture_2d> make_shared (
        GLuint               handle,
        dims_2u              dims,
        enum internal_format internal_format  );

    static std::shared_ptr<texture_2d> make_shared (
        dims_2u              dims,
        enum internal_format internal_format = internal_format::rgb,
        enum pixels::format  format          = pixels::format::rgb,
        enum pixels::type    type            = pixels::type::gl_unsigned_byte );

    dims_2u     dims() const;

    texture_2d& image ( const pixels& pixels,
                        GLint         level = 0 );

    texture_2d& sub_image ( const coords_2i& offset,
                            const pixels&    pixels,
                            GLint            level = 0 );

    texture_2d& generate_mipmaps();

    texture_2d& bind_texture_unit ( unsigned int unit );


    texture_2d& filters ( enum filter filter );

    texture_2d& min_filter ( enum min_filter filter );

    texture_2d& mag_filter ( enum mag_filter filter );

    static void set_filters ( enum filter filter );

    static void set_min_filter ( enum min_filter filter );

    static void set_mag_filter ( enum mag_filter filter );


    texture_2d& wrap ( enum texture_wrap wrap );

    texture_2d& wrap_s ( enum texture_wrap wrap );

    texture_2d& wrap_t ( enum texture_wrap wrap );

private:
    dims_2u _dims;
};

struct texture_2d_area_zero_exception : public std::exception {
    const char* what() const throw( ) {
        return "The area of the specified texture image is zero.";
    }
};
}

#endif // ifndef GLPP_TEXTURE_2D_H
