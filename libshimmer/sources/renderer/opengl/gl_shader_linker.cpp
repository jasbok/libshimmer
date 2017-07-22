#include "gl_shader_linker.h"
#include "spdlog.h"

#define GL_LOG_SIZE 2048

using namespace shimmer;

static std::shared_ptr<spdlog::logger> LOGGER
    = spdlog::stdout_color_mt ( "gl_shader_linker" );

GLuint gl_shader_linker::link ( GLuint vertex, GLuint fragment )
{
    if ( !fragment ) {
        LOGGER->error ( "Invalid fragment shader provided to linker." );
        return 0;
    }
    if ( !vertex ) {
        LOGGER->error ( "Invalid vertex shader provided to linker." );
        return 0;
    }

    GLuint program = glCreateProgram();
    glAttachShader ( program, fragment );
    glAttachShader ( program, vertex );
    glLinkProgram ( program );

    GLint success;
    glGetProgramiv ( program, GL_LINK_STATUS, &success );

    if ( !success ) {
        GLchar log[GL_LOG_SIZE];
        glGetProgramInfoLog ( program, GL_LOG_SIZE, nullptr, log );
        LOGGER->error ( "Program linking failed: {}", log );

        glDeleteProgram ( program );
        program = 0;
    }

    return program;
}
