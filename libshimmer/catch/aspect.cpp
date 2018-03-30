#include "catch.hpp"

#include "aspect.h"
#include "event_collector.h"
#include "event_exchange.h"

static const char* TAGS = "[aspect]";

using namespace shimmer;

TEST_CASE ( "Construct an aspect ratio transform system.", TAGS ) {
    event_exchange exchange;
    aspect aspect ( exchange );

    CHECK ( aspect.transform() == dims_2f{ 1.0f, 1.0f } );
}

TEST_CASE ( "Send events to the aspect transform system.", TAGS ) {
    event_exchange exchange;
    aspect aspect ( exchange );

    CHECK ( aspect.transform() == dims_2f{ 1.0f, 1.0f } );

    aspect.send ( display_resolution_change ( { 320, 240 } ) );
    aspect.send ( window_dims_change ( { 320, 240 } ) );
    CHECK ( aspect.transform() == dims_2f{ 1.0f, 1.0f } );

    aspect.send ( aspect_ratio_config ( aspect_ratio::original ) );
    CHECK ( aspect.transform() == dims_2f{ 1.0f, 1.0f } );

    aspect.send ( aspect_ratio_config ( aspect_ratio::stretch ) );
    CHECK ( aspect.transform() == dims_2f{ 1.0f, 1.0f } );

    aspect.send ( aspect_ratio_config ( aspect_ratio::zoom ) );
    CHECK ( aspect.transform() == dims_2f{ 1.0f, 1.0f } );


    aspect.send ( window_dims_change ( { 640, 480 } ) );
    CHECK ( aspect.transform() == dims_2f{ 1.0f, 1.0f } );

    aspect.send ( aspect_ratio_config ( aspect_ratio::original ) );
    CHECK ( aspect.transform() == dims_2f{ 1.0f, 1.0f } );

    aspect.send ( aspect_ratio_config ( aspect_ratio::stretch ) );
    CHECK ( aspect.transform() == dims_2f{ 1.0f, 1.0f } );

    aspect.send ( aspect_ratio_config ( aspect_ratio::zoom ) );
    CHECK ( aspect.transform() == dims_2f{ 1.0f, 1.0f } );


    aspect.send ( window_dims_change ( { 1920, 1080 } ) );
    CHECK ( aspect.transform() == dims_2f{ 1.0f, 4.0f / 3.0f } );

    aspect.send ( aspect_ratio_config ( aspect_ratio::original ) );
    CHECK ( aspect.transform() == dims_2f{ 3.0f / 4.0f, 1.0f } );

    aspect.send ( aspect_ratio_config ( aspect_ratio::stretch ) );
    CHECK ( aspect.transform() == dims_2f{ 1.0f, 1.0f } );

    aspect.send ( aspect_ratio_config ( aspect_ratio::zoom ) );
    CHECK ( aspect.transform() == dims_2f{ 1.0f, 4.0f / 3.0f } );
}

TEST_CASE ( "Send events to connected exchange of the aspect transform system.",
            TAGS ) {
    event_exchange exchange;
    aspect aspect ( exchange );

    CHECK ( aspect.transform() == dims_2f{ 1.0f, 1.0f } );

    exchange.send ( display_resolution_change ( { 320, 240 } ) );
    exchange.send ( window_dims_change ( { 320, 240 } ) );
    CHECK ( aspect.transform() == dims_2f{ 1.0f, 1.0f } );

    exchange.send ( aspect_ratio_config ( aspect_ratio::original ) );
    CHECK ( aspect.transform() == dims_2f{ 1.0f, 1.0f } );

    exchange.send ( aspect_ratio_config ( aspect_ratio::stretch ) );
    CHECK ( aspect.transform() == dims_2f{ 1.0f, 1.0f } );

    exchange.send ( aspect_ratio_config ( aspect_ratio::zoom ) );
    CHECK ( aspect.transform() == dims_2f{ 1.0f, 1.0f } );


    exchange.send ( window_dims_change ( { 640, 480 } ) );
    CHECK ( aspect.transform() == dims_2f{ 1.0f, 1.0f } );

    exchange.send ( aspect_ratio_config ( aspect_ratio::original ) );
    CHECK ( aspect.transform() == dims_2f{ 1.0f, 1.0f } );

    exchange.send ( aspect_ratio_config ( aspect_ratio::stretch ) );
    CHECK ( aspect.transform() == dims_2f{ 1.0f, 1.0f } );

    exchange.send ( aspect_ratio_config ( aspect_ratio::zoom ) );
    CHECK ( aspect.transform() == dims_2f{ 1.0f, 1.0f } );


    exchange.send ( window_dims_change ( { 1920, 1080 } ) );
    CHECK ( aspect.transform() == dims_2f{ 1.0f, 4.0f / 3.0f } );

    exchange.send ( aspect_ratio_config ( aspect_ratio::original ) );
    CHECK ( aspect.transform() == dims_2f{ 3.0f / 4.0f, 1.0f } );

    exchange.send ( aspect_ratio_config ( aspect_ratio::stretch ) );
    CHECK ( aspect.transform() == dims_2f{ 1.0f, 1.0f } );

    exchange.send ( aspect_ratio_config ( aspect_ratio::zoom ) );
    CHECK ( aspect.transform() == dims_2f{ 1.0f, 4.0f / 3.0f } );
}

TEST_CASE ( "Check that aspect transform system sends out transform events.",
            TAGS ) {
    event_exchange  exchange;
    event_collector collector;
    auto&  events = collector.events();
    aspect aspect ( exchange );

    exchange.connect ( aspect_ratio_change::type(), collector );

    exchange.send ( display_resolution_change ( { 320, 240 } ) );
    exchange.send ( window_dims_change ( { 320, 240 } ) );
    REQUIRE ( collector.events().size() == 2 );
    CHECK ( aspect_ratio_change ( { 1.0f, 0.75f } ) == *events[0] );
    CHECK ( aspect_ratio_change ( { 1.0f, 1.0f } ) == *events[1] );

    exchange.send ( aspect_ratio_config ( aspect_ratio::original ) );
    exchange.send ( aspect_ratio_config ( aspect_ratio::stretch ) );
    exchange.send ( aspect_ratio_config ( aspect_ratio::zoom ) );
    REQUIRE ( collector.events().size() == 5 );
    CHECK ( aspect_ratio_change ( { 1.0f, 1.0f } ) == *events[2] );
    CHECK ( aspect_ratio_change ( { 1.0f, 1.0f } ) == *events[3] );
    CHECK ( aspect_ratio_change ( { 1.0f, 1.0f } ) == *events[4] );

    exchange.send ( window_dims_change ( { 640, 480 } ) );
    exchange.send ( aspect_ratio_config ( aspect_ratio::original ) );
    exchange.send ( aspect_ratio_config ( aspect_ratio::stretch ) );
    exchange.send ( aspect_ratio_config ( aspect_ratio::zoom ) );
    REQUIRE ( collector.events().size() == 9 );
    CHECK ( aspect_ratio_change ( { 1.0f, 1.0f } ) == *events[5] );
    CHECK ( aspect_ratio_change ( { 1.0f, 1.0f } ) == *events[6] );
    CHECK ( aspect_ratio_change ( { 1.0f, 1.0f } ) == *events[7] );
    CHECK ( aspect_ratio_change ( { 1.0f, 1.0f } ) == *events[8] );

    exchange.send ( window_dims_change ( { 1920, 1080 } ) );
    exchange.send ( aspect_ratio_config ( aspect_ratio::original ) );
    exchange.send ( aspect_ratio_config ( aspect_ratio::stretch ) );
    exchange.send ( aspect_ratio_config ( aspect_ratio::zoom ) );
    REQUIRE ( collector.events().size() == 13 );
    CHECK ( aspect_ratio_change ( { 1.0f, 4.0f / 3.0f } ) == *events[9] );
    CHECK ( aspect_ratio_change ( { 0.75f, 1.0f } ) == *events[10] );
    CHECK ( aspect_ratio_change ( { 1.0f, 1.0f } ) == *events[11] );
    CHECK ( aspect_ratio_change ( { 1.0f, 4.0f / 3.0f } ) == *events[12] );
}
