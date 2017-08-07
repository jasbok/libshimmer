#include "gl_program.h"

using namespace shimmer;
using namespace std;

gl_program::gl_program(
    GLuint                            handle,
    const std::vector<glsl_variable>& variables )
    : _handle ( handle ),
      _variables ( variables )
{}

gl_program::~gl_program()
{
    glDeleteProgram ( _handle );
}

void gl_program::use() const
{
    glUseProgram ( _handle );
}

GLint gl_program::attribute_location ( const std::string& name ) const {
    return glGetAttribLocation ( _handle, name.c_str() );
}

GLint gl_program::uniform_location ( const std::string& name ) const {
    return glGetUniformLocation ( _handle, name.c_str() );
}

void gl_program::set_sampler ( const std::string& name,
                               int                value ) {
    glUniform1i ( uniform_location ( name ), value );
}
