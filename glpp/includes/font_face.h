#ifndef GLPP_FONT_FACE_H
#define GLPP_FONT_FACE_H

#include "font_spec.h"
#include "ft_wrapper.h"
#include "glyph.h"

namespace glpp
{
class font_face
{
public:
    font_face( const ft_wrapper& ft,
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

struct font_not_supported_exception : public std::exception {
    const char* what() const throw( ) {
        return "The specified font is not supported.";
    }
};

struct font_not_found_exception : public std::exception {
    const char* what() const throw( ) {
        return "Could not find the specified font.";
    }
};

struct unsupported_font_size_exception : public std::exception {
    const char* what() const throw( ) {
        return "The specified size is not supported by the font.";
    }
};

struct unable_to_load_glyph_exception : public std::exception {
    const char* what() const throw( ) {
        return "The specified size is not supported by the font.";
    }
};
}

#endif // ifndef GLPP_FONT_FACE_H
