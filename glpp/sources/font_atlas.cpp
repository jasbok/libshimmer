#include "font_atlas.h"

#include "pixels.h"

#include <algorithm>
#include <cmath>
#include <memory>

using namespace glpp;
using namespace std;

atlas_coords::atlas_coords( const coords_2u& coords, const dims_2u& dims )
    : tl ( coords.x, coords.y ),
      tr ( coords.x + dims.width, coords.y ),
      bl ( coords.x, coords.y + dims.height ),
      br ( coords.x + dims.width, coords.y + dims.height  )
{}

void atlas_coords::normalise ( float factor ) {
    tl *= factor;
    tr *= factor;
    bl *= factor;
    br *= factor;
}

atlas_glyph::atlas_glyph( const glyph_metadata& meta,
                          const coords_2u&      atlas_coords )
    : glyph_metadata ( meta ),
      _atlas_coords ( atlas_coords, meta.dims() )
{}

atlas_coords atlas_glyph::atlas_coords()
{
    return _atlas_coords;
}

font_atlas::font_atlas( std::vector<glyph>&& glyphs,
                        unsigned int         spacing,
                        float                resize_rate )
    : _texture ( texture::internal_format::red ),
      _spacing ( spacing ),
      _size(),
      _atlas_glyphs(),
      _resize_rate ( resize_rate )
{
    _spacing     = _spacing < 128 ? _spacing : 128;
    _resize_rate = _resize_rate > 1.01f ? _resize_rate : 1.01f;

    _calculate_atlas_size ( glyphs );

    _design_atlas ( glyphs );

    _draw_atlas ( glyphs );

    _normalise_coordinates();
}

font_atlas::~font_atlas() {}

texture_2d& font_atlas::texture()
{
    return _texture;
}

unsigned int font_atlas::size() const
{
    return _size;
}

void font_atlas::_calculate_atlas_size ( std::vector<glyph>& glyphs )
{
    unsigned int optimal_area = 0;
    dims_2u      space_adjustment ( _spacing / 2, _spacing / 2 );

    for ( const auto& glyph : glyphs ) {
        optimal_area += (glyph.meta().dims() + space_adjustment).area();
    }

    _size = _correct_texture_size ( sqrt ( optimal_area ) );
}

void font_atlas::_design_atlas ( std::vector<glyph>& glyphs )
{
    std::sort ( glyphs.begin(), glyphs.end(), [] ( auto& a, auto& b ) {
        return a.meta().dims().height > b.meta().dims().height;
    } );


    while ( !_place ( glyphs ) ) {
        _increase_size();
    }
}

void font_atlas::_draw_atlas ( std::vector<glyph>& glyphs )
{
    unsigned int area = _size * _size;

    std::unique_ptr<uint8_t> atlas_data ( new uint8_t[area] );

    for ( unsigned int i = 0; i < area; i++ ) {
        atlas_data.get()[i] = 0;
    }

    for ( unsigned int i = 0; i < glyphs.size(); i++ ) {
        const auto& data   = glyphs[i].data();
        const auto& dims   = glyphs[i].meta().dims();
        const auto& coords = _get_atlas_glyph ( glyphs[i] ).atlas_coords().tl;

        for ( unsigned int y = 0; y < dims.height; y++ ) {
            unsigned int j     = coords.y + y;
            unsigned int ystep = y * dims.width;
            unsigned int jstep = j * _size;

            for ( unsigned int x = 0; x < dims.width; x++ ) {
                unsigned int i = coords.x + x;
                atlas_data.get()[jstep + i] = data[ystep + x];
            }
        }
    }

    _texture.bind();
    _texture.image ( pixels ( std::move ( atlas_data ),
                              { _size, _size },
                              pixels::format::red,
                              pixels::type::gl_unsigned_byte ) );
}

void font_atlas::_normalise_coordinates()
{
    float normalise_factor = 1.0f / ( float )_size;

    for ( auto& group_pair : _atlas_glyphs ) {
        for ( auto& glyph_pair : group_pair.second ) {
            glyph_pair.second.atlas_coords().normalise ( normalise_factor );
        }
    }
}

inline void font_atlas::_increase_size() {
    _size = _correct_texture_size ( _size * _resize_rate );
}

unsigned int font_atlas::_correct_texture_size ( unsigned int size )
{
    // Round size up to the nearest number divisable by 16.
    // Avoids texture artifacts (diagonal skewing).

    return (size / 16 + 1) * 16;
}

bool font_atlas::_place ( const std::vector<glyph>& glyphs )
{
    unsigned int area = _size * _size;

    std::vector<uint8_t> surface ( area );

    for ( const auto& glyph : glyphs ) {
        if ( !_place ( glyph, surface ) ) {
            _atlas_glyphs.clear();

            return false;
        }
    }

    return true;
}

bool font_atlas::_place ( const glyph&          glyph,
                          std::vector<uint8_t>& surface )
{
    auto dims = glyph.meta().dims() + dims_2u ( 1, 1 );
    coords_2u coords;

    for ( coords.y = 1; coords.y < _size; coords.y += _spacing ) {
        if ( coords.y + dims.height >= _size ) break;

        for ( coords.x = 1; coords.x < _size; coords.x += _spacing ) {
            if ( coords.x + dims.width >= _size ) break;

            if ( _is_claimed ( surface, coords, dims ) ) continue;

            _claim_surface ( surface, coords, dims );
            _add_glyph ( glyph, coords );

            return true;
        }
    }

    return false;
}

void font_atlas::_add_glyph ( const glyph&     glyph,
                              const coords_2u& coords )
{
    auto& group = _atlas_glyphs[glyph.meta().group()];

    group.insert ( { glyph.meta().unicode(), { glyph.meta(), coords } } );
}

atlas_glyph& font_atlas::_get_atlas_glyph ( const glyph& glyph )
{
    auto& group = _atlas_glyphs.at ( glyph.meta().group() );
    auto& slot  = group.at ( glyph.meta().unicode() );

    return slot;
}

bool font_atlas::_is_claimed ( const std::vector<uint8_t>& area,
                               const coords_2u&            coords,
                               const dims_2u&              dims ) {
    for ( unsigned int j = 0; j < dims.height; j += _spacing ) {
        unsigned int jstep = (j + coords.y) * _size;

        for ( unsigned int i = 0; i < dims.width; i += _spacing ) {
            if ( area[jstep + coords.x + i] ) return true;
        }
    }

    return false;
}

void font_atlas::_claim_surface ( std::vector<uint8_t>& area,
                                  const coords_2u&      coords,
                                  const dims_2u&        dims ) {
    for ( unsigned int j = 0; j < dims.height; j += _spacing ) {
        unsigned int jstep = (j + coords.y) * _size;

        for ( unsigned int i = 0; i < dims.width; i += _spacing ) {
            area[jstep + coords.x + i] = true;
        }
    }
}
