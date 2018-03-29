#include "catch.hpp"

#include "event_collector.h"
#include "event_exchange.h"
#include "exchange.h"

using namespace shimmer;

static const char* TAGS = "[exchange]";

TEST_CASE ( "Construct an exchange.", TAGS ) {
    event_exchange exchange;

    event_collector collector;

    exchange.connect ( display_depth_change::type(),      collector );
    exchange.connect ( display_resolution_change::type(), collector );

    exchange.send ( display_depth_change ( 8 ) );
    exchange.send ( display_resolution_change ( { 640, 480 } ) );

    REQUIRE ( collector.events().size() == 2 );
    REQUIRE ( collector.events()[0]->type() == display_depth_change::type() );
    REQUIRE ( collector.events()[1]->type() ==
              display_resolution_change::type() );

    const display_depth_change& depth_change = *collector.events()[0];
    CHECK ( depth_change.data() == 8 );

    const display_resolution_change& resolution_change = *collector.events()[1];
    CHECK ( resolution_change.data() == dims_2u ( 640, 480 ) );
}
