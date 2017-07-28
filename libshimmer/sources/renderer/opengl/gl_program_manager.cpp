#include "gl_program_manager.h"

#include "gl_shader.h"
#include "gl_shader_linker.h"
#include "glsl_variable.h"

#include "spdlog/spdlog.h"

using namespace shimmer;
using namespace std;

static std::shared_ptr<spdlog::logger> LOGGER
    = spdlog::stdout_color_mt ( "gl_program_manager" );

shared_ptr<gl_program> gl_program_manager::load (
    const vector<shared_ptr<const gl_shader>>& shaders )
{
    shared_ptr<gl_program> program = nullptr;
    vector<GLuint> shader_handles;
    vector<glsl_variable> shader_variables;

    for ( auto shader : shaders ) {
        if ( shader != nullptr ) {
            shader_handles.push_back ( shader->handle() );

            shader_variables.insert (
                shader_variables.end(),
                shader->variables().begin(),
                shader->variables().end() );
        } else {
            LOGGER->error ( "An invalid shader was passed to the "
                            "program manager load function." );

            return nullptr;
        }
    }

    auto linked = gl_shader_linker::link ( shader_handles );

    if ( linked ) {
        program = make_shared<gl_program>( linked, shader_variables );
    }

    return program;
}
