#include "freetype.h"

namespace common
{
freetype::freetype()
    : _handle { _load_library() },
      _current_face { nullptr }
{}

void freetype::load ( const std::string& path,
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
        throw font_not_supported_exception ( path, _message_from ( ft_err ) );
    }
    else if ( ft_err != FT_Err_Ok )
    {
        throw font_not_found_exception ( path );
    }

    ft_err = FT_Set_Char_Size ( face,
                                0,
                                size * 64,
                                0,
                                dpi );

    if ( ft_err != FT_Err_Ok ) {
        throw unsupported_font_size_exception ( path, size,
                                                _message_from ( ft_err ) );
    }

    _current_face      = std::make_unique<Face>( face, &FT_Done_Face );
    _current_face_path = path;
}

fonts::glyph freetype::unicode ( wchar_t unicode ) const
{
    if ( _current_face == nullptr ) {
        throw no_face_loaded_exception ( unicode );
    }

    auto face = _current_face.get()->get();

    auto glyph_index = FT_Get_Char_Index ( face,
                                           static_cast<FT_ULong>( unicode ) );

    if ( glyph_index == 0 ) {
        throw unable_to_load_glyph_exception ( _current_face_path, unicode,
                                               "" );
    }

    auto ft_err =
        FT_Load_Glyph ( face, glyph_index, FT_LOAD_RENDER );

    if ( ft_err != FT_Err_Ok ) {
        throw unable_to_load_glyph_exception ( _current_face_path,
                                               unicode,
                                               _message_from ( ft_err ) );
    }

    auto slot    = face->glyph;
    auto metrics = slot->metrics;

    fonts::glyph_meta meta;
    meta.unicode = unicode;
    meta.dims    = { slot->bitmap.width, slot->bitmap.rows };

    meta.bearing = coords_2i ( static_cast<int>( metrics.horiBearingX ),
                               static_cast<int>( metrics.horiBearingY ) );

    meta.advance = coords_2i ( static_cast<int>( metrics.horiAdvance ),
                               static_cast<int>( metrics.vertAdvance ) );

    meta.has_vertical = FT_HAS_VERTICAL ( face );

    meta.vertical_bearing = coords_2i (
        static_cast<int>( metrics.vertBearingX ),
        static_cast<int>( metrics.vertBearingY ) );

    img::image bitmap ( meta.dims, 1 );
    memcpy ( bitmap.data(), slot->bitmap.buffer, bitmap.dims().area() );

    return { meta, std::move ( bitmap ) };
}

freetype::Library freetype::_load_library() {
    FT_Library ft = nullptr;
    auto err      =  FT_Init_FreeType ( &ft );

    if ( err != FT_Err_Ok ) {
        throw initialise_exception ( _message_from ( err ) );
    }

    return { ft, &FT_Done_FreeType };
}

freetype::font_not_supported_exception::font_not_supported_exception(
    const std::string& font,
    const std::string& ft_msg )
    : runtime_error (
          "The specified font is not supported: " + font + " (" + ft_msg + ")" )
{}

freetype::font_not_found_exception::font_not_found_exception(
    const std::string& font )
    : runtime_error ( "Could not find the specified font: " + font )
{}

freetype::unsupported_font_size_exception::unsupported_font_size_exception(
    const std::string& font,
    unsigned int       size,
    const std::string& ft_msg )
    : runtime_error ( "The specified size is not supported by the font: "
          + font + " -> " + std::to_string ( size )
          + " (" + ft_msg + ")" )
{}

freetype::no_face_loaded_exception::no_face_loaded_exception( wchar_t glyph )
    : runtime_error ( "No face has been loaded before getting a glyph: " +
          std::to_string ( glyph ) )
{}

freetype::unable_to_load_glyph_exception::unable_to_load_glyph_exception(
    const std::string& font,
    wchar_t            glyph,
    const std::string& ft_msg )
    : runtime_error (
          "Unable to load the specified glyph: "
          + font + " -> " + std::to_string ( glyph )
          + " (" + ft_msg + ")" )
{}

freetype::initialise_exception::initialise_exception( const std::string& mesg )
    : runtime_error ( "Failed to initialise FreeType: " + mesg )
{}

// *INDENT-OFF*
std::string freetype::_message_from( FT_Error ft_err )
{
    #undef __FTERRORS_H__
    #define FT_ERRORDEF( e, v, s )  case e: return s;
    #define FT_ERROR_START_LIST     switch (ft_err) {
    #define FT_ERROR_END_LIST       default: return "Unknown FT_Error";}
    #include FT_ERRORS_H
}
// *INDENT-ON*
}
