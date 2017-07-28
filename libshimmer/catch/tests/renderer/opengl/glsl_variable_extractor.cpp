#include "file_reader.h"
#include "glsl_variable_extractor.h"

#include "catch/catch.hpp"
#include "spdlog/spdlog.h"

using namespace shimmer;
using namespace std;

TEST_CASE ( "Extract GLSL variables from source files.",
            "[glsl_variable_extractor]" )
{
    string simple_fs_source = file_reader::read ( "data/glsl/simple.fs" );
    string simple_vs_source = file_reader::read ( "data/glsl/simple.vs" );

    auto fragment_variables =
        glsl_variable_extractor::extract ( simple_fs_source );

    auto vertex_variables =
        glsl_variable_extractor::extract ( simple_vs_source );

    REQUIRE ( fragment_variables.size() == 3 );
    REQUIRE ( vertex_variables.size() == 4 );

    CHECK ( fragment_variables[0].qualifier() == glsl::qualifier::VARYING );
    CHECK ( fragment_variables[0].type() == glsl::type::VEC2 );
    CHECK ( fragment_variables[0].name() == "fs_texcoord" );
    CHECK ( fragment_variables[0].size() == 1 );

    CHECK ( fragment_variables[1].qualifier() == glsl::qualifier::UNIFORM );
    CHECK ( fragment_variables[1].type() == glsl::type::SAMPLER2D );
    CHECK ( fragment_variables[1].name() == "sampler" );
    CHECK ( fragment_variables[1].size() == 1 );

    CHECK ( fragment_variables[2].qualifier() == glsl::qualifier::UNIFORM );
    CHECK ( fragment_variables[2].type() == glsl::type::FLOAT );
    CHECK ( fragment_variables[2].name() == "floats" );
    CHECK ( fragment_variables[2].size() == 15 );

    CHECK ( vertex_variables[0].qualifier() == glsl::qualifier::ATTRIBUTE );
    CHECK ( vertex_variables[0].type() == glsl::type::VEC3 );
    CHECK ( vertex_variables[0].name() == "position" );
    CHECK ( vertex_variables[0].size() == 1 );

    CHECK ( vertex_variables[1].qualifier() == glsl::qualifier::ATTRIBUTE );
    CHECK ( vertex_variables[1].type() == glsl::type::VEC2 );
    CHECK ( vertex_variables[1].name() == "texcoord" );
    CHECK ( vertex_variables[1].size() == 1 );

    CHECK ( vertex_variables[2].qualifier() == glsl::qualifier::VARYING );
    CHECK ( vertex_variables[2].type() == glsl::type::VEC2 );
    CHECK ( vertex_variables[2].name() == "fs_texcoord" );
    CHECK ( vertex_variables[2].size() == 1 );

    CHECK ( vertex_variables[3].qualifier() == glsl::qualifier::VARYING );
    CHECK ( vertex_variables[3].type() == glsl::type::FLOAT );
    CHECK ( vertex_variables[3].name() == "scale" );
    CHECK ( vertex_variables[3].size() == 1 );
}
