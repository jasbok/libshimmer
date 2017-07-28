#include "gl_shader_manager.h"
#include "simple_cache.hpp"

#include "catch/catch.hpp"
#include "spdlog/spdlog.h"

using namespace std;
using namespace shimmer;

TEST_CASE (
    "Load, store and retrieve shaders using the shader manager and cache.",
    "[gl_shader_manager]" )
{
    gl_shader_manager::default_cache cache ( "catch_shader_cache" );
    string fs_shader_path = "data/glsl/simple.fs";
    string vs_shader_path = "data/glsl/simple.vs";

    auto fs_shader = gl_shader_manager::load ( fs_shader_path,
                                               GL_FRAGMENT_SHADER );

    auto vs_shader = gl_shader_manager::load ( vs_shader_path,
                                               GL_VERTEX_SHADER );

    CHECK ( fs_shader->handle() != 0 );
    CHECK ( fs_shader->variables().size() == 3 );

    CHECK ( vs_shader->handle() != 0 );
    CHECK ( vs_shader->variables().size() == 4 );

    cache.set ( fs_shader_path, fs_shader );
    cache.set ( vs_shader_path, vs_shader );
    CHECK ( cache.exists ( fs_shader_path ) == true );
    CHECK ( cache.exists ( vs_shader_path ) == true );

    auto fs_shader_ref = cache.get ( fs_shader_path );
    auto vs_shader_ref = cache.get ( vs_shader_path );

    CHECK ( fs_shader == fs_shader_ref );
    CHECK ( vs_shader == vs_shader_ref );
    CHECK ( fs_shader->handle() == fs_shader_ref->handle() );
    CHECK ( vs_shader->handle() == vs_shader_ref->handle() );

    CHECK ( fs_shader.use_count() == 3 );
    CHECK ( vs_shader.use_count() == 3 );

    CHECK ( cache.evict ( fs_shader_path ) == fs_shader );
    CHECK ( cache.exists ( fs_shader_path ) == false );
    CHECK ( cache.exists ( vs_shader_path ) == true );
    CHECK ( fs_shader.use_count() == 2 );
    CHECK ( vs_shader.use_count() == 3 );

    cache.clear();
    CHECK ( cache.exists ( fs_shader_path ) == false );
    CHECK ( cache.exists ( vs_shader_path ) == false );
    CHECK ( fs_shader.use_count() == 2 );
    CHECK ( vs_shader.use_count() == 2 );

    fs_shader_ref = nullptr;
    vs_shader_ref = nullptr;
    CHECK ( fs_shader.use_count() == 1 );
    CHECK ( vs_shader.use_count() == 1 );
}

TEST_CASE ( "Check that the shader manager returns a nullptr for an invalid "
            "shader.",
            "[gl_shader_manager]" )
{
    gl_shader_manager::default_cache cache ( "catch_shader_cache_garbage" );
    string garbage_path = "data/glsl/garbage";

    spdlog::set_level ( spdlog::level::off );

    auto fs_shader =
        gl_shader_manager::load ( garbage_path, GL_FRAGMENT_SHADER );
    auto vs_shader =
        gl_shader_manager::load ( garbage_path, GL_VERTEX_SHADER );

    spdlog::set_level ( spdlog::level::err );

    CHECK ( fs_shader == nullptr );
    CHECK ( vs_shader == nullptr );
}
