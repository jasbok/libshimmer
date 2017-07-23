#include "gl_program.h"

using namespace shimmer;
using namespace std;

gl_program::gl_program (
    GLuint handle,
    const std::vector<glsl_variable>& variables )
    : _handle ( handle ),
      _uniforms()
{
    for ( auto& var : variables ) {
        if ( var.qualifier() == glsl::qualifier::UNIFORM ) {
            auto location = glGetUniformLocation (
                                _handle, var.name().c_str() );

            if ( location >= 0 ) {
                _uniforms.emplace ( var.name(),
                                    gl_program_variable ( var, location ) );
            }
        }
    }
}

gl_program::~gl_program()
{
    glDeleteProgram ( _handle );
}

void gl_program::use()
{
    glUseProgram ( _handle );
}
