#include "font_atlas.h"

#include "pixels.h"

#include <algorithm>
#include <cmath>
#include <memory>

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
    : _texture ( texture::internal_format::red ),
      _atlas_glyphs()
{
    _get_atlas_glyphs ( glyphs );
}

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
        return a.meta().dims().height > b.meta().dims().height;
    } );

    unsigned int glyph_area = 0;

    for ( const auto& glyph : glyphs ) {
        glyph_area += (glyph.meta().dims() + dims_2u ( 1, 1 )).area();
    }

    auto side = _upper_pow2 ( static_cast<unsigned int>(sqrt ( glyph_area )) );
    auto area = side * side;

    while ( _atlas_glyphs.empty() == true ) {
        std::vector<uint8_t> used ( area );

        for ( auto& glyph : glyphs ) {
            auto dims   = glyph.meta().dims() + dims_2u ( 1, 1 );
            bool placed = false;

            for ( unsigned int y = 0; y < side && !placed; y += 3 ) {
                if ( y + dims.height >= side ) break;

                for ( unsigned int x = 0; x < side && !placed; x += 3 ) {
                    if ( x + dims.width >= side ) break;

                    bool do_continue = false;

                    for ( unsigned int j = 0; j < dims.height; j += 3 ) {
                        unsigned int jstep = (j + y) * side;

                        for ( unsigned int i = 0; i < dims.width; i += 3 ) {
                            if ( used[jstep + x + i] ) {
                                do_continue = true;
                                break;
                            }
                        }

                        if ( do_continue ) break;
                    }

                    if ( do_continue ) continue;

                    for ( unsigned int j = 0; j < dims.height; j += 3 ) {
                        unsigned int jstep = (j + y) * side;

                        for ( unsigned int i = 0; i < dims.width; i += 3 ) {
                            used[jstep + x + i] = true;
                        }
                    }

                    placed = true;
                    _atlas_glyphs.push_back ( atlas_glyph ( glyph.meta(),
                                                            { x, y } ) );
                }
            }

            if ( !placed ) {
                side = _upper_pow2 ( side + 1 );
                area = side * side;
                _atlas_glyphs.clear();
                break;
            }
        }
    }

    std::unique_ptr<uint8_t> atlas_data ( new uint8_t[area] );

    for ( unsigned int i = 0; i < area; i++ ) {
        atlas_data.get()[i] = 0;
    }

    for ( unsigned int i = 0; i < glyphs.size(); i++ ) {
        const auto& data   = glyphs[i].data();
        const auto& dims   = glyphs[i].meta().dims();
        const auto& coords = _atlas_glyphs[i].atlas_coords();

        for ( unsigned int y = 0; y < dims.height; y++ ) {
            unsigned int j     = coords.y + y;
            unsigned int ystep = y * dims.width;
            unsigned int jstep = j * side;

            for ( unsigned int x = 0; x < dims.width; x++ ) {
                unsigned int i = coords.x + x;
                atlas_data.get()[jstep + i] = data[ystep + x];
            }
        }
    }

    _texture.bind();
    _texture.image ( pixels ( std::move ( atlas_data ),
                              { side, side },
                              pixels::format::red,
                              pixels::type::gl_unsigned_byte ) );
}
