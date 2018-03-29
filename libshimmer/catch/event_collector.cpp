#include "catch.hpp"

#include "event_collector.h"
#include "event_exchange.h"

using namespace shimmer;

const static char* TAGS = "[event_collector]";

TEST_CASE ( "Construct an event_collector.", TAGS ) {
    event_collector collector;

    CHECK ( collector.events().size() == 0 );
}

TEST_CASE ( "Capture events using event_collector.", TAGS ) {
    event_exchange  exchange;
    event_collector collector;

    exchange.connect ( window_title_change::type(), collector );

    REQUIRE ( collector.events().size() == 0 );

    exchange.send ( window_title_change ( "event0" ) );
    exchange.send ( window_dims_change ( { 0, 0 } ) );

    REQUIRE ( collector.events().size() == 1 );
    REQUIRE ( window_title_change ( "event0" ) == *collector.events()[0] );

    exchange.connect ( window_dims_change::type(), collector );

    exchange.send ( window_title_change ( "event1" ) );
    exchange.send ( window_dims_change ( { 320, 240 } ) );

    REQUIRE ( collector.events().size() == 3 );
    REQUIRE ( window_title_change ( "event0" ) == *collector.events()[0] );
    REQUIRE ( window_title_change ( "event1" ) == *collector.events()[1] );
    REQUIRE ( window_dims_change ( { 320, 240 } ) == *collector.events()[2] );
}
