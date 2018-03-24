#include "catch.hpp"

#include "common/dims.h"

typedef common::dims_2<unsigned int> dims_2u;
typedef common::dims_3<unsigned int> dims_3u;

const static char* TAGS = "[dims]";

TEST_CASE ( "Create 2D dimensions.", TAGS ) {
    dims_2u a;
    dims_2u b ( 320, 240 );
    dims_2u c ( b );

    CHECK ( a.width == 0 );
    CHECK ( a.height == 0 );

    CHECK ( b.width == 320 );
    CHECK ( b.height == 240 );

    CHECK ( c.width == 320 );
    CHECK ( c.height == 240 );
}

TEST_CASE ( "Copy 2D dimensions.", TAGS ) {
    dims_2u a ( 0, 0 );
    dims_2u b ( 320, 240 );

    a = b;

    CHECK ( a.width == 320 );
    CHECK ( a.height == 240 );

    CHECK ( b.width == 320 );
    CHECK ( b.height == 240 );
}

TEST_CASE ( "Compare 2D dimensions.", TAGS ) {
    dims_2u a ( 0, 0 );
    dims_2u b ( 320, 240 );
    dims_2u c ( 320, 240 );

    CHECK ( ( a == b ) == false );
    CHECK ( ( a == c ) == false );
    CHECK ( ( b == c ) == true );

    CHECK ( ( a != b ) == true );
    CHECK ( ( a != c ) == true );
    CHECK ( ( b != c ) == false );

    CHECK ( ( a == dims_2u{ 0, 0 } ) == true );
    CHECK ( ( b == dims_2u{ 320, 240 } ) == true );
    CHECK ( ( c == dims_2u{ 320, 240 } ) == true );

    CHECK ( ( a == dims_2u{ 1, 0 } ) == false );
    CHECK ( ( b == dims_2u{ 1, 1 } ) == false );
    CHECK ( ( c == dims_2u{ 1, 1 } ) == false );

    CHECK ( ( a != dims_2u{ 0, 0 } ) == false );
    CHECK ( ( b != dims_2u{ 320, 240 } ) == false );
    CHECK ( ( c != dims_2u{ 320, 240 } ) == false );

    CHECK ( ( a != dims_2u{ 1, 0 } ) == true );
    CHECK ( ( b != dims_2u{ 1, 1 } ) == true );
    CHECK ( ( c != dims_2u{ 1, 1 } ) == true );
}

TEST_CASE ( "Operations on 2D dimensions.", TAGS ) {
    dims_2u a ( 0, 0 );
    dims_2u b ( 320, 240 );
    dims_2u c ( 320, 240 );
    dims_2u d ( 800, 600 );

    CHECK ( ( a + b ) == dims_2u{ 320, 240 } );
    CHECK ( ( b + a ) == dims_2u{ 320, 240 } );
    CHECK ( ( b + c ) == dims_2u{ 640, 480 } );

    CHECK ( ( b - a ) == dims_2u{ 320, 240 } );
    CHECK ( ( b - c ) == dims_2u{ 0, 0 } );
    CHECK ( ( d - b ) == dims_2u{ 480, 360 } );

    CHECK ( ( a * b ) == dims_2u{ 0, 0 } );
    CHECK ( ( b * a ) == dims_2u{ 0, 0 } );
    CHECK ( ( b * d ) == dims_2u{ 256000, 144000 } );

    CHECK ( ( b / d ) == dims_2u { 0, 0 } );
    CHECK ( ( d / b ) == dims_2u { 2, 2 } );

    b += c;
    c += d;
    CHECK ( b == dims_2u{ 640, 480 } );
    CHECK ( c == dims_2u{ 1120, 840 } );
    CHECK ( d == dims_2u{ 800, 600 } );
}

TEST_CASE ( "Create 3D dimensions.", TAGS ) {
    dims_3u a;
    dims_3u b ( 320, 240, 32 );
    dims_3u c ( b );

    CHECK ( a.width == 0 );
    CHECK ( a.height == 0 );
    CHECK ( a.depth == 0 );

    CHECK ( b.width == 320 );
    CHECK ( b.height == 240 );
    CHECK ( b.depth == 32 );

    CHECK ( c.width == 320 );
    CHECK ( c.height == 240 );
    CHECK ( c.depth == 32 );
}

TEST_CASE ( "Copy 3D dimensions.", TAGS ) {
    dims_3u a ( 0, 0, 0 );
    dims_3u b ( 320, 240, 32 );

    a = b;

    CHECK ( a.width == 320 );
    CHECK ( a.height == 240 );
    CHECK ( a.depth == 32 );

    CHECK ( b.width == 320 );
    CHECK ( b.height == 240 );
    CHECK ( b.depth == 32 );
}

TEST_CASE ( "Compare 3D dimensions.", TAGS ) {
    dims_3u a ( 0, 0, 0 );
    dims_3u b ( 320, 240, 32 );
    dims_3u c ( 320, 240, 32 );

    CHECK ( ( a == b ) == false );
    CHECK ( ( a == c ) == false );
    CHECK ( ( b == c ) == true );

    CHECK ( ( a != b ) == true );
    CHECK ( ( a != c ) == true );
    CHECK ( ( b != c ) == false );

    CHECK ( ( a == dims_3u{ 0, 0, 0 } ) == true );
    CHECK ( ( b == dims_3u{ 320, 240, 32 } ) == true );
    CHECK ( ( c == dims_3u{ 320, 240, 32 } ) == true );

    CHECK ( ( a == dims_3u{ 1, 0, 0 } ) == false );
    CHECK ( ( b == dims_3u{ 1, 1, 1 } ) == false );
    CHECK ( ( c == dims_3u{ 1, 1, 1 } ) == false );

    CHECK ( ( a != dims_3u{ 0, 0, 0 } ) == false );
    CHECK ( ( b != dims_3u{ 320, 240, 32 } ) == false );
    CHECK ( ( c != dims_3u{ 320, 240, 32 } ) == false );

    CHECK ( ( a != dims_3u{ 1, 0, 1 } ) == true );
    CHECK ( ( b != dims_3u{ 1, 1, 1 } ) == true );
    CHECK ( ( c != dims_3u{ 1, 1, 1 } ) == true );
}
