#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_VERTEX_ARRAY_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_VERTEX_ARRAY_H

#include "accessor_macros.h"

#include <GL/glew.h>

namespace shimmer
{
class gl_vertex_array
{
public:
    gl_vertex_array();

    virtual ~gl_vertex_array();

    void bind();

    void unbind();

private:
    GETTER ( GLuint, handle );
};
}

#endif // ifndef LIBSHIMMER_RENDERER_OPENGL_GL_VERTEX_ARRAY_H
