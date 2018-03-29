#include "catch.hpp"

#include "event_collector.h"
#include "event_exchange.h"
#include "window.h"

using namespace shimmer;

const static char* TAGS = "[window]";

TEST_CASE ( "Construct window system.", TAGS ) {
    event_exchange exchange;
    window window ( exchange );

    CHECK ( window.dimensions() == dims_2u{ 0, 0 } );
    CHECK ( window.title() == "" );
}

TEST_CASE ( "Set window dimensions.", TAGS ) {
    event_exchange  exchange;
    event_collector collector;

    exchange.connect ( window_dims_change::type(), collector );

    window  window ( exchange );
    dims_2u dims = { 320, 240 };

    window.dimensions ( dims );
    CHECK ( window.dimensions() == dims_2u{ 320, 240 } );
    REQUIRE ( collector.events().size() == 1 );
    CHECK ( window_dims_change ( dims ) == *collector.events()[0] );

    window.dimensions ( dims_2u{ 640, 480 } );
    CHECK ( window.dimensions() == dims_2u{ 640, 480 } );
    REQUIRE ( collector.events().size() == 2 );
    CHECK ( window_dims_change ( dims ) == *collector.events()[0] );
    CHECK ( window_dims_change ( { 640, 480 } ) == *collector.events()[1] );
}

TEST_CASE ( "Set window title.", TAGS ) {
    event_exchange  exchange;
    event_collector collector;

    exchange.connect ( window_title_change::type(), collector );

    window window ( exchange );

    std::string title = "window 1";

    window.title ( title );
    CHECK ( window.title() == "window 1" );
    REQUIRE ( collector.events().size() == 1 );
    CHECK ( window_title_change ( title ) == *collector.events()[0] );

    window.title ( "window 2" );
    CHECK ( window.title() == "window 2" );
    REQUIRE ( collector.events().size() == 2 );
    CHECK ( window_title_change ( title ) == *collector.events()[0] );
    CHECK ( window_title_change ( "window 2" ) == *collector.events()[1] );
}
