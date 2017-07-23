#include "gl_program_variable.h"

using namespace shimmer;

gl_program_variable::gl_program_variable ( const gl_program_variable& copy )
    : glsl_variable ( copy ),
      _location ( copy._location )
{}

gl_program_variable::gl_program_variable ( gl_program_variable&& move )
    : glsl_variable ( std::move ( move ) ),
      _location ( move._location )
{}

gl_program_variable::gl_program_variable (
    const glsl_variable& variable,
    GLint location )
    : glsl_variable ( variable ),
      _location ( location )
{}

gl_program_variable::gl_program_variable (
    glsl_variable&& variable,
    GLint location )
    : glsl_variable ( std::move ( variable ) ),
      _location ( location )
{}

gl_program_variable& gl_program_variable::operator = ( const gl_program_variable& copy )
{
    glsl_variable::operator = ( copy );
    _location = copy._location;

    return *this;
}

gl_program_variable& gl_program_variable::operator = ( gl_program_variable&& move )
{
    glsl_variable::operator = ( std::move ( move ) );
    _location = move._location;

    return *this;
}
