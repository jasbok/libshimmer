#include "image.h"
#include "png_reader.h"

#include "catch/catch.hpp"

#include <memory>

using namespace shimmer;
using namespace std;

void CHECK_8x9x8_RGB ( image* png ) {
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

void CHECK_8x9x8_RGBA ( image* png ) {
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

TEST_CASE ( "Read a 8x9x8 RGB png image",
            "[png_reader]" )
{
    CHECK_8x9x8_RGB ( png_reader::read ( "data/images/8x9x8_rgb.png" ).get() );
}

TEST_CASE ( "Read a 8x9x8 RGBA png image",
            "[png_reader]" )
{
    CHECK_8x9x8_RGBA ( png_reader::read ( "data/images/8x9x8_rgba.png" ).get() );
}

TEST_CASE (
    "Read a 8x9x8 RGB png image with adam7 interlacing.",
    "[png_reader]" )
{
    CHECK_8x9x8_RGB ( png_reader::read (
                          "data/images/8x9x8_rgb_adam7.png" ).get() );
}

TEST_CASE (
    "Read a 8x9x8 RGBA png image with adam7 interlacing.",
    "[png_reader]" )
{
    CHECK_8x9x8_RGBA ( png_reader::read (
                           "data/images/8x9x8_rgba_adam7.png" ).get() );
}

TEST_CASE (
    "Read an invalid PNG (text file).",
    "[png_reader]" )
{
    CHECK ( png_reader::read ( "data/file_reader/simple.txt" ) == nullptr );
}

TEST_CASE (
    "Read an invalid PNG (jpeg file, rgb).",
    "[png_reader]" )
{
    CHECK ( png_reader::read ( "data/images/8x9x8_rgb.jpeg" ) == nullptr );
}

TEST_CASE (
    "Read an invalid PNG (jpeg file, rgba).",
    "[png_reader]" )
{
    CHECK ( png_reader::read ( "data/images/8x9x8_rgba.jpeg" ) == nullptr );
}

TEST_CASE (
    "Read a png using the low level calls (RGB).",
    "[png_reader]" )
{
    png_reader reader ( "data/images/8x9x8_rgb.png" );
    image img_a ( *reader.header(), nullptr );

    reader.read_data ( &img_a );
    CHECK_8x9x8_RGB ( &img_a );
}

TEST_CASE (
    "Read a png using the low level calls (RGBA).",
    "[png_reader]" )
{
    png_reader reader ( "data/images/8x9x8_rgba.png" );
    image img_a ( *reader.header(), nullptr );

    reader.read_data ( &img_a );
    CHECK_8x9x8_RGBA ( &img_a );
}

TEST_CASE (
    "Read the same png data multiple times into different data locations.",
    "[png_reader]" )
{
    png_reader reader ( "data/images/8x9x8_rgb.png" );
    image img_a ( *reader.header(), nullptr );
    image img_b ( *reader.header(), nullptr );

    CHECK ( reader.read_data ( &img_a ) == true );
    CHECK ( reader.read_data ( &img_b ) == false );
}
