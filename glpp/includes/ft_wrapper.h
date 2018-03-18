#ifndef GLPP_FT_WRAPPER_H
#define GLPP_FT_WRAPPER_H

#include "glyph.h"

#include <memory>
#include <string>

namespace glpp
{
class ft_wrapper
{
public:
    ft_wrapper();
    virtual ~ft_wrapper();

    void load_face ( const std::string& path,
                     const unsigned int size,
                     const unsigned int dpi );

    glyph get_glyph ( wchar_t unicode ) const;

private:
    class impl;
    std::unique_ptr<impl> _impl;
};
}

#endif // ifndef GLPP_FT_WRAPPER_H
