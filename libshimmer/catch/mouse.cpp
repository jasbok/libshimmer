#include "catch.hpp"

#include "mouse.h"

using namespace shimmer;

TEST_CASE ( "Transform mouse coordinates." ) {
    mouse mouse;
    coords_2i coords { 160, 120 };

    mouse.application ( { 320, 240 } ).window ( { 320, 240 } );
    CHECK ( mouse.transform ( coords ) == coords_2i{ 160, 120 } );

    mouse.window ( { 640, 480 } );
    CHECK ( mouse.transform ( coords ) == coords_2i{ 80, 60 } );

    mouse.window ( { 160, 120 } );
    CHECK ( mouse.transform ( coords ) == coords_2i{ 320, 240 } );

    mouse.application ( { 160, 120 } ).window ( { 320, 240 } );
    CHECK ( mouse.transform ( coords ) == coords_2i{ 80, 60 } );

    mouse.application ( { 640, 480 } );
    CHECK ( mouse.transform ( coords ) == coords_2i{ 320, 240 } );
}

TEST_CASE ( "Send events to mouse system." ) {
    mouse mouse;
    coords_2i coords { 160, 120 };

    mouse.send ( application_dims_change ( { 320, 240 } ) );
    mouse.send ( window_dims_change ( { 320, 240 } ) );
    CHECK ( mouse.transform ( coords ) == coords_2i{ 160, 120 } );

    mouse.send ( window_dims_change ( { 640, 480 } ) );
    CHECK ( mouse.transform ( coords ) == coords_2i{ 80, 60 } );

    mouse.send ( window_dims_change ( { 160, 120 } ) );
    CHECK ( mouse.transform ( coords ) == coords_2i{ 320, 240 } );

    mouse.send ( application_dims_change ( { 160, 120 } ) );
    mouse.send ( window_dims_change ( { 320, 240 } ) );
    CHECK ( mouse.transform ( coords ) == coords_2i{ 80, 60 } );

    mouse.send ( application_dims_change ( { 640, 480 } ) );
    CHECK ( mouse.transform ( coords ) == coords_2i{ 320, 240 } );
}
