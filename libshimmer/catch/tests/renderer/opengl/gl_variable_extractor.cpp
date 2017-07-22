#include "catch.hpp"
#include "file_reader.h"
#include "gl_variable_extractor.h"
#include "spdlog.h"

using namespace std;
using namespace shimmer;

TEST_CASE ( "Extract GLSL variables from source files.",
            "[gl_variable_extractor]" )
{
    string simple_fs_source = file_reader::read ( "data/glsl/simple.fs" );
    string simple_vs_source = file_reader::read ( "data/glsl/simple.vs" );

    auto fragment_variables =
        gl_variable_extractor::extract ( simple_fs_source );

    auto vertex_variables =
        gl_variable_extractor::extract ( simple_vs_source );

    REQUIRE ( fragment_variables.size() == 3 );
    REQUIRE ( vertex_variables.size() == 4 );

    CHECK ( fragment_variables[0].qualifier() == glsl_qualifier::VARYING );
    CHECK ( fragment_variables[0].type() == glsl_type::VEC2 );
    CHECK ( fragment_variables[0].name() == "fs_texcoord" );
    CHECK ( fragment_variables[0].size() == 1 );
    CHECK ( fragment_variables[0].location() == -1 );

    CHECK ( fragment_variables[1].qualifier() == glsl_qualifier::UNIFORM );
    CHECK ( fragment_variables[1].type() == glsl_type::SAMPLER2D );
    CHECK ( fragment_variables[1].name() == "sampler" );
    CHECK ( fragment_variables[1].size() == 1 );
    CHECK ( fragment_variables[1].location() == -1 );

    CHECK ( fragment_variables[2].qualifier() == glsl_qualifier::UNIFORM );
    CHECK ( fragment_variables[2].type() == glsl_type::FLOAT );
    CHECK ( fragment_variables[2].name() == "floats" );
    CHECK ( fragment_variables[2].size() == 15 );
    CHECK ( fragment_variables[2].location() == -1 );

    CHECK ( vertex_variables[0].qualifier() == glsl_qualifier::ATTRIBUTE );
    CHECK ( vertex_variables[0].type() == glsl_type::VEC3 );
    CHECK ( vertex_variables[0].name() == "position" );
    CHECK ( vertex_variables[0].size() == 1 );
    CHECK ( vertex_variables[0].location() == -1 );

    CHECK ( vertex_variables[1].qualifier() == glsl_qualifier::ATTRIBUTE );
    CHECK ( vertex_variables[1].type() == glsl_type::VEC2 );
    CHECK ( vertex_variables[1].name() == "texcoord" );
    CHECK ( vertex_variables[1].size() == 1 );
    CHECK ( vertex_variables[1].location() == -1 );

    CHECK ( vertex_variables[2].qualifier() == glsl_qualifier::VARYING );
    CHECK ( vertex_variables[2].type() == glsl_type::VEC2 );
    CHECK ( vertex_variables[2].name() == "fs_texcoord" );
    CHECK ( vertex_variables[2].size() == 1 );
    CHECK ( vertex_variables[2].location() == -1 );

    CHECK ( vertex_variables[3].qualifier() == glsl_qualifier::VARYING );
    CHECK ( vertex_variables[3].type() == glsl_type::FLOAT );
    CHECK ( vertex_variables[3].name() == "scale" );
    CHECK ( vertex_variables[3].size() == 1 );
    CHECK ( vertex_variables[3].location() == -1 );
}
