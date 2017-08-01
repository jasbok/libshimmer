#include "gl_pixel_buffer.h"

using namespace shimmer;

gl_pixel_buffer::gl_pixel_buffer( GLenum     target,
                                  GLsizeiptr size,
                                  GLenum     access,
                                  GLenum     usage,
                                  GLenum     format,
                                  GLenum     type )
    : gl_buffer ( target, size, access, usage ),
      _format ( format ),
      _type ( type )
{}
