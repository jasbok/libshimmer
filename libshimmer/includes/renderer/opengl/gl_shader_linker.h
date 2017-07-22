#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_SHADER_LINKER_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_SHADER_LINKER_H

#include <GL/glew.h>

namespace shimmer
{
class gl_shader_linker
{
public:
    virtual ~gl_shader_linker() {}

    static GLuint link(GLuint vertex, GLuint fragment);
};
}

#endif
