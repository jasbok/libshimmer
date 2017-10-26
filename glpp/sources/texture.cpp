#include "texture.h"

using namespace glpp;

texture::texture( enum target target )
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

void texture::bind() const {
    glBindTexture ( static_cast<GLenum>(_target), _handle );
}

void texture::unbind() const {
    glBindTexture ( static_cast<GLenum>(_target), 0 );
}
