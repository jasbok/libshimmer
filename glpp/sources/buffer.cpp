#include "buffer.h"

using namespace glpp;
using namespace std;

buffer::buffer( enum target target )
    : _handle ( 0 ),
      _target ( target ),
      _size ( 0 )
{
    glGenBuffers ( 1, &_handle );
}

buffer::buffer( buffer&& move )
    : _handle ( move._handle ),
      _target ( move._target ),
      _size ( move._size )
{
    move._handle = 0;
}

buffer::~buffer() {
    glDeleteBuffers ( 1, &_handle );
}

buffer& buffer::operator=( buffer&& move ) {
    _handle = move._handle;
    _target = move._target;
    _size   = move._size;

    move._handle = 0;

    return *this;
}

GLuint buffer::handle() const {
    return _handle;
}

enum buffer::target buffer::target() const {
    return _target;
}

size_t buffer::size() const {
    return _size;
}

void buffer::bind() const {
    glBindBuffer ( static_cast<GLenum>(_target), _handle );
}

void buffer::unbind() const {
    glBindBuffer ( static_cast<GLenum>(_target), 0 );
}

void buffer::data ( const buffer_data& data,
                    enum usage              usage ) {
    glBufferData ( static_cast<GLenum>(_target),
                   data.size,
                   data.ptr,
                   static_cast<GLenum>(usage) );

    _size = data.size;
}
