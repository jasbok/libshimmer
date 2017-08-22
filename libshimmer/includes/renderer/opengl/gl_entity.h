#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_ENTITY_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_ENTITY_H

#include "accessor_macros.h"
#include "gl_mesh.h"
#include "gl_program.h"
#include "gl_texture.h"
#include "gl_vertex_array.h"

#include <glm/glm.hpp>

namespace shimmer
{
class gl_entity
{
public:
    virtual ~gl_entity() {}

    virtual void draw() = 0;

    virtual void transform ( const glm::mat4& transform ) = 0;

private:
    GETTER ( std::shared_ptr<gl_mesh>,                 mesh );

    GETTER ( std::shared_ptr<gl_program>,              program );

    GETTER ( std::vector<std::shared_ptr<gl_texture>>, textures );

    std::shared_ptr<gl_vertex_array> _vao;
};
}

#endif // ifndef LIBSHIMMER_RENDERER_OPENGL_GL_ENTITY_H
