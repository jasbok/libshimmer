#include "external/catch/catch.hpp"

#include "common/series.h"

static const char* TAGS = "[series]";

TEST_CASE ( "Generate a series of values.", TAGS ) {
    CHECK ( common::series::sequential<unsigned int>( 1, 10, 1 )
            == std::vector<unsigned int>{ 1, 2, 3, 4, 5, 6, 7, 8, 9 } );

    CHECK ( common::series::sequential<float>( 1.0f,
                                               4.0f,
                                               0.5f )
            == std::vector<float>{ 1.0f, 1.5f, 2.0f, 2.5f, 3.0f, 3.5f } );
}

TEST_CASE ( "Transform a series of values.", TAGS ) {
    auto series_a    = common::series::sequential<int>( 1, 10, 2 );
    auto transform_a = common::series::transform ( series_a, -5, 2 );

    auto series_b    = common::series::sequential<float>( -1.0f, 1.25f, 0.25f );
    auto transform_b = common::series::transform ( series_b, 0.5f, 0.5f );

    CHECK ( transform_a
            == std::vector<int>{ -3, 1, 5, 9, 13 } );

    CHECK ( transform_b
            == std::vector<float>{ 0.0f, 0.125f, 0.25f, 0.375f, 0.5f, 0.625f,
                                   0.75f, 0.875f, 1.0f } );
}
