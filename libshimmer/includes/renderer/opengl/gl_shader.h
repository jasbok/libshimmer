#ifndef LIBSHIMMER_RENDER_OPENGL_GL_SHADER_H
#define LIBSHIMMER_RENDER_OPENGL_GL_SHADER_H

#include "accessor_macros.h"
#include "glsl_variable.h"
#include <GL/glew.h>
#include <string>
#include <vector>

namespace shimmer
{
class gl_shader
{
public:
    gl_shader (GLuint handle);

    virtual ~gl_shader();

private:
    GETTER ( gl_shader, GLuint, handle);

    FLUENT ( gl_shader, std::string, id );

    FLUENT ( gl_shader, std::string, path );

    FLUENT ( gl_shader, std::vector<glsl_variable>, variables);
};
}

#endif
