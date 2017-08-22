#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_PROGRAM_MANAGER_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_PROGRAM_MANAGER_H

#include "gl_program.h"
#include "gl_shader.h"
#include "simple_cache.hpp"

namespace shimmer
{
namespace gl_program_manager
{
typedef simple_cache<std::string, std::shared_ptr<gl_program>> default_cache;

std::shared_ptr<gl_program> load (
    const std::vector<std::shared_ptr<const gl_shader>>& shaders );
}
}

#endif // ifndef LIBSHIMMER_RENDERER_OPENGL_GL_PROGRAM_MANAGER_H
