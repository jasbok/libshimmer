#ifndef SHIMMER_SHIMMER_H
#define SHIMMER_SHIMMER_H

#include "config.h"
#include "macros.h"
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

    glpp::dims_2u app_surface_dims();

    void          set_window_title ( std::string& title );

    void          init();

    void          init_renderer();

    void          resize_window ( glpp::dims_2u& dims );

    void          move_window ( glpp::coords_2i& coords );

    void          refresh_display();

    glpp::dims_2u application_resolution() const;

    glpp::dims_2u window_resolution() const;

    void          capture_application_texture();

    void          mouse_coords ( glpp::coords_2i& coords );

private:
    std::shared_ptr<config> _config;

    std::shared_ptr<renderer> _renderer;
};
}

#endif // ifndef SHIMMER_SHIMMER_H
