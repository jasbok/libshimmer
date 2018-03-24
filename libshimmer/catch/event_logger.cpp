#include "catch.hpp"

#include "event_logger.h"

using namespace shimmer;

const static char* TAGS = "[event_logger]";

TEST_CASE ( "Construct an event_logger system.", TAGS ) {
    event_logger<display_resolution_change> logger ( "logger" );

    CHECK ( logger.id() == "logger" );
    CHECK ( logger.logging() == false );
    CHECK ( logger.capturing() == true );
    CHECK ( logger.events().size() == 0 );
}

TEST_CASE ( "Capture events using event_logger system.", TAGS ) {
    event_logger<display_resolution_change> logger ( "logger" );

    logger.send ( display_resolution_change ( dims_2u{ 320, 240 } ) );
    CHECK ( logger.events().size() == 1 );
    CHECK ( logger.events()[0].data() == dims_2u{ 320, 240 } );

    logger.send ( display_resolution_change ( dims_2u{ 160, 120 } ) );
    logger.send ( display_resolution_change ( dims_2u{ 640, 480 } ) );
    CHECK ( logger.events().size() == 3 );
    CHECK ( logger.events()[0].data() == dims_2u{ 320, 240 } );
    CHECK ( logger.events()[1].data() == dims_2u{ 160, 120 } );
    CHECK ( logger.events()[2].data() == dims_2u{ 640, 480 } );
}
