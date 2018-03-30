#include "catch.hpp"

#include "event_exchange.h"
#include "mouse.h"

using namespace shimmer;

const static char* TAGS = "[mouse]";

TEST_CASE ( "Transform mouse coordinates.", TAGS ) {
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

TEST_CASE ( "Send events to mouse system.", TAGS ) {
    mouse mouse;
    coords_2i coords { 160, 120 };

    mouse.send ( display_resolution_change ( { 320, 240 } ) );
    mouse.send ( window_dims_change ( { 320, 240 } ) );
    CHECK ( mouse.transform ( coords ) == coords_2i{ 160, 120 } );

    mouse.send ( window_dims_change ( { 640, 480 } ) );
    CHECK ( mouse.transform ( coords ) == coords_2i{ 80, 60 } );

    mouse.send ( window_dims_change ( { 160, 120 } ) );
    CHECK ( mouse.transform ( coords ) == coords_2i{ 320, 240 } );

    mouse.send ( display_resolution_change ( { 160, 120 } ) );
    mouse.send ( window_dims_change ( { 320, 240 } ) );
    CHECK ( mouse.transform ( coords ) == coords_2i{ 80, 60 } );

    mouse.send ( display_resolution_change ( { 640, 480 } ) );
    CHECK ( mouse.transform ( coords ) == coords_2i{ 320, 240 } );
}

TEST_CASE ( "Connect the mouse system to an events connector.", TAGS ) {
    event_exchange exchange;
    mouse mouse ( exchange );
    coords_2i coords { 160, 120 };

    exchange.send ( display_resolution_change ( { 320, 240 } ) );
    exchange.send ( window_dims_change ( { 320, 240 } ) );
    CHECK ( mouse.transform ( coords ) == coords_2i{ 160, 120 } );

    exchange.send ( window_dims_change ( { 640, 480 } ) );
    CHECK ( mouse.transform ( coords ) == coords_2i{ 80, 60 } );

    exchange.send ( window_dims_change ( { 160, 120 } ) );
    CHECK ( mouse.transform ( coords ) == coords_2i{ 320, 240 } );

    exchange.send ( display_resolution_change ( { 160, 120 } ) );
    exchange.send ( window_dims_change ( { 320, 240 } ) );
    CHECK ( mouse.transform ( coords ) == coords_2i{ 80, 60 } );

    exchange.send ( display_resolution_change ( { 640, 480 } ) );
    CHECK ( mouse.transform ( coords ) == coords_2i{ 320, 240 } );
}
