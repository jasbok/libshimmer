#ifndef LIBSHIMMER_CATCH_CHECK_DATA_H
#define LIBSHIMMER_CATCH_CHECK_DATA_H

#include "catch/catch.hpp"

static void CHECK_EQUAL ( void* a, void* b, int size ) {
    auto data_a = ( uint8_t* )a;
    auto data_b = ( uint8_t* )b;

    for ( unsigned int i = 0; i < size; i++ ) {
        CHECK ( data_a[i] == data_b[i] );
    }
}

#endif // ifndef LIBSHIMMER_CATCH_CHECK_DATA_H
