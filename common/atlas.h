#ifndef COMMON_ATLAS_H
#define COMMON_ATLAS_H

#include "coords.h"
#include "img.h"

namespace common::atlas
{
struct atlas_coords {
    atlas_coords() = default;

    atlas_coords( const coords_2u& coords,
                  const dims_2u&   dims );

    void normalise ( float factor );

    coords_2f tl, tr, bl, br;
};

struct atlas {
    atlas( std::vector<atlas_coords>&& coords,
           common::img::image&&        texture );

    atlas( atlas&& move ) = default;

    atlas( const atlas& copy ) = delete;

    virtual ~atlas() = default;

    atlas& operator=( atlas&& move ) = default;

    atlas& operator=( const atlas& copy ) = delete;


    std::vector<atlas_coords> coords;

    img::image texture;
};

atlas build ( const std::vector<img::image>& bitmaps,
              unsigned int                   spacing     = 7,
              float                          resize_rate = 1.05f );

void sort ( std::vector<img::image>& bitmaps );
}

#endif // ifndef COMMON_ATLAS_H
