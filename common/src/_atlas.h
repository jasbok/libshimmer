#ifndef P_COMMON_ATLAS_H
#define P_COMMON_ATLAS_H

#include "atlas.h"
#include <img.h>
#include <vector>

namespace common::atlas {
unsigned int _calculate_atlas_size ( const std::vector<img::image>& bitmaps,
                                     unsigned int               spacing );

std::pair<unsigned int, std::vector<atlas_coords>>
_design_atlas ( const std::vector<img::image>& bitmaps,
                unsigned int               size,
                unsigned int               spacing,
                float                      resize_rate );

common::img::image _draw_atlas ( unsigned int                     size,
                                 const std::vector<img::image>&       bitmaps,
                                 const std::vector<atlas_coords>& coords );


inline unsigned int _resize ( unsigned int size,
                              float        rate );

unsigned int               _correct_texture_size ( unsigned int size );

std::pair<bool, coords_2u> _place ( const img::image&  bitmap,
                                    img::image& surface,
                                    unsigned int   spacing );

void _add_glyph ( const img::image&    bitmap,
                  const coords_2u& coords );

bool _is_claimed ( const img::image& surface,
                   const coords_2u&     coords,
                   const dims_2u&       dims,
                   unsigned int         spacing );

void _claim_surface ( img::image&   surface,
                      const coords_2u& coords,
                      const dims_2u&   dims,
                      unsigned int     spacing );
}

#endif
