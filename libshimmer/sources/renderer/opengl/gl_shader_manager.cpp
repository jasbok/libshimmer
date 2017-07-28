#include "gl_shader_manager.h"

#include "file_reader.h"
#include "gl_shader_compiler.h"
#include "glsl_variable_extractor.h"
#include "simple_cache.hpp"

using namespace shimmer;
using namespace std;

shared_ptr<gl_shader> gl_shader_manager::create ( const string& source,
                                                  GLuint        type )
{
    shared_ptr<gl_shader> shader = nullptr;
    auto compiled                =
        gl_shader_compiler::compile ( source, type );

    if ( compiled ) {
        shader = make_shared<gl_shader>(
            compiled,
            glsl_variable_extractor::extract ( source ) );
    }

    return shader;
}

shared_ptr<gl_shader> gl_shader_manager::load ( const string& path,
                                                GLuint        type )
{
    shared_ptr<gl_shader> shader = nullptr;
    auto source                  = file_reader::read ( path );
    auto compiled                =
        gl_shader_compiler::compile ( source, type );

    if ( compiled ) {
        shader = make_shared<gl_shader>(
            gl_shader_compiler::compile ( source, type ),
            glsl_variable_extractor::extract ( source ) );
    }

    return shader;
}
