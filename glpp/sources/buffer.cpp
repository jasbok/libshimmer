#include "buffer.h"

using namespace glpp;
using namespace std;

buffer::buffer( enum target target,
                enum usage  usage )
    : _handle ( 0 ),
      _target ( target ),
      _usage ( usage ),
      _size ( 0 )
{
    glGenBuffers ( 1, &_handle );
}

buffer::buffer( buffer&& move )
    : _handle ( move._handle ),
      _target ( move._target ),
      _usage ( move._usage ),
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
    _usage = move._usage;
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

enum buffer::usage buffer::usage() const {
    return _usage;
}

size_t buffer::size() const {
    return _size;
}

buffer& buffer::bind() {
    glBindBuffer ( static_cast<GLenum>(_target), _handle );

    return *this;
}

void buffer::unbind() {
    glBindBuffer ( static_cast<GLenum>(_target), 0 );
}

buffer& buffer::data ( const void* data,
                       size_t      size ) {
    _size = size;

    glBufferData ( static_cast<GLenum>(_target),
                   _size,
                   data,
                   static_cast<GLenum>(_usage) );

    return *this;
}

buffer& buffer::data ( const void* data,
                       size_t      size,
                       enum usage  usage ) {
    _size  = size;
    _usage = usage;

    glBufferData ( static_cast<GLenum>(_target),
                   _size,
                   data,
                   static_cast<GLenum>(_usage) );

    return *this;
}
