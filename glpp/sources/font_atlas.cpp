#include "font_atlas.h"

#include <algorithm>
#include <cmath>

using namespace glpp;
using namespace std;

atlas_glyph::atlas_glyph( const glyph_metadata& meta,
                          const coords_2u&      atlas_coords )
    : glyph_metadata ( meta ),
      _atlas_coords ( atlas_coords )
{}

coords_2u atlas_glyph::atlas_coords()
{
    return _atlas_coords;
}

font_atlas::font_atlas( std::vector<glyph>&& glyphs )
    : _atlas_glyphs(), _texture ( texture::internal_format::red )
{}

font_atlas::~font_atlas() {}

texture_2d& font_atlas::texture()
{
    return _texture;
}

std::vector<atlas_glyph>& font_atlas::glyphs()
{
    return _atlas_glyphs;
}

unsigned int font_atlas::_upper_pow2 ( unsigned int i )
{
    // http://graphics.stanford.edu/~seander/bithacks.html#RoundUpPowerOf2
    i--;
    i |= i >> 1;
    i |= i >> 2;
    i |= i >> 4;
    i |= i >> 8;
    i |= i >> 16;

    return ++i;
}

void font_atlas::_get_atlas_glyphs ( std::vector<glyph>& glyphs )
{
    std::sort ( glyphs.begin(), glyphs.end(), [] ( auto& a, auto& b ) {
        return a.meta().dims().area() > b.meta().dims().area();
    } );

    unsigned int area = 0;

    for ( const auto& glyph : glyphs ) {
        area += glyph.meta().dims().area();
    }

    auto side = _upper_pow2 ( static_cast<unsigned int>(sqrt ( area )) );
    area = side * side;

    for (; _atlas_glyphs.empty(); side *= 2, area = side * side ) {
        std::vector<bool> used ( area );

        for ( const auto& glyph : glyphs ) {
            auto dims   = glyph.meta().dims();
            bool placed = false;

            for ( unsigned int y = 0; y < side; y++ ) {
                if ( y + dims.height >= side ) break;

                unsigned int top    = y * side;
                unsigned int bottom = (y + dims.height - 1) * side;

                for ( unsigned int x = 0; x < side; x++ ) {
                    if ( x + dims.width >= side ) break;

                    unsigned int tl = top + x;

                    if ( used[tl] ) continue;

                    if ( used[tl + dims.width - 1] ) continue;


                    unsigned int bl = bottom + x;

                    if ( used[bl] ) continue;

                    if ( used[bl + dims.width - 1] ) continue;


                    for ( unsigned int j = top; j <= bottom; j += side ) {
                        for ( unsigned int i = 0; i < dims.width; i++ ) {
                            used[j + i] = true;
                        }
                    }

                    placed = true;
                    _atlas_glyphs.push_back ( atlas_glyph ( glyph.meta(),
                                                            { x, y } ) );
                }
            }

            if ( !placed ) {
                _atlas_glyphs.clear();
                break;
            }
        }
    }

    std::vector<uint8_t> atlas_data ( area );

    for ( unsigned int i = 0; i < glyphs.size(); i++ ) {
        const auto& data   = glyphs[i].data();
        const auto& dims   = glyphs[i].meta().dims();
        const auto& coords = _atlas_glyphs[i].atlas_coords();

        for ( unsigned int y = 0; y < dims.height; y++ ) {
            unsigned int j = coords.y + y;

            for ( unsigned int x = 0; x < dims.width; x++ ) {
                unsigned int i = coords.x + x;
            }
        }
    }
}
