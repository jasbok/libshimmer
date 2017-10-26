#ifndef GLPP_PIXEL_H
#define GLPP_PIXEL_H

#include <GL/glew.h>

namespace glpp
{
namespace pixel
{
enum class format : GLenum {
    gl_red             = GL_RED,
    gl_rg              = GL_RG,
    gl_rgb             = GL_RGB,
    gl_bgr             = GL_BGR,
    gl_rgba            = GL_RGBA,
    gl_bgra            = GL_BGRA,
    gl_red_integer     = GL_RED_INTEGER,
    gl_rg_integer      = GL_RG_INTEGER,
    gl_rgb_integer     = GL_RGB_INTEGER,
    gl_bgr_integer     = GL_BGR_INTEGER,
    gl_rgba_integer    = GL_RGBA_INTEGER,
    gl_bgra_integer    = GL_BGRA_INTEGER,
    gl_stencil_index   = GL_STENCIL_INDEX,
    gl_depth_component = GL_DEPTH_COMPONENT,
    gl_depth_stencil   = GL_DEPTH_STENCIL
};

enum class type : GLenum {
    gl_unsigned_byte               = GL_UNSIGNED_BYTE,
    gl_byte                        = GL_BYTE,
    gl_unsigned_short              = GL_UNSIGNED_SHORT,
    gl_short                       = GL_SHORT,
    gl_unsigned_int                = GL_UNSIGNED_INT,
    gl_int                         = GL_INT,
    gl_float                       = GL_FLOAT,
    gl_unsigned_byte_3_3_2         = GL_UNSIGNED_BYTE_3_3_2,
    gl_unsigned_byte_2_3_3_rev     = GL_UNSIGNED_BYTE_2_3_3_REV,
    gl_unsigned_short_5_6_5        = GL_UNSIGNED_SHORT_5_6_5,
    gl_unsigned_short_5_6_5_rev    = GL_UNSIGNED_SHORT_5_6_5_REV,
    gl_unsigned_short_4_4_4_4      = GL_UNSIGNED_SHORT_4_4_4_4,
    gl_unsigned_short_4_4_4_4_rev  = GL_UNSIGNED_SHORT_4_4_4_4_REV,
    gl_unsigned_short_1_5_5_5_rev  = GL_UNSIGNED_SHORT_1_5_5_5_REV,
    gl_unsigned_int_8_8_8_8        = GL_UNSIGNED_INT_8_8_8_8,
    gl_unsigned_int_8_8_8_8_rev    = GL_UNSIGNED_INT_8_8_8_8_REV,
    gl_unsigned_int_10_10_10_2     = GL_UNSIGNED_INT_10_10_10_2,
    gl_unsigned_int_2_10_10_10_rev = GL_UNSIGNED_INT_2_10_10_10_REV
};

}
}

#endif // ifndef GLPP_PIXEL_H
