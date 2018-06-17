#ifndef COMMON_FREETYPE_H
#define COMMON_FREETYPE_H

#include "fonts.h"

#include <ft2build.h>
#include FT_FREETYPE_H

#include <memory>
#include <string>

namespace common
{
class freetype
{
public:
    freetype();

    virtual ~freetype() = default;

    /**
     * @brief load Loads the font face located at the given path.
     * @param path The path to the font face.
     * @param size The size to load.
     * @param dpi The dpi to load.
     * @throws If the font face could not be loaded.
     */
    void load ( const std::string& path,
                const unsigned int size,
                const unsigned int dpi );

    /**
     * @brief unicode Generates a glyph for the given character using the
     * current loaded face.
     * @param c The unicode character to load.
     * @return A glyph of the given unicode character.
     * @throws If not font face is loaded or creating the character failed.
     */
    fonts::glyph unicode ( wchar_t c ) const;

private:
    using Library = std::unique_ptr<std::remove_reference<decltype( * FT_Library() )>::type,
                                    decltype(& ::FT_Done_FreeType )>;

    using Face = std::unique_ptr<std::remove_reference<decltype( * FT_Face() )>::type,
                                 decltype(& FT_Done_Face )>;

    Library _handle;

    std::string _current_face_path;

    std::unique_ptr<Face> _current_face;

    static Library     _load_library();

    static std::string _message_from ( FT_Error ft_err );

public:
    struct font_not_supported_exception : public std::runtime_error {
        font_not_supported_exception( const std::string& font,
                                      const std::string& ft_msg  );

        virtual ~font_not_supported_exception() = default;
    };

    struct font_not_found_exception : public std::runtime_error {
        font_not_found_exception( const std::string& font );

        virtual ~font_not_found_exception() = default;
    };

    struct unsupported_font_size_exception : public std::runtime_error {
        unsupported_font_size_exception( const std::string& font,
                                         unsigned int       size,
                                         const std::string& ft_msg );

        virtual ~unsupported_font_size_exception() = default;
    };

    struct no_face_loaded_exception : public std::runtime_error {
        no_face_loaded_exception( wchar_t glyph );

        virtual ~no_face_loaded_exception() = default;
    };

    struct unable_to_load_glyph_exception : public std::runtime_error {
        unable_to_load_glyph_exception( const std::string& font,
                                        wchar_t            glyph,
                                        const std::string& ft_msg );

        virtual ~unable_to_load_glyph_exception() = default;
    };

    struct initialise_exception : public std::runtime_error {
        initialise_exception( const std::string& mesg );

        virtual ~initialise_exception() = default;
    };
};
}

#endif // ifndef COMMON_FREETYPE_H
