#include "gl_texture.h"
#include "spdlog.h"

using namespace shimmer;

static std::shared_ptr<spdlog::logger> LOGGER
    = spdlog::stdout_color_mt ( "gl_texture" );

gl_texture::gl_texture (
    unsigned int width,
    unsigned int height,
    GLenum target,
    GLint level,
    GLint internalFormat )
    : texture ( width,  height ),
      _handle ( 0 ),
      _target ( target ),
      _level ( level )
{
    glGenTextures ( 1, &_handle );

    if ( _handle ) {
        glBindTexture ( target, _handle );
        glTexImage2D ( target,
                       level,
                       internalFormat,
                       width,
                       height,
                       0, 0, 0, 0 );
    } else {
        LOGGER->error ( "Unable to allocate new texture." );
    }
}

gl_texture::~gl_texture()
{
    glDeleteTextures ( 1, &_handle );
}
