#include "font_loader.h"

#include <cstring>
#include <iostream>
#include <iterator>

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

font_spec::font_spec( const string&           id,
                      const string&           path,
                      unsigned int            size,
                      std::vector<range_uint> unicodes )
    : _id ( id ),
      _path ( path ),
      _size ( size ),
      _unicodes ( unicodes )
{}

font_spec& font_spec::path ( const string& path )
{
    _path = path;

    return *this;
}

string font_spec::path() const
{
    return _path;
}

font_spec& font_spec::id ( const string& id )
{
    _id = id;

    return *this;
}

string font_spec::id() const
{
    return _id;
}

font_spec& font_spec::size ( unsigned int size )
{
    _size = size;

    return *this;
}

unsigned int font_spec::size() const
{
    return _size;
}

font_spec& font_spec::unicodes ( const std::vector<range_uint>& unicodes )
{
    _unicodes = unicodes;

    return *this;
}

std::vector<range_uint> font_spec::unicodes() const
{
    return _unicodes;
}

font_face::font_face( const FT_Library& ft,
                      const font_spec&  font,
                      unsigned int      dpi )
    : _face(),
      _font ( font ),
      _dpi ( dpi )
{
    auto ft_err = FT_New_Face ( ft,
                                _font.path().c_str(),
                                0,
                                &_face );

    if ( ft_err == FT_Err_Unknown_File_Format )
    {
        print_ft_error ( ft_err, _font.path() );
        throw font_not_supported_exception();
    }
    else if ( ft_err != FT_Err_Ok )
    {
        print_ft_error ( ft_err, _font.path() );
        throw font_not_found_exception();
    }

    ft_err = FT_Set_Char_Size ( _face,
                                0,
                                _font.size() * 64,
                                0,
                                _dpi );

    if ( ft_err != FT_Err_Ok ) {
        print_ft_error ( ft_err, _font.path() );
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

    dims_2u   dims ( slot->bitmap.width, slot->bitmap.rows );
    coords_2i bearing ( metrics.horiBearingX, metrics.horiBearingY );
    coords_2i advance ( metrics.horiAdvance, metrics.vertAdvance );
    coords_2i vertical_bearing ( metrics.vertBearingX, metrics.vertBearingY );

    glyph_metadata meta = FT_HAS_VERTICAL ( _face )
                          ? glyph_metadata ( unicode,
                                             _font.id(),
                                             dims,
                                             bearing,
                                             advance )

                          : glyph_metadata ( unicode,
                                             _font.id(),
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

vector<glyph> font_loader::load ( const font_spec& font,
                                  unsigned int     dpi )
{
    for ( const auto& search_path : _search_paths ) {
        try {
            font_spec curr = font;
            curr.path ( search_path + "/" + font.path() );

            return _convert_to_glyphs ( font_face ( _ft, curr, dpi ) );
        }
        catch ( const exception& ex ) {
            cerr << "Unable to load font, checking search path... "
                 << "(" << font.path() << "): "
                 << ex.what() << std::endl;
        }
    }

    throw font_not_found_exception();
}

std::vector<glyph> font_loader::load ( const std::vector<font_spec>& fonts,
                                       unsigned int                  dpi )
{
    std::vector<glyph> results;

    for ( const auto& font : fonts ) {
        auto glyphs = load ( font, dpi );
        std::move ( glyphs.begin(), glyphs.end(), back_inserter ( results ) );
    }

    return results;
}

std::vector<glyph> font_loader::_convert_to_glyphs ( const font_face& face )
{
    std::vector<glyph> glyphs;

    for ( auto range : face.font().unicodes() ) {
        for ( unsigned int c = range.start; c < range.end; c++ ) {
            try {
                auto glyph = face.get_glyph ( c );
                auto dims  = glyph.meta().dims();

                if ( (dims.width > 0) && (dims.height > 0) ) {
                    glyphs.push_back ( std::move ( glyph ) );
                }
            }
            catch ( const exception& ex ) {}
        }
    }


    return glyphs;
}
