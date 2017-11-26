#ifndef SHIMMER_SHIMMER_H
#define SHIMMER_SHIMMER_H

#include "macros.h"
#include "options.h"
#include "renderer.h"
#include "specs.h"

namespace shimmer
{
class shimmer
{
public:
    shimmer();

    virtual ~shimmer();

    void create_window ( std::string&     title,
                         glpp::coords_2i& coords,
                         glpp::dims_2u&   dims );

    void          init();

    void          init_renderer();

    void          resize_window ( glpp::dims_2u& dims );

    void          refresh_display();

    glpp::dims_2u application_resolution() const;

    glpp::dims_2u window_resolution() const;

    bool          scaling_enabled() const;

    void          activate_application_texture();

    void          mouse_coords ( glpp::coords_2i& coords );

private:
    struct application _app;
    struct options _options;

    renderer _renderer;
};
}

#endif // ifndef SHIMMER_SHIMMER_H
