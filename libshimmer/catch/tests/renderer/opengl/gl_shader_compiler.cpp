#include "file_reader.h"
#include "gl_shader_compiler.h"

#include "catch/catch.hpp"
#include "spdlog/spdlog.h"

using namespace std;
using namespace shimmer;

TEST_CASE ( "Compile a few test shaders.",
            "[gl_shader_compiler]" )
{
    string simple_fs_source = file_reader::read ( "data/glsl/simple.fs" );
    string simple_vs_source = file_reader::read ( "data/glsl/simple.vs" );
    string garbage_source   = file_reader::read ( "data/glsl/garbage" );
    string empty_source     = "";
    string uninitialised_source;

    REQUIRE ( simple_fs_source.empty() == false );
    REQUIRE ( simple_vs_source.empty() == false );
    REQUIRE ( garbage_source.empty() == false );
    REQUIRE ( empty_source.empty() == true );

    auto simple_fs = gl_shader_compiler::compile ( simple_fs_source,
                                                   GL_FRAGMENT_SHADER );

    auto simple_vs = gl_shader_compiler::compile ( simple_vs_source,
                                                   GL_VERTEX_SHADER );

    spdlog::set_level ( spdlog::level::off );

    auto swapped_fs = gl_shader_compiler::compile ( simple_vs_source,
                                                    GL_FRAGMENT_SHADER );

    auto swapped_vs = gl_shader_compiler::compile ( simple_fs_source,
                                                    GL_VERTEX_SHADER );

    auto garbage_fs = gl_shader_compiler::compile ( garbage_source,
                                                    GL_FRAGMENT_SHADER );

    auto garbage_vs = gl_shader_compiler::compile ( garbage_source,
                                                    GL_VERTEX_SHADER );

    auto empty_fs = gl_shader_compiler::compile ( empty_source,
                                                  GL_FRAGMENT_SHADER );

    auto empty_vs = gl_shader_compiler::compile ( empty_source,
                                                  GL_VERTEX_SHADER );

    auto uninitialised_fs = gl_shader_compiler::compile ( uninitialised_source,
                                                          GL_FRAGMENT_SHADER );

    auto uninitialised_vs = gl_shader_compiler::compile ( uninitialised_source,
                                                          GL_VERTEX_SHADER );

    spdlog::set_level ( spdlog::level::err );

    CHECK ( simple_fs != 0 );
    CHECK ( simple_vs != 0 );

    CHECK ( swapped_fs == 0 );
    CHECK ( swapped_vs == 0 );

    CHECK ( garbage_fs == 0 );
    CHECK ( garbage_vs == 0 );

    CHECK ( empty_fs == 0 );
    CHECK ( empty_vs == 0 );

    CHECK ( uninitialised_fs == 0 );
    CHECK ( uninitialised_vs == 0 );
}
