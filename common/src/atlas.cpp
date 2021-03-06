#include "_atlas.h"

#include <algorithm>
#include <cmath>

namespace common::atlas
{
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

atlas::atlas( std::vector<atlas_coords>&& coords,
              img::image&&                texture )
    : coords ( std::move ( coords ) ),
      texture ( std::move ( texture ) )
{}

atlas build ( const std::vector<img::image>& bitmaps,
              unsigned int                   spacing,
              float                          resize_rate )
{
    spacing     = spacing > 0 ? spacing : 1;
    spacing     = spacing < 128 ? spacing : 128;
    resize_rate = resize_rate > 1.01f ? resize_rate : 1.01f;

    auto optimum_size = _calculate_atlas_size ( bitmaps, spacing );

    auto[size, coords] = _design_atlas ( bitmaps,
                                         optimum_size,
                                         spacing,
                                         resize_rate );

    auto texture = _draw_atlas ( size, bitmaps, coords );

    return { std::move ( coords ), std::move ( texture ) };
}

void sort ( std::vector<img::image>& bitmaps )
{
    std::sort ( bitmaps.begin(), bitmaps.end(), [] ( auto& a, auto& b ) {
            return a.dims().height > b.dims().height;
        } );
}

unsigned int _calculate_atlas_size (
    const std::vector<img::image>& bitmaps,
    unsigned int                   spacing )
{
    unsigned int optimal_area = 0;
    dims_2u space_adjustment ( spacing / 2, spacing / 2 );

    for ( const auto& bitmap : bitmaps ) {
        optimal_area += ( bitmap.dims() + space_adjustment ).area();
    }

    return _correct_texture_size ( static_cast<unsigned int>( sqrt (
                                                                  optimal_area ) ) );
}

std::pair<unsigned int, std::vector<atlas_coords>>
_design_atlas ( const std::vector<img::image>& bitmaps,
                unsigned int                   size,
                unsigned int                   spacing,
                float                          resize_rate )
{
    std::vector<atlas_coords> coords;

    coords.reserve ( bitmaps.size() );

    while ( coords.empty() ) {
        img::image surface ( { size, size }, 1 );

        for ( const auto& bitmap : bitmaps ) {
            auto[success, atlas_coords] = _place ( bitmap, surface, spacing );

            if ( !success ) {
                size = _resize ( size, resize_rate );
                coords.clear();
                break;
            }

            coords.push_back ( { atlas_coords, bitmap.dims() } );
            continue;
        }
    }

    return std::pair{ size, coords };
}

img::image _draw_atlas ( unsigned int                     size,
                         const std::vector<img::image>&   bitmaps,
                         const std::vector<atlas_coords>& atlas_coords )
{
    unsigned int area = size * size;

    std::unique_ptr<uint8_t> atlas_data ( new uint8_t[area] );

    for ( unsigned int i = 0; i < area; i++ ) {
        atlas_data.get()[i] = 0;
    }

    for ( unsigned int i = 0; i < bitmaps.size(); i++ ) {
        const auto& dims   = bitmaps[i].dims();
        const auto& data   = bitmaps[i].data();
        const auto& coords = atlas_coords[i].tl;

        for ( unsigned int y = 0; y < dims.height; y++ ) {
            unsigned int j     = static_cast<unsigned int>( coords.y + y );
            unsigned int ystep = y * dims.width;
            unsigned int jstep = j * size;

            for ( unsigned int x = 0; x < dims.width; x++ ) {
                unsigned int i = static_cast<unsigned int>( coords.x + x );
                atlas_data.get()[jstep + i] = data[ystep + x];
            }
        }
    }

    return common::img::image { std::move ( atlas_data ),
                                { size, size },
                                1 };
}

inline unsigned int _resize ( unsigned int size,
                              float        rate ) {
    return _correct_texture_size ( static_cast<unsigned int>( size * rate ) );
}

unsigned int _correct_texture_size ( unsigned int size )
{
    // Round size up to the nearest number divisable by 16.
    // Avoids texture artifacts (diagonal skewing).

    return ( size / 16 + 1 ) * 16;
}

std::pair<bool, coords_2u> _place ( const img::image& bitmap,
                                    img::image&       surface,
                                    unsigned int      spacing )
{
    auto bdims = bitmap.dims() + dims_2u ( 1, 1 );
    auto sdims = surface.dims();
    coords_2u coords;

    for ( coords.y = 1; coords.y < sdims.height - 1; coords.y += spacing ) {
        if ( coords.y + bdims.height >= sdims.height ) break;

        for ( coords.x = 1; coords.x < sdims.width - 1; coords.x += spacing ) {
            if ( coords.x + bdims.width >= sdims.width ) break;

            if ( _is_claimed ( surface, coords, bdims, spacing ) ) continue;

            _claim_surface ( surface, coords, bdims, spacing );

            return { true, coords };
        }
    }

    return { false, {} };
}

bool _is_claimed ( const img::image& surface,
                   const coords_2u&  coords,
                   const dims_2u&    dims,
                   unsigned int      spacing ) {
    for ( unsigned int j = 0; j < dims.height; j += spacing ) {
        unsigned int jstep = ( j + coords.y ) * surface.dims().width;

        for ( unsigned int i = 0; i < dims.width; i += spacing ) {
            if ( surface.data()[jstep + coords.x + i] ) return true;
        }
    }

    return false;
}

void _claim_surface ( img::image&      surface,
                      const coords_2u& coords,
                      const dims_2u&   dims,
                      unsigned int     spacing ) {
    for ( unsigned int j = 0; j < dims.height; j += spacing ) {
        unsigned int jstep = ( j + coords.y ) * surface.dims().width;

        for ( unsigned int i = 0; i < dims.width; i += spacing ) {
            surface.data()[jstep + coords.x + i] = true;
        }
    }
}
}
