#include "texture_2d.h"

#include "pixels.h"

#include <algorithm>

using namespace glpp;
using namespace std;

texture_2d::texture_2d( enum internal_format internal_format )
    : texture ( texture::target::tex_2d, internal_format ),
      _dims()
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

dims_2u texture_2d::dims() const {
    return _dims;
}

texture_2d& texture_2d::image ( const pixels& pixels,
                                GLint         level ) {
    _dims = pixels.dims();

    glTexImage2D ( static_cast<GLenum>(target()),
                   level,
                   static_cast<GLenum>(internal_format()),
                   _dims.width,
                   _dims.height,
                   0,
                   static_cast<GLenum>(pixels.format()),
                   static_cast<GLenum>(pixels.type()),
                   pixels.data() );

    return *this;
}

texture_2d& texture_2d::sub_image ( const coords_2i& offset,
                                    const pixels&    pixels,
                                    GLint            level ) {
    glTexSubImage2D ( static_cast<GLenum>(target()),
                      level,
                      offset.x,
                      offset.y,
                      pixels.dims().width,
                      pixels.dims().height,
                      static_cast<GLenum>(pixels.format()),
                      static_cast<GLenum>(pixels.type()),
                      pixels.data() );

    return *this;
}

texture_2d& texture_2d::generate_mipmap() {
    glGenerateMipmap ( static_cast<GLenum>(target()) );

    return *this;
}

texture_2d& texture_2d::bind_texture_unit ( unsigned int unit ) {
    glActiveTexture ( GL_TEXTURE0 + unit );
    bind();

    return *this;
}

texture_2d& texture_2d::min_filter ( enum min_filter filter ) {
    glTexParameteri ( static_cast<GLenum>(target()),
                      GL_TEXTURE_MIN_FILTER,
                      static_cast<GLenum>(filter) );

    return *this;
}

texture_2d& texture_2d::mag_filter ( enum mag_filter filter ) {
    glTexParameteri ( static_cast<GLenum>(target()),
                      GL_TEXTURE_MAG_FILTER,
                      static_cast<GLenum>(filter) );

    return *this;
}

texture_2d& texture_2d::wrap_s ( enum texture_wrap wrap ) {
    glTexParameteri ( static_cast<GLenum>(target()),
                      GL_TEXTURE_WRAP_S,
                      static_cast<GLenum>(wrap) );

    return *this;
}

texture_2d& texture_2d::wrap_t ( enum texture_wrap wrap ) {
    glTexParameteri ( static_cast<GLenum>(target()),
                      GL_TEXTURE_WRAP_T,
                      static_cast<GLenum>(wrap) );

    return *this;
}
