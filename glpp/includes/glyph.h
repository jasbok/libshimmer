#ifndef GLPP_GLYPH_H
#define GLPP_GLYPH_H

#include "specs.h"

#include <vector>

namespace glpp
{
class glyph_metadata
{
public:
    glyph_metadata( wchar_t          unicode,
                    const dims_2u&   dims,
                    const coords_2i& bearing,
                    const coords_2i& advance );

    glyph_metadata( wchar_t          unicode,
                    const dims_2u&   dims,
                    const coords_2i& bearing,
                    const coords_2i& advance,
                    const coords_2i& vertical_bearing );

    glyph_metadata( glyph_metadata&& move ) = default;

    glyph_metadata( const glyph_metadata& copy ) = default;

    virtual ~glyph_metadata() = default;

    glyph_metadata& operator=( glyph_metadata&& move ) = default;

    glyph_metadata& operator=( const glyph_metadata& copy ) = default;


    unsigned int unicode() const;

    dims_2u      dims() const;

    coords_2i    bearing() const;

    coords_2i    advance() const;

    bool         has_vertical() const;

    coords_2i    vertical_bearing() const;

private:
    wchar_t _unicode;

    dims_2u _dims;

    coords_2i _bearing;

    coords_2i _advance;

    bool _has_vertical;

    coords_2i _vertical_bearing;
};

class glyph
{
public:
    glyph( const glyph_metadata& meta );

    glyph( const glyph_metadata&  meta,
           std::vector<uint8_t>&& data );

    glyph( glyph&& move );

    glyph( const glyph& copy ) = delete;

    virtual ~glyph();

    glyph& operator=( glyph&& move );

    glyph& operator=( const glyph& copy ) = delete;


    glyph_metadata        meta() const;

    std::vector<uint8_t>& data();

private:
    glyph_metadata _meta;

    std::vector<uint8_t> _data;
};
}

#endif // ifndef GLPP_GLYPH_H
