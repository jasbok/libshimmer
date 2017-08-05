#include "gl_pixel.h"

#include "gl_enum.h"

#include "spdlog/spdlog.h"

#include <unordered_map>

using namespace shimmer;

static std::shared_ptr<spdlog::logger> LOGGER
    = spdlog::stdout_color_mt ( "gl_pixel" );

const std::unordered_map<GLenum, unsigned int> pixel_format_component = {
    { GL_RED,             1 },
    { GL_RG,              2 },
    { GL_RGB,             3 },
    { GL_BGR,             3 },
    { GL_RGBA,            4 },
    { GL_BGRA,            4 },
    { GL_RED_INTEGER,     1 },
    { GL_RG_INTEGER,      2 },
    { GL_RGB_INTEGER,     3 },
    { GL_BGR_INTEGER,     3 },
    { GL_RGBA_INTEGER,    4 },
    { GL_BGRA_INTEGER,    4 },
    { GL_STENCIL_INDEX,   1 },
    { GL_DEPTH_COMPONENT, 1 },
    { GL_DEPTH_STENCIL,   2 }
};

const std::unordered_map<GLenum, unsigned int> pixel_type_bytes = {
    { GL_UNSIGNED_BYTE,               1 },
    { GL_BYTE,                        1 },
    { GL_UNSIGNED_SHORT,              2 },
    { GL_SHORT,                       2 },
    { GL_UNSIGNED_INT,                4 },
    { GL_INT,                         4 },
    { GL_FLOAT,                       4 },
    { GL_UNSIGNED_BYTE_3_3_2,         1 },
    { GL_UNSIGNED_BYTE_2_3_3_REV,     1 },
    { GL_UNSIGNED_SHORT_5_6_5,        2 },
    { GL_UNSIGNED_SHORT_5_6_5_REV,    2 },
    { GL_UNSIGNED_SHORT_4_4_4_4,      2 },
    { GL_UNSIGNED_SHORT_4_4_4_4_REV,  2 },
    { GL_UNSIGNED_SHORT_5_5_5_1,      2 },
    { GL_UNSIGNED_SHORT_1_5_5_5_REV,  2 },
    { GL_UNSIGNED_INT_8_8_8_8,        4 },
    { GL_UNSIGNED_INT_8_8_8_8_REV,    4 },
    { GL_UNSIGNED_INT_10_10_10_2,     4 },
    { GL_UNSIGNED_INT_2_10_10_10_REV, 4 }
};

unsigned int opengl::bytes_per_pixel ( GLenum format, GLenum type )
{
    auto format_components = pixel_format_component.find ( format );

    if ( format_components == pixel_format_component.end() ) {
        LOGGER->error ( "Unknown pixel format: {}",
                        enum_to_string ( format ) );

        return 0;
    }

    auto type_bytes = pixel_type_bytes.find ( type );

    if ( type_bytes == pixel_type_bytes.end() ) {
        LOGGER->error ( "Unknown pixel type: {}", enum_to_string ( type ) );

        return 0;
    }

    return format_components->second * type_bytes->second;
}
