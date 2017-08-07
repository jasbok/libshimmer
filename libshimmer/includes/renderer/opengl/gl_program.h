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

    void  use() const;

    GLint attribute_location ( const std::string& name ) const;

    GLint uniform_location ( const std::string& name ) const;

    void  set_sampler ( const std::string& name,
                        int                value );

private:
    GETTER ( GLuint,                     handle );

    GETTER ( std::vector<glsl_variable>, variables );
};
}

#endif // ifndef LIBSHIMMER_RENDERER_OPENGL_GL_PROGRAM_H
