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
}

#endif // ifndef GLPP_ENUMS_H
