#include "check_opengl.h"
#include "gl_program_manager.h"
#include "gl_shader_manager.h"

#include "catch/catch.hpp"

using namespace shimmer;
using namespace std;

TEST_CASE ( "Compile shader programs using the program manager.",
            "[gl_program_manager]" )
{
    CHECK_GL_NO_ERROR();

    gl_shader_manager::default_cache cache ( "catch_shader_cache" );

    string fs_shader_path = "data/glsl/simple.fs";
    string vs_shader_path = "data/glsl/simple.vs";
    string garbage_path   = "data/glsl/garbage";

    auto fs_shader = gl_shader_manager::load ( fs_shader_path,
                                               GL_FRAGMENT_SHADER );
    CHECK_GL_NO_ERROR();

    auto vs_shader = gl_shader_manager::load ( vs_shader_path,
                                               GL_VERTEX_SHADER );
    CHECK_GL_NO_ERROR();

    auto garbage_shader = gl_shader_manager::load ( garbage_path,
                                                    GL_VERTEX_SHADER );
    CHECK_GL_NO_ERROR();

    REQUIRE ( fs_shader != nullptr );
    REQUIRE ( vs_shader != nullptr );
    REQUIRE ( garbage_shader == nullptr );

    auto valid_program = gl_program_manager::load ( { fs_shader,
                                                      vs_shader } );
    CHECK_GL_NO_ERROR();
    CHECK ( valid_program != nullptr );
    CHECK ( valid_program->handle() != 0 );

    auto invalid_program_a = gl_program_manager::load ( { fs_shader,
                                                          garbage_shader } );
    CHECK_GL_NO_ERROR();
    CHECK ( invalid_program_a == nullptr );

    auto invalid_program_b = gl_program_manager::load ( { garbage_shader,
                                                          vs_shader } );
    CHECK_GL_NO_ERROR();
    CHECK ( invalid_program_b == nullptr );

    auto fs_partial_program = gl_program_manager::load ( { fs_shader } );
    CHECK_GL_NO_ERROR();
    CHECK ( fs_partial_program != nullptr );
    CHECK ( fs_partial_program->handle() != 0 );

    auto vs_partial_program = gl_program_manager::load ( { vs_shader } );
    CHECK_GL_NO_ERROR();
    CHECK ( vs_partial_program != nullptr );
    CHECK ( vs_partial_program->handle() != 0 );

    CHECK_GL_NO_ERROR();
}
