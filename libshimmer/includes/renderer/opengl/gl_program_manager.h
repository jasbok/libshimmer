#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_PROGRAM_MANAGER_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_PROGRAM_MANAGER_H

#include "gl_program.h"
#include "gl_shader.h"
#include "simple_cache.hpp"

namespace shimmer::gl_program_manager
{
using namespace std;
typedef simple_cache<string, shared_ptr<gl_program>> default_cache;

shared_ptr<gl_program> load ( const vector<shared_ptr<gl_shader>>& shaders );
}

#endif
