#include "fonts.h"

#include "freetype.h"

namespace common::fonts
{
spec::spec( const std::string&      id,
            const std::string&      path,
            unsigned int            size,
            std::vector<range_uint> unicodes )
    : _id ( id ),
      _path ( path ),
      _size ( size ),
      _unicodes ( unicodes )
{}

spec& spec::path ( const std::string& path )
{
    _path = path;

    return *this;
}

std::string spec::path() const
{
    return _path;
}

spec& spec::id ( const std::string& id )
{
    _id = id;

    return *this;
}

std::string spec::id() const
{
    return _id;
}

spec& spec::size ( unsigned int size )
{
    _size = size;

    return *this;
}

unsigned int spec::size() const
{
    return _size;
}

spec& spec::unicodes ( const unicode_ranges& unicodes )
{
    _unicodes = unicodes;

    return *this;
}

spec::unicode_ranges spec::unicodes() const
{
    return _unicodes;
}

glyph_pack _convert_to_glyphs ( const freetype&             ft,
                                const spec::unicode_ranges& unicodes )
{
    glyph_pack pack;

    for ( auto range : unicodes ) {
        for ( unsigned int c = range.start; c < range.end; c++ ) {
            try {
                auto glyph = ft.unicode ( static_cast<wchar_t>( c ) );
                auto dims  = glyph.meta.dims;

                if ( glyph.meta.dims.area() > 0 ) {
                    pack.metas.push_back ( std::move ( glyph.meta ) );
                    pack.bitmaps.push_back ( std::move ( glyph.bitmap ) );
                }
            }
            catch ( const std::exception& ) {}
        }
    }


    return pack;
}

glyph_pack load ( const std::vector<spec>& fonts,
                  unsigned int             dpi )
{
    freetype   ft;
    glyph_pack pack;

    for ( const auto& font : fonts ) {
        ft.load ( font.path(), font.size(), dpi );
        auto data = _convert_to_glyphs ( ft, font.unicodes() );
        std::move ( data.bitmaps.begin(), data.bitmaps.end(),
                    back_inserter ( pack.bitmaps ) );
        std::move ( data.metas.begin(), data.metas.end(),
                    back_inserter ( pack.metas ) );
    }

    return pack;
}
}
