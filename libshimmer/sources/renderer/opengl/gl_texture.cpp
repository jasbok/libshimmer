#include "gl_texture.h"

#include "spdlog/spdlog.h"

using namespace shimmer;

static std::shared_ptr<spdlog::logger> LOGGER
    = spdlog::stdout_color_mt ( "gl_texture" );

gl_texture::gl_texture (
    unsigned int width,
    unsigned int height,
    GLenum target,
    GLint level,
    GLint internal_format )
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
                       internal_format,
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

void gl_texture::bind()
{
    glBindTexture ( _target, _handle );
}

void gl_texture::upload ( GLenum format,
                          GLenum type,
                          const GLvoid* data )
{
    upload ( format, type, data, 0, 0, width(), height() );
}

void gl_texture::upload ( GLenum format,
                          GLenum type,
                          const GLvoid* data,
                          GLint x_offset,
                          GLint y_offset,
                          GLsizei width,
                          GLsizei height )
{
    bind();

    glTexSubImage2D ( _target,
                      _level,
                      x_offset,
                      y_offset,
                      width,
                      height,
                      format,
                      type,
                      data );
}

void gl_texture::download ( GLenum format,
                            GLenum type,
                            GLvoid* data )
{
    bind();

    glGetTexImage ( _target,
                    _level,
                    format,
                    type,
                    data );
}





