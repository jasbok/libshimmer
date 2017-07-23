#include "gl_shader.h"

using namespace std;
using namespace shimmer;

gl_shader::gl_shader ( GLuint handle )
    : _handle ( handle )
{}

gl_shader::~gl_shader()
{
    glDeleteShader( _handle );
}
