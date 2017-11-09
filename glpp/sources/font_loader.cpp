#include "font_loader.h"

#include <cstring>
#include <iostream>

using namespace glpp;
using namespace std;


// *INDENT-OFF*
void print_ft_error(FT_Error ft_err, const string& label)
{
    #undef __FTERRORS_H__
    #define FT_ERRORDEF( e, v, s )  case e: cerr << s << ": " << label << endl; break;
    #define FT_ERROR_START_LIST     switch (ft_err) {
    #define FT_ERROR_END_LIST       default: cerr << label << "Unknown FT_Error: " << endl;}
    #include FT_ERRORS_H
}

// *INDENT-ON*

font_face::font_face( const FT_Library&  ft,
                      const std::string& path,
                      unsigned int       size,
                      unsigned int       dpi )
    : _face(),
      _path ( path ),
      _size ( size ),
      _dpi ( dpi )
{
    auto ft_err = FT_New_Face ( ft,
                                _path.c_str(),
                                0,
                                &_face );

    if ( ft_err == FT_Err_Unknown_File_Format )
    {
        print_ft_error ( ft_err, path );
        throw font_not_supported_exception();
    }
    else if ( ft_err != FT_Err_Ok )
    {
        print_ft_error ( ft_err, path );
        throw font_not_found_exception();
    }

    ft_err = FT_Set_Char_Size ( _face,
                                0,
                                _size * 64,
                                0,
                                _dpi );

    if ( ft_err != FT_Err_Ok ) {
        print_ft_error ( ft_err, path );
        throw unsupported_font_size_exception();
    }
}

font_face::font_face( font_face&& move )
    : _face ( move._face ),
      _path ( std::move ( move._path ) ),
      _size ( move._size ),
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
    _path = std::move ( move._path );
    _size = move._size;
    _dpi  = move._dpi;

    move._face = nullptr;

    return *this;
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

    dims_2u   dims ( metrics.width, metrics.height );
    coords_2i bearing ( metrics.horiBearingX, metrics.horiBearingY );
    coords_2i advance ( metrics.horiAdvance, metrics.vertAdvance );
    coords_2i vertical_bearing ( metrics.vertBearingX, metrics.vertBearingY );

    glyph_metadata meta = FT_HAS_VERTICAL ( _face )
                          ? glyph_metadata ( unicode,
                                             dims,
                                             bearing,
                                             advance )

                          : glyph_metadata ( unicode,
                                             dims,
                                             bearing,
                                             advance,
                                             vertical_bearing );

    vector<uint8_t> data ( dims.area() );
    memcpy ( data.data(), slot->bitmap.buffer, dims.area() );

    return glyph ( meta, std::move ( data ) );
}

font_loader::font_loader( const vector<string>& paths )
    : _search_paths { "." },
      _ft()
{
    _search_paths.insert ( _search_paths.end(), paths.begin(), paths.end() );

    auto ft_err = FT_Init_FreeType ( &_ft );

    if ( ft_err != FT_Err_Ok ) {
        throw freetype_init_exception();
    }
}

font_loader::~font_loader()
{
    FT_Done_FreeType ( _ft );
}

vector<glyph> font_loader::load ( const string& path,
                                  unsigned int  size,
                                  unsigned int  dpi )
{
    FT_Face face;

    for ( const auto& search_path : _search_paths ) {
        string font_path = search_path + "/" + path;
        auto   ft_err    = FT_New_Face ( _ft,
                                         font_path.c_str(),
                                         0,
                                         &face );

        try {
            return _convert_to_glyphs ( font_face ( _ft,
                                                    font_path,
                                                    size,
                                                    dpi ) );
        }
        catch ( exception ex ) {
            //            cerr << "Unable to load font, checking search path...
            // "
            //                 << "(" << path << "): "
            //                 << ex.what() << std::endl;
        }
    }

    throw font_not_found_exception();
}

std::vector<glyph> font_loader::_convert_to_glyphs ( const font_face& face )
{
    std::vector<glyph> glyphs;

    for ( unsigned int c = 0x00000; c < 0x00080; c++ ) {
        try {
            glyphs.push_back ( face.get_glyph ( c ) );
        }
        catch ( exception ex ) {}
    }

    return glyphs;
}
