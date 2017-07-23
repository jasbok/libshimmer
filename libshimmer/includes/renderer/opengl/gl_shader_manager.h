#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_SHADER_MANAGER_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_SHADER_MANAGER_H

#include "gl_shader.h"
#include "simple_cache.hpp"
#include <GL/glew.h>
#include <memory>
#include <string>

namespace shimmer::gl_shader_manager
{
typedef simple_cache<std::string, std::shared_ptr<gl_shader>> default_cache;
std::shared_ptr<gl_shader> create ( const std::string& source, GLuint type );
std::shared_ptr<gl_shader> load ( const std::string& path, GLuint type );
}

#endif








