#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_PROGRAM_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_PROGRAM_H

#include "accessor_macros.h"
#include "gl_program_variable.h"

#include <GL/glew.h>

#include <string>
#include <unordered_map>
#include <vector>

namespace shimmer
{
class gl_program
{
public:
    gl_program(
        GLuint                            handle,
        const std::vector<glsl_variable>& variables );

    virtual ~gl_program();

    void use();

private:
    GETTER ( GLuint,       handle );

    typedef std::unordered_map<std::string, gl_program_variable> variable_map;
    GETTER ( variable_map, uniforms );
};
}

#endif // ifndef LIBSHIMMER_RENDERER_OPENGL_GL_PROGRAM_H
