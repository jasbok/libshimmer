#ifndef LIBSHIMMER_CATCH_CHECK_IMAGE_H
#define LIBSHIMMER_CATCH_CHECK_IMAGE_H

#include "image.h"

#include "catch/catch.hpp"

static void CHECK_EQUAL ( const shimmer::image& a, const shimmer::image& b ) {
    REQUIRE ( a.width() ==  b.width() );
    REQUIRE ( a.height() ==  b.height() );
    REQUIRE ( a.channels() ==  b.channels() );
    REQUIRE ( a.bit_depth() ==  b.bit_depth() );
    REQUIRE ( a.size() ==  b.size() );

    for ( unsigned int i = 0; i < a.size(); i++ ) {
        CHECK ( a.data().get()[i] == b.data().get()[i] );
    }
}

#endif // ifndef LIBSHIMMER_CATCH_CHECK_IMAGE_H
