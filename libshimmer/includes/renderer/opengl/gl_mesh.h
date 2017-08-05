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
    gl_mesh( std::vector<GLfloat> vertices,
             std::vector<GLsizeiptr> elements,
             unsigned int       vertices_stride = 7,
             unsigned int       elements_stride = 3 );

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
