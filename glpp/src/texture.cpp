#include "texture.h"

#include <iostream>

namespace glpp
{
GLint texture::_max_texture_image_units = -1;

texture::texture( enum target target
                  )
    : _handle ( 0 ),
      _target ( target )
{
    glGenTextures ( 1, &_handle );
}

texture::texture( texture&& move )
    : _handle ( move._handle ),
      _target ( move._target )
{
    move._handle = 0;
}

texture::~texture() {
    glDeleteTextures ( 1, &_handle );
}

texture& texture::operator=( texture&& move ) {
    glDeleteTextures ( 1, &_handle );

    _handle = move._handle;
    _target = move._target;

    move._handle = 0;

    return *this;
}

GLuint texture::handle() const {
    return _handle;
}

enum texture::target texture::target() const {
    return _target;
}

texture& texture::bind() {
    glBindTexture ( static_cast<GLenum>( _target ), _handle );

    return *this;
}

void texture::unbind() {
    glBindTexture ( static_cast<GLenum>( _target ), 0 );
}

void texture::active_texture ( unsigned int unit ) {
    glActiveTexture ( GL_TEXTURE0 + unit );
}

GLint texture::max_texture_image_units() {
    if ( _max_texture_image_units == -1 ) {
        glGetIntegerv ( GL_MAX_TEXTURE_IMAGE_UNITS,
                        &_max_texture_image_units );
    }

    return _max_texture_image_units;
}
}
