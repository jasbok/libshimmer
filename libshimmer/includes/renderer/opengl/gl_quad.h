#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_QUAD_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_QUAD_H

#include "accessor_macros.h"
#include "gl_mesh.h"
#include "gl_program.h"
#include "gl_texture.h"
#include "gl_vertex_array.h"

#include <glm/glm.hpp>

namespace shimmer
{
class gl_quad
{
public:
    gl_quad( std::shared_ptr<gl_program>              program,
             std::vector<std::shared_ptr<gl_texture>> textures );

    gl_quad( std::shared_ptr<gl_program>              program,
             std::vector<std::shared_ptr<gl_texture>> textures,
             float                                    aspect_ratio,
             bool                                     flip_y );

    virtual ~gl_quad() {}

    gl_quad& shape ( float aspect_ratio,
                     bool  flip_y = false );

    gl_quad& transform ( const glm::mat4& transform );

    void     draw();

private:
    GETTER ( glm::mat4,                                transform );

    GETTER ( std::shared_ptr<gl_program>,              program );

    GETTER ( std::vector<std::shared_ptr<gl_texture>>, textures );

    static std::shared_ptr<gl_buffer> _ebo;

    std::shared_ptr<gl_buffer> _vbo;

    std::shared_ptr<gl_vertex_array> _vao;
};
}

#endif // ifndef LIBSHIMMER_RENDERER_OPENGL_GL_QUAD_H
