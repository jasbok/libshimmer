#include "gl_shader.h"

using namespace shimmer;
using namespace std;

gl_shader::gl_shader(
    GLuint                       handle,
    const vector<glsl_variable>& variables )
    : _handle ( handle ),
      _variables ( variables )
{}

gl_shader::gl_shader(
    GLuint                       handle,
    std::vector<glsl_variable>&& variables )
    : _handle ( handle ),
      _variables ( std::move ( variables ) )
{}

gl_shader::~gl_shader()
{
    glDeleteShader ( _handle );
}
