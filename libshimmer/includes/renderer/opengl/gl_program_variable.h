#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_PROGRAM_VARIABLE_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_PROGRAM_VARIABLE_H

#include "accessor_macros.h"
#include "glsl_variable.h"

#include <GL/glew.h>

namespace shimmer
{
class gl_program_variable : public glsl_variable
{
public:
    gl_program_variable( const gl_program_variable& copy );

    gl_program_variable( gl_program_variable&& move );

    gl_program_variable( const glsl_variable& variable,
                         GLint                location );

    gl_program_variable( glsl_variable&& variable,
                         GLint           location );

    virtual ~gl_program_variable() {}

    gl_program_variable& operator=( const gl_program_variable& copy );

    gl_program_variable& operator=( gl_program_variable&& move );

private:
    GETTER ( GLint, location );
};
}

#endif // ifndef LIBSHIMMER_RENDERER_OPENGL_GL_PROGRAM_VARIABLE_H
