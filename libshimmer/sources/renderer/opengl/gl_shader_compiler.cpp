#include "gl_shader_compiler.h"

#include "spdlog/spdlog.h"

#define GL_LOG_SIZE 2048

using namespace shimmer;
using namespace std;

static std::shared_ptr<spdlog::logger> LOGGER
    = spdlog::stdout_color_mt ( "gl_shader_compiler" );

GLuint gl_shader_compiler::compile (
    const string& source,
    GLuint        type )
{
    if ( source.empty() ) {
        LOGGER->error ( "An empty source string was provided to compiler." );

        return 0;
    }

    if ( (type != GL_FRAGMENT_SHADER) && (type != GL_VERTEX_SHADER) ) {
        LOGGER->error ( "Incorrect GL type provided to compiler: {}", type );

        return 0;
    }

    GLuint shader = glCreateShader ( type );

    const GLchar* shader_source_gl = source.c_str();
    glShaderSource ( shader, 1, &shader_source_gl, nullptr );
    glCompileShader ( shader );

    GLint success;
    glGetShaderiv ( shader, GL_COMPILE_STATUS, &success );

    if ( !success ) {
        GLchar log[GL_LOG_SIZE];
        glGetShaderInfoLog ( shader, GL_LOG_SIZE, nullptr, log );
        LOGGER->error ( "Shader Compilation Failed: {}", log );

        glDeleteShader ( shader );
        shader = 0;
    }

    return shader;
}
