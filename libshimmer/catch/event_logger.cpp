#include "catch.hpp"

#include "event_logger.h"

using namespace shimmer;

TEST_CASE ( "Construct an event_logger system." ) {
    event_logger<application_dims_change> logger ( "logger" );

    CHECK ( logger.id() == "logger" );
    CHECK ( logger.logging() == false );
    CHECK ( logger.capturing() == false );
    CHECK ( logger.events().size() == 0 );
}

TEST_CASE ( "Capture events using event_logger system." ) {
    event_logger<application_dims_change> logger ( "logger" );

    logger.capturing ( true );
    CHECK ( logger.capturing() == true );

    logger.send ( application_dims_change ( dims_2u{ 320, 240 } ) );
    CHECK ( logger.events().size() == 1 );
    CHECK ( logger.events()[0].data() == dims_2u{ 320, 240 } );

    logger.send ( application_dims_change ( dims_2u{ 160, 120 } ) );
    logger.send ( application_dims_change ( dims_2u{ 640, 480 } ) );
    CHECK ( logger.events().size() == 3 );
    CHECK ( logger.events()[0].data() == dims_2u{ 320, 240 } );
    CHECK ( logger.events()[1].data() == dims_2u{ 160, 120 } );
    CHECK ( logger.events()[2].data() == dims_2u{ 640, 480 } );
}
