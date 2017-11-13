#include "font_face.h"

#include <iostream>

using namespace glpp;
using namespace std;

font_face::font_face( const ft_wrapper& ft,
                      const font_spec&  font,
                      unsigned int      dpi )
    : _face(),
      _font ( font ),
      _dpi ( dpi )
{
    auto ft_err = FT_New_Face ( ft.handle(),
                                _font.path().c_str(),
                                0,
                                &_face );

    if ( ft_err == FT_Err_Unknown_File_Format )
    {
        ft_wrapper::print_error ( ft_err, _font.path() );
        throw font_not_supported_exception();
    }
    else if ( ft_err != FT_Err_Ok )
    {
        ft_wrapper::print_error ( ft_err, _font.path() );
        throw font_not_found_exception();
    }

    ft_err = FT_Set_Char_Size ( _face,
                                0,
                                _font.size() * 64,
                                0,
                                _dpi );

    if ( ft_err != FT_Err_Ok ) {
        ft_wrapper::print_error ( ft_err, _font.path() );
        throw unsupported_font_size_exception();
    }
}

font_face::font_face( font_face&& move )
    : _face ( move._face ),
      _font ( move._font ),
      _dpi ( move._dpi )
{
    move._face = nullptr;
}

font_face::~font_face()
{
    FT_Done_Face ( _face );
}

font_face& font_face::operator=( font_face&& move )
{
    _face = move._face;
    _font = move._font;
    _dpi  = move._dpi;

    move._face = nullptr;

    return *this;
}

font_spec font_face::font() const
{
    return _font;
}

glyph font_face::get_glyph ( wchar_t unicode ) const
{
    auto glyph_index = FT_Get_Char_Index ( _face, unicode );

    if ( glyph_index == 0 ) {
        wcerr << "Font does not contain glyph: " << unicode << endl;
        throw unable_to_load_glyph_exception();
    }

    auto ft_err = FT_Load_Glyph ( _face, glyph_index, FT_LOAD_RENDER );

    if ( ft_err != FT_Err_Ok ) {
        wcerr << "Unable to load font glyph: " << unicode << endl;
        throw unable_to_load_glyph_exception();
    }

    auto slot    = _face->glyph;
    auto metrics = slot->metrics;

    glyph_meta meta;
    meta.unicode = unicode;
    meta.dims    = { slot->bitmap.width, slot->bitmap.rows };
    meta.bearing = coords_2i ( metrics.horiBearingX, metrics.horiBearingY );
    meta.advance = coords_2i ( metrics.horiAdvance, metrics.vertAdvance );

    meta.has_vertical     = FT_HAS_VERTICAL ( _face );
    meta.vertical_bearing = coords_2i ( metrics.vertBearingX,
                                        metrics.vertBearingY );

    bitmap bitmap ( meta.dims );
    memcpy ( bitmap.data.data(), slot->bitmap.buffer, bitmap.dims.area() );

    return { meta, std::move ( bitmap ) };
}
