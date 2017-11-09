#ifndef GLPP_FONT_ATLAS_H
#define GLPP_FONT_ATLAS_H

#include "glyph.h"
#include "texture_2d.h"

namespace glpp
{
class atlas_glyph : public glyph_metadata
{
public:
    atlas_glyph( const glyph_metadata& meta,
                 const coords_2u&      atlas_coords );

    atlas_glyph( atlas_glyph&& move ) = default;

    atlas_glyph( const atlas_glyph& copy ) = default;

    virtual ~atlas_glyph() = default;

    atlas_glyph& operator=( atlas_glyph&& move ) = default;

    atlas_glyph& operator=( const atlas_glyph& copy ) = default;

    coords_2u    atlas_coords();

private:
    coords_2u _atlas_coords;
};

class font_atlas
{
public:
    font_atlas( std::vector<glyph>&& glyphs );

    font_atlas( font_atlas&& move );

    font_atlas( const font_atlas& copy ) = delete;

    virtual ~font_atlas();

    font_atlas& operator=( font_atlas&& move );

    font_atlas& operator=( const font_atlas& copy ) = delete;


    texture_2d&               texture();

    std::vector<atlas_glyph>& glyphs();

private:
    texture_2d _texture;

    std::vector<atlas_glyph> _atlas_glyphs;

    unsigned int _upper_pow2 ( unsigned int i );

    void         _get_atlas_glyphs ( std::vector<glyph>& glyphs );
};
}

#endif // ifndef GLPP_FONT_ATLAS_H
