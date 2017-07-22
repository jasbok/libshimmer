#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_SHADER_COMPILER_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_SHADER_COMPILER_H

#include <GL/glew.h>
#include <string>
#include <vector>

namespace shimmer
{
class gl_shader_compiler
{
public:
    virtual ~gl_shader_compiler() {}

    static GLuint compile ( const std::string& source, GLuint type );

};
}

#endif
