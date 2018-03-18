#include "font_loader.h"

#include "ft_wrapper.h"

#include <cstring>
#include <iostream>
#include <iterator>

using namespace glpp;
using namespace std;

glyph_pack _convert_to_glyphs ( const ft_wrapper&                ft,
                                const font_spec::unicode_ranges& unicodes )
{
    glyph_pack pack;

    for ( auto range : unicodes ) {
        for ( unsigned int c = range.start; c < range.end; c++ ) {
            try {
                auto glyph = ft.get_glyph ( c );
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

font_loader::font_loader( const vector<string>& paths )
    : _search_paths { "." }
{
    _search_paths.insert ( _search_paths.end(), paths.begin(), paths.end() );
}

font_loader::~font_loader() {}


struct font_loader_font_not_found_exception : public std::exception {
    const char* what() const throw( ) {
        return "Could not find the specified font.";
    }
};

glyph_pack font_loader::load ( const font_spec& font,
                               unsigned int     dpi )
{
    ft_wrapper ft;

    for ( const auto& search_path : _search_paths ) {
        try {
            font_spec curr = font;
            curr.path ( search_path + "/" + font.path() );

            ft.load_face ( curr.path(), curr.size(), dpi );

            return _convert_to_glyphs ( ft, font.unicodes() );
        }
        catch ( const exception& ex ) {
            //             cerr << "Unable to load font, checking search path...
            // "
            //                  << "(" << font.path() << "): "
            //                  << ex.what() << std::endl;
        }
    }

    throw font_loader_font_not_found_exception();
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
