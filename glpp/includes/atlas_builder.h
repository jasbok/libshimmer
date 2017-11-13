#ifndef GLPP_ATLAS_BUILDER_H
#define GLPP_ATLAS_BUILDER_H

#include "bitmap.h"
#include "texture_2d.h"

namespace glpp
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
           texture_2d&&                texture );

    atlas( atlas&& move ) = default;

    atlas( const atlas& copy ) = delete;

    virtual ~atlas() = default;

    atlas& operator=( atlas&& move ) = default;

    atlas& operator=( const atlas& copy ) = delete;


    std::vector<atlas_coords> coords;

    texture_2d texture;
};

class atlas_builder
{
public:
    virtual ~atlas_builder() = default;

    atlas build ( const std::vector<bitmap>& bitmaps,
                  unsigned int               spacing     = 7,
                  float                      resize_rate = 1.05 );


    void sort ( std::vector<bitmap>& bitmaps );

private:
    unsigned int _calculate_atlas_size ( const std::vector<bitmap>& bitmaps,
                                         unsigned int               spacing );

    std::pair<unsigned int, std::vector<atlas_coords>>
    _design_atlas ( const std::vector<bitmap>& bitmaps,
                    unsigned int               size,
                    unsigned int               spacing,
                    float                      resize_rate );

    texture_2d _draw_atlas ( unsigned int                     size,
                             const std::vector<bitmap>&       bitmaps,
                             const std::vector<atlas_coords>& coords );


    inline unsigned int _resize ( unsigned int size,
                                  float        rate );

    unsigned int               _correct_texture_size ( unsigned int size );

    std::pair<bool, coords_2u> _place ( const bitmap&  bitmap,
                                        struct bitmap& surface,
                                        unsigned int   spacing );

    void _add_glyph ( const bitmap&    bitmap,
                      const coords_2u& coords );

    bool _is_claimed ( const struct bitmap& surface,
                       const coords_2u&     coords,
                       const dims_2u&       dims,
                       unsigned int         spacing );

    void _claim_surface ( struct bitmap&   surface,
                          const coords_2u& coords,
                          const dims_2u&   dims,
                          unsigned int     spacing );
};
}

#endif // ifndef GLPP_ATLAS_BUILDER_H
