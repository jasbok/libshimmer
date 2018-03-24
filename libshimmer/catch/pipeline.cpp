#include "catch/catch.hpp"

#include "pipeline.h"

const static char* TAGS = "[pipeline]";

TEST_CASE (
    "Check that pipeline structure is correctly deserialised from json file.",
    tags )
{
    struct shimmer::pipeline pipeline;

    pipeline.load ( "data/config/pipeline.json" );

    REQUIRE ( pipeline.stages.size() == 1 );

    auto& stage0 = pipeline.stages[0];
    CHECK ( stage0.input == "application" );
    CHECK ( stage0.output == "stage_1_out" );
    CHECK ( stage0.scale == 2.0f );
    REQUIRE ( stage0.passes.size() == 1 );

    auto& pass0 = stage0.passes[0];
    CHECK ( pass0.blend_function == "src_dest_one" );

    auto& shader0 = pass0.shader;
    CHECK ( shader0.vertex   == "vertex.vert" );
    CHECK ( shader0.fragment == "fragment.frag" );

    REQUIRE ( pass0.texture_bindings.size() == 2 );

    auto& texture_binding0 = pass0.texture_bindings[0];
    CHECK ( texture_binding0.texture_id == "application" );
    CHECK ( texture_binding0.variable == "application" );

    auto& texture_binding1 = pass0.texture_bindings[1];
    CHECK ( texture_binding1.texture_id == "image" );
    CHECK ( texture_binding1.variable == "image" );

    REQUIRE ( pass0.uniforms.size() == 2 );

    auto& uniform0 = pass0.uniforms[0];
    CHECK ( uniform0.variable == "var1" );
    CHECK ( uniform0.value == "1.0" );

    auto& uniform1 = pass0.uniforms[1];
    CHECK ( uniform1.variable == "var2" );
    CHECK ( uniform1.value == "2.0" );
}
