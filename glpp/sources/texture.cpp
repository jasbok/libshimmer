#include "texture.h"

#include <iostream>

using namespace glpp;

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
