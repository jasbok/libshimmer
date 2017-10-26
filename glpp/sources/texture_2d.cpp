#include "texture_2d.h"

#include <algorithm>

using namespace glpp;

texture_2d::texture_2d( enum target          target,
                        GLsizei              width,
                        GLsizei              height,
                        enum internal_format internal_format )
    : texture ( static_cast<enum texture::target>(target) ),
      _width ( width ),
      _height ( height ),
      _internal_format ( internal_format )
{}

texture_2d::texture_2d( texture_2d&& move )
    : texture ( std::move ( move ) ),
      _width ( move._width ),
      _height ( move._height ),
      _internal_format ( move._internal_format )
{}

texture_2d::~texture_2d() {}

texture_2d& texture_2d::operator=( texture_2d&& move ) {
    texture::operator=( std::move ( move ) );
    _width           = move._width;
    _height          = move._height;
    _internal_format = move._internal_format;

    return *this;
}

GLsizei texture_2d::width() const {
    return _width;
}

GLsizei texture_2d::height() const {
    return _height;
}

enum texture_2d::internal_format texture_2d::internal_format() const {
    return _internal_format;
}

void texture_2d::tex_image ( GLint              level,
                             enum pixel::format format,
                             enum pixel::type   type,
                             const GLvoid*      data ) {
    glTexImage2D ( static_cast<GLenum>(target()),
                   level,
                   static_cast<GLenum>(_internal_format),
                   _width,
                   _height,
                   0,
                   static_cast<GLenum>(format),
                   static_cast<GLenum>(type),
                   data );
}

void texture_2d::tex_sub_image ( GLint              level,
                                 GLint              xoffset,
                                 GLint              yoffset,
                                 GLsizei            width,
                                 GLsizei            height,
                                 enum pixel::format format,
                                 enum pixel::type   type,
                                 const GLvoid*      pixels ) {
    glTexSubImage2D ( static_cast<GLenum>(target()),
                      level,
                      xoffset,
                      yoffset,
                      width,
                      height,
                      static_cast<GLenum>(format),
                      static_cast<GLenum>(type),
                      pixels );
}
