#ifndef GLPP_FONT_ATLAS_H
#define GLPP_FONT_ATLAS_H

#include "glyph.h"
#include "texture_2d.h"

#include <unordered_map>

namespace glpp
{
struct atlas_coords {
    atlas_coords( const coords_2u& coords,
                  const dims_2u&   dims );

    void normalise ( float factor );

    coords_2f tl, tr, bl, br;
};

class atlas_glyph : public glyph_metadata
{
public:
    atlas_glyph( const glyph_metadata& meta,
                 const coords_2u&      atlas_coords );

    atlas_glyph( atlas_glyph&& move ) = default;

    atlas_glyph( const atlas_glyph& copy ) = default;

    virtual ~atlas_glyph() = default;

    atlas_glyph&        operator=( atlas_glyph&& move ) = default;

    atlas_glyph&        operator=( const atlas_glyph& copy ) = default;

    struct atlas_coords atlas_coords();

private:
    struct atlas_coords _atlas_coords;
};

class font_atlas
{
public:
    explicit font_atlas( std::vector<glyph>&& glyphs,
                         unsigned int         spacing = 7,
                         float                resize_rate = 1.05 );

    font_atlas( font_atlas&& move );

    font_atlas( const font_atlas& copy ) = delete;

    virtual ~font_atlas();

    font_atlas& operator=( font_atlas&& move );

    font_atlas& operator=( const font_atlas& copy ) = delete;


    texture_2d&  texture();

    unsigned int size() const;

    unsigned int spacing() const;

private:
    typedef std::unordered_map<unsigned int, atlas_glyph> glyph_map;
    typedef std::unordered_map<std::string, glyph_map>    group_map;

    texture_2d _texture;

    unsigned int _spacing;

    unsigned int _size;

    group_map _atlas_glyphs;

    float _resize_rate;


    void _calculate_atlas_size ( std::vector<glyph>& glyphs );

    void _design_atlas ( std::vector<glyph>& glyphs );

    void _draw_atlas ( std::vector<glyph>& glyphs );

    void _normalise_coordinates();


    void                _increase_size();

    inline unsigned int _correct_texture_size ( unsigned int size );


    bool _place ( const std::vector<glyph>& glyphs );

    bool _place ( const glyph&          glyph,
                  std::vector<uint8_t>& surface );

    void _add_glyph ( const glyph&     glyph,
                      const coords_2u& coords );

    atlas_glyph& _get_atlas_glyph ( const glyph& glyph  );

    bool         _is_claimed ( const std::vector<uint8_t>& surface,
                               const coords_2u&            coords,
                               const dims_2u&              dims );

    void _claim_surface ( std::vector<uint8_t>& surface,
                          const coords_2u&      coords,
                          const dims_2u&        dims );
};
}

#endif // ifndef GLPP_FONT_ATLAS_H
