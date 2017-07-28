#include "file_reader.h"
#include "gl_shader_compiler.h"
#include "gl_shader_linker.h"

#include "catch/catch.hpp"
#include "spdlog/spdlog.h"

using namespace std;
using namespace shimmer;

TEST_CASE ( "Link valid compiled shaders of a program.",
            "[gl_shader_linker]" )
{
    string simple_fs_source = file_reader::read ( "data/glsl/simple.fs" );
    string simple_vs_source = file_reader::read ( "data/glsl/simple.vs" );

    REQUIRE ( simple_fs_source.empty() == false );
    REQUIRE ( simple_vs_source.empty() == false );

    auto simple_fs = gl_shader_compiler::compile ( simple_fs_source,
                                                   GL_FRAGMENT_SHADER );

    auto simple_vs = gl_shader_compiler::compile ( simple_vs_source,
                                                   GL_VERTEX_SHADER );

    REQUIRE ( simple_fs !=  0 );
    REQUIRE ( simple_vs !=  0 );

    auto program = gl_shader_linker::link ( { simple_vs, simple_fs } );

    CHECK ( program !=  0 );
}

TEST_CASE ( "Link invalid shaders of a program and check that an invalid "
            "program is returned.",
            "[gl_shader_linker]" )
{
    string simple_fs_source = file_reader::read ( "data/glsl/garbage" );
    string simple_vs_source = file_reader::read ( "data/glsl/simple.vs" );

    REQUIRE ( simple_fs_source.empty() == false );
    REQUIRE ( simple_vs_source.empty() == false );

    spdlog::set_level ( spdlog::level::off );

    auto simple_fs = gl_shader_compiler::compile ( simple_fs_source,
                                                   GL_FRAGMENT_SHADER );

    auto simple_vs = gl_shader_compiler::compile ( simple_vs_source,
                                                   GL_VERTEX_SHADER );

    CHECK ( simple_fs ==  0 );
    CHECK ( simple_vs !=  0 );

    auto program = gl_shader_linker::link ( { simple_vs, simple_fs } );

    spdlog::set_level ( spdlog::level::err );

    CHECK ( program ==  0 );
}
