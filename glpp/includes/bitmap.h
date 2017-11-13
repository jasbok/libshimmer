#ifndef GLPP_BITMAP_H
#define GLPP_BITMAP_H

#include "specs.h"

#include <vector>

namespace glpp{
struct bitmap
{
    bitmap() = default;

    bitmap( const dims_2u& dims );

    bitmap( bitmap&& move );

    bitmap( const bitmap& copy ) = delete;

    bitmap& operator=( bitmap&& move );

    bitmap& operator=( const bitmap& copy ) = delete;


    dims_2u dims;

    std::vector<uint8_t> data;
};
}

#endif
