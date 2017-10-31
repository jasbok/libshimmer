#include "texture.h"

using namespace glpp;

texture::texture( enum target          target,
                  enum internal_format internal_format
                  )
    : _handle ( 0 ),
      _target ( target ),
      _internal_format ( internal_format )
{
    glGenTextures ( 1, &_handle );
}

texture::texture( texture&& move )
    : _handle ( move._handle ),
      _target ( move._target ),
      _internal_format ( move._internal_format )
{
    move._handle = 0;
}

texture::~texture() {
    glDeleteTextures ( 1, &_handle );
}

texture& texture::operator=( texture&& move ) {
    glDeleteTextures ( 1, &_handle );

    _handle          = move._handle;
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
    glBindTexture ( static_cast<GLenum>(_target), _handle );

    return *this;
}

void texture::unbind() {
    glBindTexture ( static_cast<GLenum>(_target), 0 );
}
