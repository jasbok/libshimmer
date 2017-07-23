#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_SHADER_LINKER_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_SHADER_LINKER_H

#include <GL/glew.h>
#include <vector>

namespace shimmer::gl_shader_linker
{
GLuint link ( const std::vector<GLuint>& shaders );
}

#endif
