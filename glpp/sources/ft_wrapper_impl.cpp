#include "ft_wrapper_impl.h"

#include <iostream>

using namespace glpp;
using namespace std;

ft_wrapper::impl::impl()
    : _handle { _load_library() },
      _current_face { nullptr }
{}

void ft_wrapper::impl::load_face ( const std::string& path,
                                   const unsigned int size,
                                   const unsigned int dpi )
{
    FT_Face face   = nullptr;
    auto    ft_err = FT_New_Face ( _handle.get(),
                                   path.c_str(),
                                   0,
                                   &face );

    if ( ft_err == FT_Err_Unknown_File_Format )
    {
        _print_error ( ft_err, path );
        throw freetype_font_not_supported_exception();
    }
    else if ( ft_err != FT_Err_Ok )
    {
        _print_error ( ft_err, path );
        throw freetype_font_not_found_exception();
    }

    ft_err = FT_Set_Char_Size ( face,
                                0,
                                size * 64,
                                0,
                                dpi );

    if ( ft_err != FT_Err_Ok ) {
        _print_error ( ft_err, path );
        throw freetype_unsupported_font_size_exception();
    }

    _current_face = std::make_unique<Face>( face, &FT_Done_Face );
}

glyph ft_wrapper::impl::get_glyph ( wchar_t unicode ) const
{
    if ( _current_face == nullptr ) {
        wcerr << "No face was loaded when trying to load glyph: " <<
            unicode << endl;
        throw freetype_no_face_loaded_exception();
    }

    auto face = _current_face.get()->get();

    auto glyph_index = FT_Get_Char_Index ( face, unicode );

    if ( glyph_index == 0 ) {
        wcerr << "Font does not contain glyph: " << unicode << endl;
        throw freetype_unable_to_load_glyph_exception();
    }

    auto ft_err =
        FT_Load_Glyph ( face, glyph_index, FT_LOAD_RENDER );

    if ( ft_err != FT_Err_Ok ) {
        wcerr << "Unable to load font glyph: " << unicode << endl;
        throw freetype_unable_to_load_glyph_exception();
    }

    auto slot    = face->glyph;
    auto metrics = slot->metrics;

    glyph_meta meta;
    meta.unicode = unicode;
    meta.dims    = { slot->bitmap.width, slot->bitmap.rows };
    meta.bearing = coords_2i ( metrics.horiBearingX, metrics.horiBearingY );
    meta.advance = coords_2i ( metrics.horiAdvance, metrics.vertAdvance );

    meta.has_vertical     = FT_HAS_VERTICAL ( face );
    meta.vertical_bearing = coords_2i ( metrics.vertBearingX,
                                        metrics.vertBearingY );

    bitmap bitmap ( meta.dims );
    memcpy ( bitmap.data.data(), slot->bitmap.buffer, bitmap.dims.area() );

    return { meta, std::move ( bitmap ) };
}

ft_wrapper::impl::Library ft_wrapper::impl::_load_library() {
    FT_Library ft = nullptr;

    if ( FT_Init_FreeType ( &ft ) != FT_Err_Ok ) {
        throw freetype_init_exception();
    }

    return { ft, &FT_Done_FreeType };
}

// *INDENT-OFF*
void ft_wrapper::impl::_print_error(FT_Error ft_err, const string &label)
{
    #undef __FTERRORS_H__
    #define FT_ERRORDEF( e, v, s )  case e: cerr << "freetype - " << s << ": " << label << endl; break;
    #define FT_ERROR_START_LIST     switch (ft_err) {
    #define FT_ERROR_END_LIST       default: cerr << "freetype - " << label << "Unknown FT_Error: " << endl;}
    #include FT_ERRORS_H
}
// *INDENT-ON*
