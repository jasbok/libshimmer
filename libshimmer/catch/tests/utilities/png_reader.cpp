#include "image.h"
#include "png_reader.h"

#include "catch/catch.hpp"

#include <memory>

using namespace shimmer;
using namespace std;

void CHECK_8x9x8_RGB ( const shared_ptr<image>& png ) {
    unsigned int expected_width     = 8;
    unsigned int expected_height    = 9;
    unsigned int expected_channels  = 3;
    unsigned int expected_bit_depth = 8;
    unsigned int expected_step      = expected_width * expected_channels *
                                      expected_bit_depth * 0.125;
    unsigned int expected_size = expected_height * expected_step;

    REQUIRE ( png->width() == expected_width );
    REQUIRE ( png->height() == expected_height );
    REQUIRE ( png->channels() == expected_channels );
    REQUIRE ( png->bit_depth() == expected_bit_depth );
    REQUIRE ( png->step() ==  expected_step );
    REQUIRE ( png->size() ==  expected_size );

    for ( unsigned int row = 0; row < png->height(); row++ ) {
        int r_expected = row % 3 == 0 ? 255 : 0;
        int g_expected = row % 3 == 1 ? 255 : 0;
        int b_expected = row % 3 == 2 ? 255 : 0;

        for ( unsigned int col = 0; col < png->width(); col++ ) {
            int r = png->rows()[row][col * expected_channels + 0];
            int g = png->rows()[row][col * expected_channels + 1];
            int b = png->rows()[row][col * expected_channels + 2];

            CHECK ( r == r_expected );
            CHECK ( g == g_expected );
            CHECK ( b == b_expected );
        }
    }
}

void CHECK_8x9x8_RGBA ( const shared_ptr<image>& png ) {
    unsigned int expected_width     = 8;
    unsigned int expected_height    = 9;
    unsigned int expected_channels  = 4;
    unsigned int expected_bit_depth = 8;
    unsigned int expected_step      = expected_width * expected_channels *
                                      expected_bit_depth * 0.125;
    unsigned int expected_size = expected_height * expected_step;

    REQUIRE ( png->width() == expected_width );
    REQUIRE ( png->height() == expected_height );
    REQUIRE ( png->channels() == expected_channels );
    REQUIRE ( png->bit_depth() == expected_bit_depth );
    REQUIRE ( png->step() ==  expected_step );
    REQUIRE ( png->size() ==  expected_size );

    for ( unsigned int row = 0; row < png->height(); row++ ) {
        int r_expected = row % 3 == 0 ? 255 : 0;
        int g_expected = row % 3 == 1 ? 255 : 0;
        int b_expected = row % 3 == 2 ? 255 : 0;
        int a_expected = 255;

        for ( unsigned int col = 0; col < png->width(); col++ ) {
            int r = png->rows()[row][col * expected_channels + 0];
            int g = png->rows()[row][col * expected_channels + 1];
            int b = png->rows()[row][col * expected_channels + 2];
            int a = png->rows()[row][col * expected_channels + 3];

            CHECK ( r == r_expected );
            CHECK ( g == g_expected );
            CHECK ( b == b_expected );
            CHECK ( a == a_expected );
        }
    }
}

TEST_CASE ( "Read a 8x9x8 RGB png image, normal method.",
            "[png_reader]" )
{
    png_reader reader;
    auto png = reader.read ( "data/images/8x9x8_rgb.png", false );

    CHECK_8x9x8_RGB ( png );
}

TEST_CASE ( "Read a 8x9x8 RGB png image, fast method.",
            "[png_reader]" )
{
    png_reader reader;
    auto png = reader.read ( "data/images/8x9x8_rgb.png", true );

    CHECK_8x9x8_RGB ( png );
}

TEST_CASE ( "Read a 8x9x8 RGBA png image, normal method.",
            "[png_reader]" )
{
    png_reader reader;
    auto png = reader.read ( "data/images/8x9x8_rgba.png", false );

    CHECK_8x9x8_RGB ( png );
}

TEST_CASE ( "Read a 8x9x8 RGBA png image, fast method.",
            "[png_reader]" )
{
    png_reader reader;
    auto png = reader.read ( "data/images/8x9x8_rgba.png", true );

    CHECK_8x9x8_RGB ( png );
}

TEST_CASE (
    "Read a 8x9x8 RGB png image with adam7 interlacing, normal method.",
    "[png_reader]" )
{
    png_reader reader;
    auto png = reader.read ( "data/images/8x9x8_rgb_adam7.png", false );

    CHECK_8x9x8_RGB ( png );
}

TEST_CASE ( "Read a 8x9x8 RGB png image with adam7 interlacing, fast method.",
            "[png_reader]" )
{
    png_reader reader;
    auto png = reader.read ( "data/images/8x9x8_rgb_adam7.png", true );

    CHECK_8x9x8_RGB ( png );
}

TEST_CASE (
    "Read a 8x9x8 RGBA png image with adam7 interlacing, normal method.",
    "[png_reader]" )
{
    png_reader reader;
    auto png = reader.read ( "data/images/8x9x8_rgba_adam7.png", false );

    CHECK_8x9x8_RGB ( png );
}

TEST_CASE (
    "Read a 8x9x8 RGBA png image with adam7 interlacing, fast method.",
    "[png_reader]" )
{
    png_reader reader;
    auto png = reader.read ( "data/images/8x9x8_rgba_adam7.png", true );

    CHECK_8x9x8_RGB ( png );
}

TEST_CASE (
    "Read an invalid PNG (text file), normal method.",
    "[png_reader]" )
{
    png_reader reader;
    auto png = reader.read ( "data/file_reader/simple.txt", false );

    CHECK ( png == nullptr );
}

TEST_CASE (
    "Read an invalid PNG (text file), fast method.",
    "[png_reader]" )
{
    png_reader reader;
    auto png = reader.read ( "data/file_reader/simple.txt", true );

    CHECK ( png == nullptr );
}

TEST_CASE (
    "Read an invalid PNG (jpeg file, rgb), normal method.",
    "[png_reader]" )
{
    png_reader reader;
    auto png = reader.read ( "data/images/8x9x8_rgb.jpeg", false );

    CHECK ( png == nullptr );
}

TEST_CASE (
    "Read an invalid PNG (jpeg file,  rgb), fast method.",
    "[png_reader]" )
{
    png_reader reader;
    auto png = reader.read ( "data/images/8x9x8_rgb.jpeg", true );

    CHECK ( png == nullptr );
}

TEST_CASE (
    "Read an invalid PNG (jpeg file, rgba), normal method.",
    "[png_reader]" )
{
    png_reader reader;
    auto png = reader.read ( "data/images/8x9x8_rgba.jpeg", false );

    CHECK ( png == nullptr );
}

TEST_CASE (
    "Read an invalid PNG (jpeg file,  rgba), fast method.",
    "[png_reader]" )
{
    png_reader reader;
    auto png = reader.read ( "data/images/8x9x8_rgba.jpeg", true );

    CHECK ( png == nullptr );
}
