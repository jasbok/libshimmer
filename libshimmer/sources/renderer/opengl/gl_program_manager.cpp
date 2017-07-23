#include "gl_program_manager.h"
#include "gl_shader.h"
#include "gl_shader_linker.h"
#include "glsl_variable.h"

using namespace shimmer;
using namespace std;

shared_ptr<gl_program> gl_program_manager::load (
    const vector<shared_ptr<gl_shader>>& shaders )
{
    shared_ptr<gl_program> program =  nullptr;
    vector<GLuint> shader_handles;
    vector<glsl_variable> shader_variables;

    for ( auto shader : shaders ) {
        shader_handles.push_back ( shader->handle() );
        shader_variables.insert (
            shader_variables.end(),
            shader->variables().begin(),
            shader->variables().end() );
    }

    auto linked = gl_shader_linker::link ( shader_handles );

    if ( linked ) {
        program = make_shared<gl_program> ( linked, shader_variables );
    }

    return program;
}

