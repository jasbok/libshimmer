#ifndef GLPP_VERTEX_ATTRIB_H
#define GLPP_VERTEX_ATTRIB_H

#include "enums.h"

#include <GL/glew.h>

#include <string>

namespace glpp
{
class vertex_attrib
{
public:
    vertex_attrib( enum gl_type type,
                   GLuint    size );

    vertex_attrib( enum gl_type type,
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

    vertex_attrib& name ( const std::string& name );


    vertex_attrib& define_pointer();

    vertex_attrib& enable_array();

    vertex_attrib& disable_array();

private:
    enum gl_type _type;

    GLuint _size;

    size_t _type_size;

    GLint _location;

    bool _normalised;

    GLuint _stride;

    GLuint _offset;

    std::string _name;
};
}

#endif // ifndef GLPP_VERTEX_ATTRIB_H
