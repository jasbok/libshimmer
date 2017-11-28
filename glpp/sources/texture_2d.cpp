#include "texture_2d.h"

#include "pixels.h"

#include <algorithm>
#include <iostream>

using namespace glpp;
using namespace std;

texture_2d::texture_2d( enum internal_format internal_format )
    : texture ( texture::target::tex_2d, internal_format ),
      _dims()
{}

texture_2d::texture_2d( GLuint               handle,
                        dims_2u              dims,
                        enum internal_format internal_format  )
    : texture ( texture::target::tex_2d, internal_format, handle ),
      _dims ( dims )
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

std::shared_ptr<texture_2d> texture_2d::make_shared (
    enum texture::internal_format internal_format ) {
    return std::make_shared<texture_2d>( internal_format );
}

std::shared_ptr<texture_2d> texture_2d::make_shared (
    GLuint                        handle,
    dims_2u                       dims,
    enum texture::internal_format internal_format ) {
    return std::make_shared<texture_2d>( handle, dims, internal_format );
}

std::shared_ptr<texture_2d> texture_2d::make_shared (
    dims_2u                       dims,
    enum texture::internal_format internal_format,
    enum pixels::format           format,
    enum pixels::type             type ) {
    auto texture = std::make_shared<texture_2d>( internal_format );

    texture->bind();
    texture->image ( { nullptr,
                       dims,
                       format,
                       type } );

    return texture;
}

dims_2u texture_2d::dims() const {
    return _dims;
}

texture_2d& texture_2d::image ( const pixels& pixels,
                                GLint         level ) {
    if ( owning() ) {
        _dims = pixels.dims();

        if ( _dims.area() == 0 ) throw texture_2d_area_zero_exception();

        glTexImage2D ( static_cast<GLenum>( target() ),
                       level,
                       static_cast<GLenum>( internal_format() ),
                       _dims.width,
                       _dims.height,
                       0,
                       static_cast<GLenum>( pixels.format() ),
                       static_cast<GLenum>( pixels.type() ),
                       pixels.data() );
    }
    else {
        std::cerr << "Tried to draw to a non-owning texture.\n";
    }

    return *this;
}

texture_2d& texture_2d::sub_image ( const coords_2i& offset,
                                    const pixels&    pixels,
                                    GLint            level ) {
    if ( owning() ) {
        glTexSubImage2D ( static_cast<GLenum>( target() ),
                          level,
                          offset.x,
                          offset.y,
                          pixels.dims().width,
                          pixels.dims().height,
                          static_cast<GLenum>( pixels.format() ),
                          static_cast<GLenum>( pixels.type() ),
                          pixels.data() );
    }
    else {
        std::cerr << "Tried to draw to a non-owning texture.\n";
    }

    return *this;
}

texture_2d& texture_2d::generate_mipmaps() {
    glGenerateMipmap ( static_cast<GLenum>( target() ) );

    return *this;
}

texture_2d& texture_2d::bind_texture_unit ( unsigned int unit ) {
    glActiveTexture ( GL_TEXTURE0 + unit );
    bind();

    return *this;
}

texture_2d& texture_2d::filters ( texture_2d::filter filter )
{
    min_filter ( static_cast<enum min_filter>( filter ) );
    mag_filter ( static_cast<enum mag_filter>( filter ) );

    return *this;
}

texture_2d& texture_2d::min_filter ( enum min_filter filter ) {
    glTexParameteri ( static_cast<GLenum>( target() ),
                      GL_TEXTURE_MIN_FILTER,
                      static_cast<GLenum>( filter ) );

    return *this;
}

texture_2d& texture_2d::mag_filter ( enum mag_filter filter ) {
    glTexParameteri ( static_cast<GLenum>( target() ),
                      GL_TEXTURE_MAG_FILTER,
                      static_cast<GLenum>( filter ) );

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
                      static_cast<GLenum>( filter ) );
}

void texture_2d::set_mag_filter ( enum texture_2d::mag_filter filter )
{
    glTexParameteri ( GL_TEXTURE_2D,
                      GL_TEXTURE_MAG_FILTER,
                      static_cast<GLenum>( filter ) );
}

texture_2d& texture_2d::wrap ( texture_2d::texture_wrap wrap )
{
    wrap_s ( wrap );
    wrap_t ( wrap );

    return *this;
}

texture_2d& texture_2d::wrap_s ( enum texture_wrap wrap ) {
    glTexParameteri ( static_cast<GLenum>( target() ),
                      GL_TEXTURE_WRAP_S,
                      static_cast<GLenum>( wrap ) );

    return *this;
}

texture_2d& texture_2d::wrap_t ( enum texture_wrap wrap ) {
    glTexParameteri ( static_cast<GLenum>( target() ),
                      GL_TEXTURE_WRAP_T,
                      static_cast<GLenum>( wrap ) );

    return *this;
}
