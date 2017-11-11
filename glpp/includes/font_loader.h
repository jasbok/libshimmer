#ifndef GLPP_FONT_LOADER_H
#define GLPP_FONT_LOADER_H

#include "glyph.h"
#include "specs.h"

#include <ft2build.h>
#include FT_FREETYPE_H

#include <string>
#include <vector>

namespace glpp
{
class font_spec
{
public:
    font_spec() = delete;

    font_spec( const std::string&      id,
               const std::string&      path,
               unsigned int            size,
               std::vector<range_uint> unicodes );

    font_spec( font_spec&& move ) = default;

    font_spec( const font_spec& copy ) = default;

    virtual ~font_spec() = default;

    font_spec& operator=( font_spec&& move ) = default;

    font_spec& operator=( const font_spec& copy ) = default;


    font_spec&              id ( const std::string& id );

    std::string             id() const;

    font_spec&              path ( const std::string& path );

    std::string             path() const;

    font_spec&              size ( unsigned int size );

    unsigned int            size() const;

    font_spec&              unicodes ( const std::vector<range_uint>& unicodes );

    std::vector<range_uint> unicodes() const;

private:
    std::string _id;

    std::string _path;

    unsigned int _size;

    std::vector<range_uint> _unicodes;
};

class font_face
{
public:
    font_face( const FT_Library& ft,
               const font_spec&  font,
               unsigned int      dpi = 72 );

    font_face( font_face&& move );

    font_face( const font_face& copy ) = delete;

    virtual ~font_face();

    font_face& operator=( font_face&& move );

    font_face& operator=( const font_face& copy ) = delete;

    font_spec  font() const;

    glyph      get_glyph ( wchar_t unicode ) const;

private:
    FT_Face _face;

    font_spec _font;

    unsigned int _dpi;
};

class font_loader
{
public:
    explicit font_loader( const std::vector<std::string>& paths );

    virtual ~font_loader();

    std::vector<glyph> load ( const font_spec& font,
                              unsigned int     dpi = 72 );

    std::vector<glyph> load ( const std::vector<font_spec>& fonts,
                              unsigned int                  dpi = 72 );

private:
    std::vector<std::string> _search_paths;

    FT_Library _ft;

    std::vector<glyph> _convert_to_glyphs ( const font_face& face );
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
