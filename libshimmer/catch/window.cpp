// #include "catch.hpp"

// #include "event_logger.h"
// #include "window.h"

// using namespace shimmer;

// const static char* TAGS = "[window]";

// TEST_CASE ( "Construct window system.", TAGS ) {
//    window window;

//    CHECK ( window.dimensions() == dims_2u{ 0, 0 } );
//    CHECK ( window.title() == "" );
// }

// TEST_CASE ( "Set window dimensions.", TAGS ) {
//    window  window;
//    dims_2u dims = { 320, 240 };

//    event_logger<window_dims_change> parent_logger ( "parent" );
//    event_logger<window_dims_change> component_logger ( "component" );

//    parent_logger.add_component ( &window );
//    window.add_component ( &component_logger );

//    window.dimensions ( dims );
//    CHECK ( window.dimensions() == dims_2u{ 320, 240 } );
//    REQUIRE ( parent_logger.events().size() == 1 );
//    CHECK ( parent_logger.events()[0].data() == dims_2u{ 320, 240 } );
//    CHECK ( component_logger.events().size() == 0 );

//    window.dimensions ( dims_2u{ 640, 480 } );
//    CHECK ( window.dimensions() == dims_2u{ 640, 480 } );
//    REQUIRE ( parent_logger.events().size() == 2 );
//    CHECK ( parent_logger.events()[1].data() == dims_2u{ 640, 480 } );
//    CHECK ( component_logger.events().size() == 0 );
// }

// TEST_CASE ( "Set window title.", TAGS ) {
//    window window;

//    std::string title = "window 1";

//    event_logger<window_title_change> parent_logger ( "parent" );
//    event_logger<window_title_change> component_logger ( "component" );

//    parent_logger.add_component ( &window );
//    window.add_component ( &component_logger );

//    window.title ( title );
//    CHECK ( window.title() == "window 1" );
//    REQUIRE ( parent_logger.events().size() == 1 );
//    CHECK ( parent_logger.events()[0].data() == "window 1" );
//    CHECK ( component_logger.events().size() == 0 );

//    window.title ( "window 2" );
//    CHECK ( window.title() == "window 2" );
//    REQUIRE ( parent_logger.events().size() == 2 );
//    CHECK ( parent_logger.events()[1].data() == "window 2" );
//    CHECK ( component_logger.events().size() == 0 );
// }
