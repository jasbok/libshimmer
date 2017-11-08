#ifndef GLPP_FONT_LOADER_H
#define GLPP_FONT_LOADER_H

#include "specs.h"

#include <freetype2/ft2build.h>
#include FT_FREETYPE_H

#include <string>
#include <vector>

namespace glpp
{
class glyph
{
public:
    glyph( wchar_t                unicode,
           const dims_2u&         dims,
           const coords_2i&       bearing,
           const coords_2i&       advance,
           std::vector<uint8_t>&& data );

    glyph( wchar_t                unicode,
           const dims_2u&         dims,
           const coords_2i&       bearing,
           const coords_2i&       advance,
           const coords_2i&       vertical_bearing,
           std::vector<uint8_t>&& data );

    glyph( glyph&& move );

    glyph( const glyph& copy ) = delete;

    virtual ~glyph();

    glyph& operator=( glyph&& move );

    glyph& operator=( const glyph& copy ) = delete;


    unsigned int unicode() const;

    dims_2u      dims() const;

    coords_2i    bearing() const;

    coords_2i    advance() const;

    bool         has_vertical() const;

    coords_2i    vertical_bearing() const;

    uint8_t*     data();

private:
    wchar_t _unicode;

    dims_2u _dims;

    coords_2i _bearing;

    coords_2i _advance;

    bool _has_vertical;

    coords_2i _vertical_bearing;

    std::vector<uint8_t> _data;
};

class font_face
{
public:
    font_face( const FT_Library&  ft,
               const std::string& path,
               unsigned int       size,
               unsigned int       dpi = 72 );

    font_face( font_face&& move );

    font_face( const font_face& copy ) = delete;

    virtual ~font_face();

    font_face& operator=( font_face&& move );

    font_face& operator=( const font_face& copy ) = delete;

    glyph      get_glyph ( wchar_t unicode ) const;

private:
    FT_Face _face;

    std::string _path;

    unsigned int _size;

    unsigned int _dpi;
};

class font_loader
{
public:
    font_loader( const std::vector<std::string>& paths );

    virtual ~font_loader();

    std::vector<glyph> load ( const std::string& path,
                              unsigned int       size );

private:
    std::vector<std::string> _search_paths;

    FT_Library _ft;

    std::vector<glyph> _convert_to_glyphs ( const FT_Face& face );
};

struct freetype_init_exception : public std::exception {
    const char* what() const throw() {
        return "Could not initialise FreeType.";
    }
};

struct font_not_supported_exception : public std::exception {
    const char* what() const throw() {
        return "The specified font is not supported.";
    }
};

struct font_not_found_exception : public std::exception {
    const char* what() const throw() {
        return "Could not find the specified font.";
    }
};

struct unsupported_font_size_exception : public std::exception {
    const char* what() const throw() {
        return "The specified size is not supported by the font.";
    }
};

struct unable_to_load_glyph_exception : public std::exception {
    const char* what() const throw() {
        return "The specified size is not supported by the font.";
    }
};
}

#endif // GLPP_FONT_LOADER_H
