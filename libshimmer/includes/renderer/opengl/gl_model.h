#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_MODEL_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_MODEL_H

#include "accessor_macros.h"
#include "gl_mesh.h"
#include "gl_program.h"
#include "gl_texture.h"
#include "gl_vertex_array.h"

#include <memory>

namespace shimmer
{
class gl_model
{
public:
    gl_model();

    virtual ~gl_model();

    void render();

private:
    std::shared_ptr<gl_program> _program;

    std::shared_ptr<gl_mesh> _mesh;

    std::vector<std::shared_ptr<gl_texture>> _textures;

    std::shared_ptr<gl_vertex_array> _vao;
};
}

#endif // ifndef LIBSHIMMER_RENDERER_OPENGL_GL_MODEL_H
