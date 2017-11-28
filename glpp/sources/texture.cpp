#include "texture.h"

#include <iostream>

using namespace glpp;

texture::texture( enum target          target,
                  enum internal_format internal_format
                  )
    : _handle ( 0 ),
      _target ( target ),
      _internal_format ( internal_format ),
      _owning ( true )
{
    glGenTextures ( 1, &_handle );
}

texture::texture( enum target          target,
                  enum internal_format internal_format,
                  GLuint               handle )
    : _handle ( handle ),
      _target ( target ),
      _internal_format ( internal_format ),
      _owning ( false )
{}

texture::texture( texture&& move )
    : _handle ( move._handle ),
      _target ( move._target ),
      _internal_format ( move._internal_format ),
      _owning ( move._owning )
{
    move._handle = 0;
}

texture::~texture() {
    if ( _owning ) {
        glDeleteTextures ( 1, &_handle );
    }
}

texture& texture::operator=( texture&& move ) {
    if ( _owning ) {
        glDeleteTextures ( 1, &_handle );
    }

    _handle          = move._handle;
    _owning          = move._owning;
    _target          = move._target;
    _internal_format = move._internal_format;

    move._handle = 0;

    return *this;
}

GLuint texture::handle() const {
    return _handle;
}

enum texture::target texture::target() const {
    return _target;
}

enum texture::internal_format texture::internal_format() const {
    return _internal_format;
}

texture& texture::bind() {
    glBindTexture ( static_cast<GLenum>( _target ), _handle );

    return *this;
}

void texture::unbind() {
    glBindTexture ( static_cast<GLenum>( _target ), 0 );
}

bool texture::owning()
{
    return _owning;
}
