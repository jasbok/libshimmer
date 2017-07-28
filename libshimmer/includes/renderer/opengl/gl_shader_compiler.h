#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_SHADER_COMPILER_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_SHADER_COMPILER_H

#include <GL/glew.h>

#include <string>
#include <vector>

namespace shimmer::gl_shader_compiler
{
GLuint compile ( const std::string& source,
                 GLuint             type );
}

#endif // ifndef LIBSHIMMER_RENDERER_OPENGL_GL_SHADER_COMPILER_H
