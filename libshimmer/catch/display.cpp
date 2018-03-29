#include "catch.hpp"

#include "display.h"
#include "event_collector.h"
#include "event_exchange.h"

using namespace shimmer;

const static char* TAGS = "[display]";

TEST_CASE ( "Construct a display system.", TAGS ) {
    event_exchange exchange;
    display display ( exchange );

    CHECK ( display.resolution() == dims_2u{ 0, 0 } );
    CHECK ( display.depth() == 0 );
}

TEST_CASE ( "Set the display resolution.", TAGS ) {
    event_exchange exchange;
    display display ( exchange );

    event_collector collector;

    exchange.connect ( display_resolution_change::type(), collector );

    display.resolution ( { 320, 240 } );
    display.resolution ( { 160, 120 } );
    display.resolution ( { 640, 480 } );

    CHECK ( display.resolution() == dims_2u{ 640, 480 } );
    REQUIRE ( collector.events().size() == 3 );

    const display_resolution_change res0 ( { 320, 240 } );
    const display_resolution_change res1 ( { 160, 120 } );
    const display_resolution_change res2 ( { 640, 480 } );

    CHECK ( res0 == *collector.events()[0] );
    CHECK ( res1 == *collector.events()[1] );
    CHECK ( res2 == *collector.events()[2] );
}

TEST_CASE ( "Set the display depth.", TAGS ) {
    event_exchange exchange;
    display display ( exchange );

    event_collector collector;

    exchange.connect ( display_depth_change::type(), collector );

    display.depth ( 16 );
    display.depth ( 8 );
    display.depth ( 32 );

    CHECK ( display.depth() == 32 );
    REQUIRE ( collector.events().size() == 3 );

    const display_depth_change depth0 ( 16 );
    const display_depth_change depth1 ( 8 );
    const display_depth_change depth2 ( 32 );

    CHECK ( depth0 == *collector.events()[0] );
    CHECK ( depth1 == *collector.events()[1] );
    CHECK ( depth2 == *collector.events()[2] );
}
