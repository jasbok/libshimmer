#include "gl_shader_manager.h"
#include "file_reader.h"
#include "gl_shader_compiler.h"
#include "glsl_variable_extractor.h"
#include "simple_cache.hpp"

using namespace std;
using namespace shimmer;

gl_shader_manager::gl_shader_manager()
    :  _cache ( make_shared<simple_cache<string, shared_ptr<gl_shader>>>
                ( "gl_shader_manager" ) )
{}

void gl_shader_manager::clear()
{
    _cache->clear();
}

shared_ptr<gl_shader> gl_shader_manager::evict ( const string& id )
{
    return _cache->evict(id);
}

bool gl_shader_manager::exists ( const string& id )
{
    return _cache->exists ( id );
}

shared_ptr<gl_shader> gl_shader_manager::get ( const string& id )
{
    return _cache->get ( id );
}

shared_ptr<gl_shader> gl_shader_manager::load (
    const string& path,
    GLuint type )
{
    auto source = file_reader::read ( path );
    auto shader = make_shared<gl_shader> (
                      gl_shader_compiler::compile ( source, type ) );

    shader->id ( path )
    .path ( path )
    .variables ( glsl_variable_extractor::extract ( source ) );

    return shader;
}

void gl_shader_manager::set (
    const string& id,
    const shared_ptr<gl_shader>& shader )
{
    _cache->set ( id, shader );
}

