#include "gl_buffer.h"

using namespace shimmer;
using namespace std;

gl_buffer::gl_buffer( GLenum     target,
                      GLsizeiptr size,
                      GLenum     usage,
                      GLenum     access )
    : _target ( target ),
      _size ( size ),
      _usage ( usage ),
      _access ( access ),
      _data ( nullptr )
{
    glGenBuffers ( 1, &_handle );

    glBindBuffer ( _target, _handle );
    glBufferData ( _target, _size, 0, usage );
}

gl_buffer::~gl_buffer() {
    glDeleteBuffers ( 1, &_handle );
}

void shimmer::gl_buffer::bind()
{
    glBindBuffer ( _target, _handle );
}

void* shimmer::gl_buffer::map()
{
    glBindBuffer ( _target, _handle );
    _data = glMapBuffer ( _target, _access );

    return _data;
}

void shimmer::gl_buffer::unmap()
{
    glBindBuffer ( _target, _handle );
    glUnmapBuffer ( _target );
}
