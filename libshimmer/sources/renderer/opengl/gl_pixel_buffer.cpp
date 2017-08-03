#include "gl_pixel_buffer.h"

using namespace shimmer;

gl_pixel_buffer::gl_pixel_buffer( GLenum     target,
                                  GLsizeiptr size,
                                  GLenum     usage,
                                  GLenum     access,
                                  GLenum     format,
                                  GLenum     type )
    : gl_buffer ( target, size, usage, access ),
      _format ( format ),
      _type ( type )
{}
