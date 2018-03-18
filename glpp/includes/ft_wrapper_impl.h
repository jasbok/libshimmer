#ifndef GLPP_FT_WRAPPER_IMPL_H
#define GLPP_FT_WRAPPER_IMPL_H

#include "ft_wrapper.h"
#include "glyph.h"

#include <ft2build.h>
#include FT_FREETYPE_H

#include <exception>
#include <memory>
#include <string>

namespace glpp
{
class ft_wrapper::impl
{
public:
    impl();

    virtual ~impl() = default;

    void load_face ( const std::string& path,
                     const unsigned int size,
                     const unsigned int dpi );

    glyph get_glyph ( wchar_t unicode ) const;

private:
    using Library = std::unique_ptr<std::remove_reference<decltype( * FT_Library() )>::type,
                                    decltype(& ::FT_Done_FreeType )>;

    using Face = std::unique_ptr<std::remove_reference<decltype( * FT_Face() )>::type,
                                 decltype(& FT_Done_Face )>;

    Library _handle;
    std::unique_ptr<Face> _current_face;

    static Library _load_library();

    static void    _print_error ( FT_Error           ft_err,
                                  const std::string& label );
};


struct freetype_font_not_supported_exception : public std::exception {
    const char* what() const throw( ) {
        return "The specified font is not supported.";
    }
};

struct freetype_font_not_found_exception : public std::exception {
    const char* what() const throw( ) {
        return "Could not find the specified font.";
    }
};

struct freetype_unsupported_font_size_exception : public std::exception {
    const char* what() const throw( ) {
        return "The specified size is not supported by the font.";
    }
};

struct freetype_no_face_loaded_exception : public std::exception {
    const char* what() const throw( ) {
        return "No face has been loaded before getting a glyph.";
    }
};

struct freetype_unable_to_load_glyph_exception : public std::exception {
    const char* what() const throw( ) {
        return "The specified size is not supported by the font.";
    }
};

struct freetype_init_exception : public std::exception {
    const char* what() const throw( ) {
        return "Could not initialise FreeType.";
    }
};
}

#endif // ifndef GLPP_FT_WRAPPER_IMPL_H
