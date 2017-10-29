#ifndef GLPP_ENUMS_H
#define GLPP_ENUMS_H

#include <GL/glew.h>

namespace glpp
{
enum class gl_type : GLenum {
    gl_byte           = GL_BYTE,
    gl_unsigned_byte  = GL_UNSIGNED_BYTE,
    gl_short          = GL_SHORT,
    gl_unsigned_short = GL_UNSIGNED_SHORT,
    gl_fixed          = GL_FIXED,
    gl_float          = GL_FLOAT
};

size_t size_of ( enum gl_type type );

size_t size_of ( GLenum type );

enum class usage : GLenum {
    stream_draw  = GL_STREAM_DRAW,
    stream_read  = GL_STREAM_READ,
    stream_copy  = GL_STREAM_COPY,
    static_draw  = GL_STATIC_DRAW,
    static_read  = GL_STATIC_READ,
    static_copy  = GL_STATIC_COPY,
    dynamic_draw = GL_DYNAMIC_DRAW,
    dynamic_read = GL_DYNAMIC_READ,
    dynamic_copy = GL_DYNAMIC_COPY
};

enum class access : GLenum {
    read_only  = GL_READ_ONLY,
    write_only = GL_WRITE_ONLY,
    read_write = GL_READ_WRITE
};
}

#endif // ifndef GLPP_ENUMS_H
