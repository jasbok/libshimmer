#ifndef GLPP_VERTEX_ARRAY_H
#define GLPP_VERTEX_ARRAY_H

#include <GL/glew.h>

namespace glpp
{
class vertex_array
{
public:
    vertex_array();

    vertex_array( vertex_array&& move );

    vertex_array( const vertex_array& copy ) = delete;

    virtual ~vertex_array();

    vertex_array& operator=( vertex_array&& move );

    vertex_array& operator=( const vertex_array& copy ) = delete;

    GLuint        handle() const;

    vertex_array& bind();

    void          unbind();

private:
    GLuint _handle;
};
}

#endif // ifndef GLPP_VERTEX_ARRAY_H
