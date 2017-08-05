#include "gl_program.h"

using namespace shimmer;
using namespace std;

gl_program::gl_program(
    GLuint                            handle,
    const std::vector<glsl_variable>& variables )
    : _handle ( handle ),
      _uniforms()
{
    for ( auto& var : variables ) {
        switch ( var.qualifier() ) {
        case glsl::qualifier::ATTRIBUTE:
        case glsl::qualifier::INPUT:
            _add_input ( var );
            break;

        case glsl::qualifier::UNIFORM:
            _add_uniform ( var );
            break;

        default:
            break;
        }
    }
}

void gl_program::_add_input ( const glsl_variable& variable )
{
    auto location = glGetAttribLocation ( _handle, variable.name().c_str() );

    if ( location >= 0 ) {
        _inputs.emplace ( variable.name(),
                          gl_program_variable ( variable, location ) );
    }
}

void gl_program::_add_uniform ( const glsl_variable& variable )
{
    auto location = glGetUniformLocation ( _handle, variable.name().c_str() );

    if ( location >= 0 ) {
        _uniforms.emplace ( variable.name(),
                            gl_program_variable ( variable, location ) );
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
