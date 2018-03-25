#include "catch.hpp"

#include "event.h"
#include "event_collector.h"
#include "event_logger.h"
#include "exchange.h"

using namespace shimmer;

static const char* TAGS = "[exchange]";

TEST_CASE ( "Construct an exchange.", TAGS ) {
    typedef exchange<enum event::type, event, shimmer::match_on_type> exchange;

    exchange ex;

    event_collector<event> collector;
    ex.connect ( display_depth_change::type(),      collector );
    ex.connect ( display_resolution_change::type(), collector );

    event_logger<event> logger;
    ex.connect ( display_depth_change::type(),      logger );
    ex.connect ( display_resolution_change::type(), logger );

    ex.send ( display_depth_change ( 8 ) );
    ex.send ( display_resolution_change ( { 640, 480 } ) );

    REQUIRE ( collector.events().size() == 2 );
    REQUIRE ( collector.events()[0]->type() == display_depth_change::type() );
    REQUIRE ( collector.events()[1]->type() ==
              display_resolution_change::type() );

    const display_depth_change& depth_change = *collector.events()[0];
    CHECK ( depth_change.data() == 8 );

    const display_resolution_change& resolution_change = *collector.events()[1];
    CHECK ( resolution_change.data() == dims_2u ( 640, 480 ) );
}
