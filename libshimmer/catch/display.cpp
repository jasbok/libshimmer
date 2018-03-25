// #include "catch.hpp"

// #include "display.h"
// #include "event_logger.h"

// using namespace shimmer;

// const static char* TAGS = "[display]";

// TEST_CASE ( "Construct a display system.", TAGS ) {
//    display display;

//    CHECK ( display.resolution() == dims_2u{ 0, 0 } );
//    CHECK ( display.depth() == 0 );
// }

// TEST_CASE ( "Set the display resolution.", TAGS ) {
//    display display;

//    event_logger<display_resolution_change> parent_logger;
//    event_logger<display_resolution_change> component_logger;

//    parent_logger.add_component ( &display );
//    display.add_component ( &component_logger );

//    display.resolution ( { 320, 240 } );
//    CHECK ( display.resolution() == dims_2u{ 320, 240 } );
//    REQUIRE ( parent_logger.events().size() == 1 );
//    CHECK ( parent_logger.events()[0].data() == dims_2u{ 320, 240 } );
//    CHECK ( component_logger.events().size() == 0 );

//    display.resolution ( { 160, 120 } );
//    display.resolution ( { 640, 480 } );
//    CHECK ( display.resolution() == dims_2u{ 640, 480 } );
//    REQUIRE ( parent_logger.events().size() == 3 );
//    CHECK ( parent_logger.events()[0].data() == dims_2u{ 320, 240 } );
//    CHECK ( parent_logger.events()[1].data() == dims_2u{ 160, 120 } );
//    CHECK ( parent_logger.events()[2].data() == dims_2u{ 640, 480 } );
//    CHECK ( component_logger.events().size() == 0 );
// }

// TEST_CASE ( "Set the display depth.", TAGS ) {
//    display display;

//    event_logger<display_depth_change> parent_logger;
//    event_logger<display_depth_change> component_logger;

//    parent_logger.add_component ( &display );
//    display.add_component ( &component_logger );

//    display.depth ( 16 );
//    CHECK ( display.depth() == 16 );
//    REQUIRE ( parent_logger.events().size() == 1 );
//    CHECK ( parent_logger.events()[0].data() == 16 );
//    CHECK ( component_logger.events().size() == 0 );

//    display.depth ( 8 );
//    display.depth ( 32 );
//    CHECK ( display.depth() == 32 );
//    REQUIRE ( parent_logger.events().size() == 3 );
//    CHECK ( parent_logger.events()[0].data() == 16 );
//    CHECK ( parent_logger.events()[1].data() == 8 );
//    CHECK ( parent_logger.events()[2].data() == 32 );
//    CHECK ( component_logger.events().size() == 0 );
// }
