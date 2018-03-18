#ifndef GLPP_FONT_LOADER_H
#define GLPP_FONT_LOADER_H

#include "font_spec.h"
#include "glyph.h"

namespace glpp
{
class font_loader
{
public:
    explicit font_loader( const std::vector<std::string>& paths );

    virtual ~font_loader();

    glyph_pack load ( const font_spec& font,
                      unsigned int     dpi = 72 );

    glyph_pack load ( const std::vector<font_spec>& fonts,
                      unsigned int                  dpi = 72 );

private:
    std::vector<std::string> _search_paths;
};
}

#endif // GLPP_FONT_LOADER_H
