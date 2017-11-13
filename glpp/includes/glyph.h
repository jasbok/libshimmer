#ifndef GLPP_GLYPH_H
#define GLPP_GLYPH_H

#include "bitmap.h"

#include <vector>

namespace glpp
{
struct glyph_meta
{
    wchar_t unicode;

    std::string group;

    dims_2u dims;

    coords_2i bearing;

    coords_2i advance;

    bool has_vertical;

    coords_2i vertical_bearing;
};

struct glyph_pack
{
    glyph_pack() = default;

    glyph_pack( glyph_pack&& move ) = default;

    glyph_pack( const glyph_pack& copy ) = delete;

    glyph_pack& operator=( glyph_pack&& move ) = default;

    glyph_pack& operator=( const glyph_pack& copy ) = delete;


    std::vector<struct glyph_meta> metas;

    std::vector<struct bitmap> bitmaps;
};

struct glyph {
    glyph( glyph&& move ) = default;

    glyph( const glyph& copy ) = delete;

    glyph& operator=( glyph&& move ) = default;

    glyph& operator=( const glyph& copy ) = delete;


    struct glyph_meta meta;

    struct bitmap bitmap;
};
}

#endif // ifndef GLPP_GLYPH_H
