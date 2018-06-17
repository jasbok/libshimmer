#ifndef COMMON_FONTS_H
#define COMMON_FONTS_H

#include "coords.h"
#include "img.h"
#include "unicodes.h"

namespace common::fonts
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
    std::vector<struct glyph_meta> metas;

    std::vector<img::image> bitmaps;
};

struct glyph {
    struct glyph_meta meta;

    img::image bitmap;
};

class spec
{
public:
    typedef std::vector<range_uint> unicode_ranges;

    spec() = delete;

    spec( const std::string&      id,
          const std::string&      path,
          unsigned int            size,
          std::vector<range_uint> unicodes );

    spec( spec&& move ) = default;

    spec( const spec& copy ) = default;

    virtual ~spec() = default;

    spec& operator=( spec&& move ) = default;

    spec& operator=( const spec& copy ) = default;


    spec&          id ( const std::string& id );

    std::string    id() const;

    spec&          path ( const std::string& path );

    std::string    path() const;

    spec&          size ( unsigned int size );

    unsigned int   size() const;

    spec&          unicodes ( const unicode_ranges& unicodes );

    unicode_ranges unicodes() const;

private:
    std::string _id;

    std::string _path;

    unsigned int _size;

    std::vector<range_uint> _unicodes;
};

glyph_pack load ( const std::vector<spec>& fonts,
                  unsigned int             dpi = 72 );
}

#endif // ifndef COMMON_FONTS_H
