#include "gl_texture.h"

#include "spdlog/spdlog.h"

using namespace shimmer;
using namespace std;

static std::shared_ptr<spdlog::logger> LOGGER
    = spdlog::stdout_color_mt ( "gl_texture" );

gl_texture::gl_texture( GLenum        target,
                        GLint         level,
                        GLint         internal_format,
                        GLsizei       width,
                        GLsizei       height,
                        GLenum        format,
                        GLenum        type,
                        const GLvoid* data  )
    : texture ( width, height ),
      _handle ( 0 ),
      _target ( target ),
      _level ( level ),
      _internal_format ( internal_format )
{
    glGenTextures ( 1, &_handle );

    if ( _handle ) {
        glBindTexture ( _target, _handle );

        glTexImage2D ( _target,
                       _level,
                       _internal_format,
                       width,
                       height,
                       0,
                       format,
                       type,
                       data );
    }
    else {
        LOGGER->error ( "Unable to create new texture handle." );
    }
}

gl_texture::~gl_texture()
{
    glDeleteTextures ( 1, &_handle );
}

void gl_texture::bind() const
{
    glBindTexture ( _target, _handle );
}

void gl_texture::upload ( GLenum        format,
                          GLenum        type,
                          const GLvoid* data )
{
    upload ( format, type, data, 0, 0, width(), height() );
}

void gl_texture::upload ( GLenum        format,
                          GLenum        type,
                          const GLvoid* data,
                          GLint         x_offset,
                          GLint         y_offset,
                          GLsizei       width,
                          GLsizei       height )
{
    glBindTexture ( _target, _handle );

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

void gl_texture::download ( GLenum  format,
                            GLenum  type,
                            GLvoid* data ) const
{
    glBindTexture ( _target, _handle );

    glGetTexImage ( _target,
                    _level,
                    format,
                    type,
                    data );
}

void opengl::bind_texture_units (
    const vector<shared_ptr<gl_texture>>& textures ) {
    auto texture_unit = GL_TEXTURE0;

    for ( const auto& texture : textures ) {
        glActiveTexture ( texture_unit++ );
        texture->bind();
    }
}
