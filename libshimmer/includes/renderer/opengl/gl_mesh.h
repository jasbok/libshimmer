#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_MESH_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_MESH_H

#include "accessor_macros.h"
#include "gl_buffer.h"

#include <vector>

namespace shimmer
{
class gl_mesh
{
public:
    gl_mesh( const std::vector<GLfloat>&    vertices,
             const std::vector<GLsizeiptr>& elements,
             unsigned int                   vertices_stride,
             unsigned int                   elements_stride );

    virtual ~gl_mesh();

    void bind() const;

    void unbind() const;

private:
    GETTER ( gl_buffer,    vertices );

    GETTER ( unsigned int, vertices_stride );

    GETTER ( GLsizeiptr,   vertices_count );

    GETTER ( gl_buffer,    elements );

    GETTER ( unsigned int, elements_stride );

    GETTER ( GLsizeiptr,   elements_count );
};
}

#endif // ifndef LIBSHIMMER_RENDERER_OPENGL_GL_MESH_H
