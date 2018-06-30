#ifndef LIBSHIMMER_CATCH_CHECK_IMAGE_H
#define LIBSHIMMER_CATCH_CHECK_IMAGE_H

#include "check_data.h"
#include "image.h"

#include "catch/catch.hpp"

static void CHECK_EQUAL ( const shimmer::image& a, const shimmer::image& b ) {
    REQUIRE ( a.width() == b.width() );
    REQUIRE ( a.height() == b.height() );
    REQUIRE ( a.channels() == b.channels() );
    REQUIRE ( a.bit_depth() == b.bit_depth() );
    REQUIRE ( a.size() == b.size() );
    CHECK_EQUAL ( a.data().get(), b.data().get(), a.size() );
}

#endif // ifndef LIBSHIMMER_CATCH_CHECK_IMAGE_H
