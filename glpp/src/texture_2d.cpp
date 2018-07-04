#include "texture_2d.h"

#include "pixels.h"

#include <algorithm>
#include <iostream>

using namespace std;

namespace glpp
{
texture_2d::texture_2d()
    : texture ( texture::target::tex_2d )
{}

texture_2d::texture_2d( texture_2d&& move )
    : texture ( std::move ( move ) ),
      _dims ( std::move ( move._dims ) )
{}

texture_2d::~texture_2d() {}

texture_2d& texture_2d::operator=( texture_2d&& move ) {
    texture::operator=( std::move ( move ) );
    _dims = std::move ( move._dims );

    return *this;
}

common::dims_2u texture_2d::dims() const {
    return _dims;
}

texture_2d& texture_2d::image ( const common::img::image& img )
{
    return image ( _internal_format_from ( img ), img );
}

texture_2d& texture_2d::image ( internal_format        internal_format,
                                const common::dims_2u& dims ) {
    _dims = dims;

    glTexImage2D ( GL_TEXTURE_2D,
                   0,
                   static_cast<GLint>( internal_format ),
                   static_cast<GLsizei>( _dims.width ),
                   static_cast<GLsizei>( _dims.height ),
                   0,
                   static_cast<GLenum>( internal_format ),
                   GL_UNSIGNED_BYTE,
                   nullptr );

    return *this;
}

texture_2d& texture_2d::image ( internal_format           internal_format,
                                const common::img::image& image ) {
    _dims = image.dims();

    glTexImage2D ( GL_TEXTURE_2D,
                   0,
                   static_cast<GLint>( internal_format ),
                   static_cast<GLsizei>( _dims.width ),
                   static_cast<GLsizei>( _dims.height ),
                   0,
                   _gl_format_from ( image ),
                   GL_UNSIGNED_BYTE,
                   image.data() );

    return *this;
}

texture_2d& texture_2d::sub_image ( const common::img::image& image ) {
    glTexSubImage2D ( GL_TEXTURE_2D,
                      0,
                      0,
                      0,
                      static_cast<GLsizei>( image.dims().width ),
                      static_cast<GLsizei>( image.dims().height ),
                      _gl_format_from ( image ),
                      GL_UNSIGNED_BYTE,
                      image.data() );

    return *this;
}

texture_2d& texture_2d::sub_image ( uint8_t*               data,
                                    const common::dims_2u& dims,
                                    unsigned int           channels )
{
    glTexSubImage2D ( GL_TEXTURE_2D,
                      0,
                      0,
                      0,
                      static_cast<GLsizei>( dims.width ),
                      static_cast<GLsizei>( dims.height ),
                      _gl_format_from_channels ( channels ),
                      GL_UNSIGNED_BYTE,
                      data );

    return *this;
}

texture_2d& texture_2d::sub_image ( const coords_2i&          offset,
                                    const common::img::image& image ) {
    glTexSubImage2D ( GL_TEXTURE_2D,
                      0,
                      offset.x,
                      offset.y,
                      static_cast<GLsizei>( image.dims().width ),
                      static_cast<GLsizei>( image.dims().height ),
                      _gl_format_from ( image ),
                      GL_UNSIGNED_BYTE,
                      image.data() );

    return *this;
}

texture_2d& texture_2d::generate_mipmaps() {
    glGenerateMipmap ( GL_TEXTURE_2D );

    return *this;
}

texture_2d& texture_2d::filters ( texture_2d::filter filter )
{
    min_filter ( static_cast<enum min_filter>( filter ) );
    mag_filter ( static_cast<enum mag_filter>( filter ) );

    return *this;
}

texture_2d& texture_2d::min_filter ( enum min_filter filter ) {
    glTexParameteri ( GL_TEXTURE_2D,
                      GL_TEXTURE_MIN_FILTER,
                      static_cast<GLint>( filter ) );

    return *this;
}

texture_2d& texture_2d::mag_filter ( enum mag_filter filter ) {
    glTexParameteri ( GL_TEXTURE_2D,
                      GL_TEXTURE_MAG_FILTER,
                      static_cast<GLint>( filter ) );

    return *this;
}

void texture_2d::set_filters ( enum texture_2d::filter filter )
{
    set_min_filter ( static_cast<enum min_filter>( filter ) );
    set_mag_filter ( static_cast<enum mag_filter>( filter ) );
}

void texture_2d::set_min_filter ( enum texture_2d::min_filter filter )
{
    glTexParameteri ( GL_TEXTURE_2D,
                      GL_TEXTURE_MIN_FILTER,
                      static_cast<GLint>( filter ) );
}

void texture_2d::set_mag_filter ( enum texture_2d::mag_filter filter )
{
    glTexParameteri ( GL_TEXTURE_2D,
                      GL_TEXTURE_MAG_FILTER,
                      static_cast<GLint>( filter ) );
}

texture_2d& texture_2d::wrap ( texture_2d::texture_wrap wrap )
{
    wrap_s ( wrap );
    wrap_t ( wrap );

    return *this;
}

texture_2d& texture_2d::wrap_s ( enum texture_wrap wrap ) {
    glTexParameteri ( GL_TEXTURE_2D,
                      GL_TEXTURE_WRAP_S,
                      static_cast<GLint>( wrap ) );

    return *this;
}

texture_2d& texture_2d::wrap_t ( enum texture_wrap wrap ) {
    glTexParameteri ( GL_TEXTURE_2D,
                      GL_TEXTURE_WRAP_T,
                      static_cast<GLint>( wrap ) );

    return *this;
}

texture::internal_format texture_2d::_internal_format_from (
    const common::img::image& image )
{
    switch ( image.channels() ) {
    case 1: return internal_format::red;

    case 2: return internal_format::rg;

    case 3: return internal_format::rgb;

    case 4: return internal_format::rgba;

    default: return internal_format::rgb;
    }
}

GLenum texture_2d::_gl_format_from ( const common::img::image& image ) {
    switch ( image.channels() ) {
    case 1: return GL_RED;

    case 2: return GL_RG;

    case 3: return GL_RGB;

    case 4: return GL_RGBA;

    default: return GL_RGB;
    }
}

GLenum texture_2d::_gl_format_from_channels ( unsigned int channels ) {
    switch ( channels ) {
    case 1: return GL_RED;

    case 2: return GL_RG;

    case 3: return GL_RGB;

    case 4: return GL_RGBA;

    default: return GL_RGB;
    }
}
}
