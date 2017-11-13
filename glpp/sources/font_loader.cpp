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

vector<glyph> font_loader::load ( const font_spec& font,
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

std::vector<glyph> font_loader::load ( const std::vector<font_spec>& fonts,
                                       unsigned int                  dpi )
{
    std::vector<glyph> results;

    for ( const auto& font : fonts ) {
        auto glyphs = load ( font, dpi );
        std::move ( glyphs.begin(), glyphs.end(), back_inserter ( results ) );
    }

    return results;
}

std::vector<glyph> font_loader::_convert_to_glyphs ( const font_face& face )
{
    std::vector<glyph> glyphs;

    for ( auto range : face.font().unicodes() ) {
        for ( unsigned int c = range.start; c < range.end; c++ ) {
            try {
                auto glyph = face.get_glyph ( c );
                auto dims  = glyph.meta().dims();

                if ( ( dims.width > 0 ) && ( dims.height > 0 ) ) {
                    glyphs.push_back ( std::move ( glyph ) );
                }
            }
            catch ( const exception& ex ) {}
        }
    }


    return glyphs;
}
