#include "catch/catch.hpp"

#include "img.h"

static const char* TAGS = "[img]";

TEST_CASE ( "Read the contents of a png file into an image data structure.",
            TAGS ) {
    using namespace common::img;
    using namespace std;

    auto image = read ( "data/image/test.png" );

    REQUIRE ( image.data != nullptr );
    REQUIRE ( image.dims.width == 32 );
    REQUIRE ( image.dims.height == 30 );
    REQUIRE ( image.channels == 4 );

    for ( unsigned int j = 0; j < image.dims.height; j++ ) {
        unsigned int row = j * image.dims.width  * image.channels;

        for ( unsigned int i = 0; i < image.dims.width; i++ ) {
            unsigned int column = i * image.channels;

            for ( unsigned int c = 0; c < image.channels; c++ ) {
                const auto& value = image.data.get()[row + column + c];

                if ( c == 3 ) {
                    // Alpha is always opaque.
                    CHECK ( value == 255 );
                }

                else if ( i < 30 ) {
                    auto rgb_index = ( i / 2 ) % 3;

                    if ( rgb_index == c ) {
                        CHECK ( value == 255 );
                    }
                    else {
                        CHECK ( value == 0 );
                    }
                }
                else {
                    // Right black border.
                    CHECK ( value == 0 );
                }
            }
        }
    }
}

TEST_CASE ( "Read the contents of a jpg file into an image data structure.",
            TAGS ) {
    using namespace common::img;
    using namespace std;

    auto image = read ( "data/image/test.jpg" );

    REQUIRE ( image.data != nullptr );
    REQUIRE ( image.dims.width == 32 );
    REQUIRE ( image.dims.height == 30 );
    REQUIRE ( image.channels == 3 );

    // Note compression slightly changes original values.
    for ( unsigned int j = 0; j < image.dims.height; j++ ) {
        unsigned int row = j * image.dims.width  * image.channels;

        for ( unsigned int i = 0; i < image.dims.width; i++ ) {
            unsigned int column = i * image.channels;

            for ( unsigned int c = 0; c < image.channels; c++ ) {
                const auto& value = image.data.get()[row + column + c];

                if ( i < 30 ) {
                    auto rgb_index = ( i / 2 ) % 3;

                    if ( rgb_index == c ) {
                        CHECK ( value >= 250 );
                    }
                    else {
                        CHECK ( value <= 4 );
                    }
                }
                else {
                    // Right black border.
                    CHECK ( value <= 4 );
                }
            }
        }
    }
}

TEST_CASE (
    "Read the contents of a non-existing file into an image data structure.",
    TAGS ) {
    using namespace common::img;

    CHECK_THROWS_AS ( read ( "does_not_exist.png" ), read_exception );

    CHECK_THROWS_WITH ( read ( "does_not_exist.png" ),
                        Catch::Matchers::Contains ( "does_not_exist.png" ) );
}
