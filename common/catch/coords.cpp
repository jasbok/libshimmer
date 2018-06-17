#include "external/catch/catch.hpp"

#include "common/coords.h"

typedef common::coords_2<int> coords_2i;
typedef common::coords_3<int> coords_3i;

const static char* TAGS = "[coords]";

TEST_CASE ( "Create 2D coords.", TAGS ) {
    coords_2i a;
    coords_2i b ( 1, 2 );
    coords_2i c ( b );

    CHECK ( a.x == 0 );
    CHECK ( a.y == 0 );

    CHECK ( b.x == 1 );
    CHECK ( b.y == 2 );

    CHECK ( c.x == 1 );
    CHECK ( c.y == 2 );
}

TEST_CASE ( "Copy 2D coords.", TAGS ) {
    coords_2i a ( 0, 0 );
    coords_2i b ( 1, 2 );

    a = b;

    CHECK ( a.x == 1 );
    CHECK ( a.y == 2 );

    CHECK ( b.x == 1 );
    CHECK ( b.y == 2 );
}

TEST_CASE ( "Compare 2D coords.", TAGS ) {
    coords_2i a ( 0, 0 );
    coords_2i b ( 1, 2 );
    coords_2i c ( 1, 2 );

    CHECK ( ( a == b ) == false );
    CHECK ( ( a == c ) == false );
    CHECK ( ( b == c ) == true );

    CHECK ( ( a != b ) == true );
    CHECK ( ( a != c ) == true );
    CHECK ( ( b != c ) == false );

    CHECK ( ( a == coords_2i{ 0, 0 } ) == true );
    CHECK ( ( b == coords_2i{ 1, 2 } ) == true );
    CHECK ( ( c == coords_2i{ 1, 2 } ) == true );

    CHECK ( ( a == coords_2i{ 1, 0 } ) == false );
    CHECK ( ( b == coords_2i{ 1, 1 } ) == false );
    CHECK ( ( c == coords_2i{ 1, 1 } ) == false );

    CHECK ( ( a != coords_2i{ 0, 0 } ) == false );
    CHECK ( ( b != coords_2i{ 1, 2 } ) == false );
    CHECK ( ( c != coords_2i{ 1, 2 } ) == false );

    CHECK ( ( a != coords_2i{ 1, 0 } ) == true );
    CHECK ( ( b != coords_2i{ 1, 1 } ) == true );
    CHECK ( ( c != coords_2i{ 1, 1 } ) == true );
}

TEST_CASE ( "Operations on 2D coords.", TAGS ) {
    coords_2i a ( 0, 0 );
    coords_2i b ( 1, 2 );
    coords_2i c ( 1, 2 );
    coords_2i d ( 2, 6 );

    CHECK ( ( a + b ) == coords_2i{ 1, 2 } );
    CHECK ( ( b + a ) == coords_2i{ 1, 2 } );
    CHECK ( ( b + c ) == coords_2i{ 2, 4 } );

    CHECK ( ( a - b ) == coords_2i{ -1, -2 } );
    CHECK ( ( b - a ) == coords_2i{ 1, 2 } );
    CHECK ( ( b - c ) == coords_2i{ 0, 0 } );

    CHECK ( ( a * b ) == coords_2i{ 0, 0 } );
    CHECK ( ( b * a ) == coords_2i{ 0, 0 } );
    CHECK ( ( b * c ) == coords_2i{ 1, 4 } );

    CHECK ( ( a / b ) == coords_2i{ 0, 0 } );
    CHECK ( ( b / c ) == coords_2i{ 1, 1 } );
    CHECK ( ( c / b ) == coords_2i{ 1, 1 } );
    CHECK ( ( b / d ) == coords_2i{ 0, 0 } );
    CHECK ( ( c / d ) == coords_2i{ 0, 0 } );
    CHECK ( ( d / b ) == coords_2i{ 2, 3 } );
    CHECK ( ( d / c ) == coords_2i{ 2, 3 } );

    b += c;
    c += d;
    CHECK ( b == coords_2i{ 2, 4 } );
    CHECK ( c == coords_2i{ 3, 8 } );
    CHECK ( d == coords_2i{ 2, 6 } );
}

TEST_CASE ( "Create 3D coords.", TAGS ) {
    coords_3i a;
    coords_3i b ( 1, 2, 3 );
    coords_3i c ( b );

    CHECK ( a.x == 0 );
    CHECK ( a.y == 0 );
    CHECK ( a.z == 0 );

    CHECK ( b.x == 1 );
    CHECK ( b.y == 2 );
    CHECK ( b.z == 3 );

    CHECK ( c.x == 1 );
    CHECK ( c.y == 2 );
    CHECK ( c.z == 3 );
}

TEST_CASE ( "Copy 3D coords.", TAGS ) {
    coords_3i a ( 0, 0, 0 );
    coords_3i b ( 1, 2, 3 );

    a = b;

    CHECK ( a.x == 1 );
    CHECK ( a.y == 2 );
    CHECK ( a.z == 3 );

    CHECK ( b.x == 1 );
    CHECK ( b.y == 2 );
    CHECK ( b.z == 3 );
}

TEST_CASE ( "Compare 3D coords.", TAGS ) {
    coords_3i a ( 0, 0, 0 );
    coords_3i b ( 1, 2, 3 );
    coords_3i c ( 1, 2, 3 );

    CHECK ( ( a == b ) == false );
    CHECK ( ( a == c ) == false );
    CHECK ( ( b == c ) == true );

    CHECK ( ( a != b ) == true );
    CHECK ( ( a != c ) == true );
    CHECK ( ( b != c ) == false );

    CHECK ( ( a == coords_3i{ 0, 0, 0 } ) == true );
    CHECK ( ( b == coords_3i{ 1, 2, 3 } ) == true );
    CHECK ( ( c == coords_3i{ 1, 2, 3 } ) == true );

    CHECK ( ( a == coords_3i{ 1, 0, 0 } ) == false );
    CHECK ( ( b == coords_3i{ 1, 1, 1 } ) == false );
    CHECK ( ( c == coords_3i{ 1, 1, 1 } ) == false );

    CHECK ( ( a != coords_3i{ 0, 0, 0 } ) == false );
    CHECK ( ( b != coords_3i{ 1, 2, 3 } ) == false );
    CHECK ( ( c != coords_3i{ 1, 2, 3 } ) == false );

    CHECK ( ( a != coords_3i{ 1, 0, 1 } ) == true );
    CHECK ( ( b != coords_3i{ 1, 1, 1 } ) == true );
    CHECK ( ( c != coords_3i{ 1, 1, 1 } ) == true );
}
