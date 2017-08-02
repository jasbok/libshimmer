#include "check_opengl.h"
#include "file_reader.h"
#include "gl_shader_compiler.h"
#include "gl_shader_linker.h"

#include "catch/catch.hpp"

using namespace shimmer;
using namespace std;

TEST_CASE ( "Link valid compiled shaders of a program.",
            "[gl_shader_linker]" )
{
    CHECK_GL_NO_ERROR();

    string simple_fs_source = file_reader::read ( "data/glsl/simple.fs" );
    string simple_vs_source = file_reader::read ( "data/glsl/simple.vs" );

    REQUIRE ( simple_fs_source.empty() == false );
    REQUIRE ( simple_vs_source.empty() == false );

    auto simple_fs = gl_shader_compiler::compile ( simple_fs_source,
                                                   GL_FRAGMENT_SHADER );
    CHECK_GL_NO_ERROR();

    auto simple_vs = gl_shader_compiler::compile ( simple_vs_source,
                                                   GL_VERTEX_SHADER );
    CHECK_GL_NO_ERROR();

    REQUIRE ( simple_fs !=  0 );
    REQUIRE ( simple_vs !=  0 );

    auto program = gl_shader_linker::link ( { simple_vs, simple_fs } );
    CHECK_GL_NO_ERROR();
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

    auto simple_fs = gl_shader_compiler::compile ( simple_fs_source,
                                                   GL_FRAGMENT_SHADER );
    CHECK_GL_NO_ERROR();

    auto simple_vs = gl_shader_compiler::compile ( simple_vs_source,
                                                   GL_VERTEX_SHADER );
    CHECK_GL_NO_ERROR();

    CHECK ( simple_fs ==  0 );
    CHECK ( simple_vs !=  0 );

    auto program = gl_shader_linker::link ( { simple_vs, simple_fs } );
    CHECK_GL_NO_ERROR();
    CHECK ( program ==  0 );
}
