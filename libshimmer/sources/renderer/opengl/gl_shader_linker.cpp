#include "gl_shader_linker.h"
#include "spdlog.h"

#define GL_LOG_SIZE 2048

using namespace shimmer;

static std::shared_ptr<spdlog::logger> LOGGER
    = spdlog::stdout_color_mt ( "gl_shader_linker" );

GLuint gl_shader_linker::link ( const std::vector<GLuint>& shaders )
{
    if ( shaders.size() < 2 ) {
        LOGGER->error (
            "Invalid shader list, less than two shaders provided." );
        return 0;
    }

    for ( auto shader : shaders ) {
        if ( !shader ) {
            LOGGER->error ( "Found an invalid shader in the list." );
            return 0;
        }
    }

    GLuint program = glCreateProgram();

    for ( auto shader : shaders ) {
        glAttachShader ( program, shader );
    }

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
