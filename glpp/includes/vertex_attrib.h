#ifndef GLPP_VERTEX_ATTRIB_H
#define GLPP_VERTEX_ATTRIB_H

#include <GL/glew.h>

namespace glpp
{
class vertex_attrib
{
public:
    enum class type : GLenum {
        gl_byte           = GL_BYTE,
        gl_unsigned_byte  = GL_UNSIGNED_BYTE,
        gl_short          = GL_SHORT,
        gl_unsigned_short = GL_UNSIGNED_SHORT,
        gl_fixed          = GL_FIXED,
        gl_float          = GL_FLOAT
    };

    vertex_attrib( enum type type,
                   GLuint    size );

    vertex_attrib( enum type type,
                   GLuint    size,
                   size_t    type_size );

    vertex_attrib( vertex_attrib&& move ) = default;

    vertex_attrib( const vertex_attrib& copy ) = default;

    virtual ~vertex_attrib() = default;

    vertex_attrib& operator=( vertex_attrib&& move ) = default;

    vertex_attrib& operator=( const vertex_attrib& copy ) = default;


    vertex_attrib& location ( GLint location );

    vertex_attrib& normalised ( bool normalised );

    vertex_attrib& stride ( GLuint stride );

    vertex_attrib& offset ( GLuint offset );


    vertex_attrib& define_pointer();

    vertex_attrib& enable_array();

    vertex_attrib& disable_array();

private:
    enum type _type;

    GLuint _size;

    size_t _type_size;

    GLint _location;

    bool _normalised;

    GLuint _stride;

    GLuint _offset;
};
}

#endif // ifndef GLPP_VERTEX_ATTRIB_H
