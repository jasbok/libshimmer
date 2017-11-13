#include "font_loader.h"

#include <cstring>
#include <iostream>
#include <iterator>

using namespace glpp;
using namespace std;

font_loader::font_loader( const vector<string>& paths )
    : _search_paths { "." }
{
    _search_paths.insert ( _search_paths.end(), paths.begin(), paths.end() );
}

font_loader::~font_loader() {}

glyph_pack font_loader::load ( const font_spec& font,
                               unsigned int     dpi )
{
    ft_wrapper ft;

    for ( const auto& search_path : _search_paths ) {
        try {
            font_spec curr = font;
            curr.path ( search_path + "/" + font.path() );

            return _convert_to_glyphs ( font_face ( ft, curr, dpi ) );
        }
        catch ( const exception& ex ) {
            cerr << "Unable to load font, checking search path... "
                 << "(" << font.path() << "): "
                 << ex.what() << std::endl;
        }
    }

    throw font_not_found_exception();
}

glyph_pack font_loader::load ( const std::vector<font_spec>& fonts,
                               unsigned int                  dpi )
{
    glyph_pack pack;

    for ( const auto& font : fonts ) {
        auto data = load ( font, dpi );
        std::move ( data.bitmaps.begin(), data.bitmaps.end(),
                    back_inserter ( pack.bitmaps ) );
        std::move ( data.metas.begin(), data.metas.end(),
                    back_inserter ( pack.metas ) );
    }

    return pack;
}

glyph_pack font_loader::_convert_to_glyphs ( const font_face& face )
{
    glyph_pack pack;

    for ( auto range : face.font().unicodes() ) {
        for ( unsigned int c = range.start; c < range.end; c++ ) {
            try {
                auto glyph = face.get_glyph ( c );
                auto dims  = glyph.meta.dims;

                if ( glyph.meta.dims.area() > 0 ) {
                    pack.metas.push_back ( std::move ( glyph.meta ) );
                    pack.bitmaps.push_back ( std::move ( glyph.bitmap ) );
                }
            }
            catch ( const exception& ex ) {}
        }
    }


    return pack;
}
