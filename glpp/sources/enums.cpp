#include "enums.h"

#include <stddef.h>

using namespace glpp;

size_t glpp::size_of ( enum gl_type type ) {
    switch ( type ) {
    case gl_type::gl_byte:

        return sizeof(GLbyte);

    case gl_type::gl_fixed:

        return sizeof(GLfixed);

    case gl_type::gl_float:

        return sizeof(GLfloat);

    case gl_type::gl_short:

        return sizeof(GLshort);

    case gl_type::gl_unsigned_byte:

        return sizeof(GLubyte);

    case gl_type::gl_unsigned_short:

        return sizeof(GLushort);
    }

    return 0;
}
