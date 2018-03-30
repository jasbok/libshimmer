#ifndef SHIMMER_SHIMMER_H
#define SHIMMER_SHIMMER_H

#include "config.h"
#include "coords.h"
#include "dims.h"
#include "display.h"
#include "event_exchange.h"
#include "macros.h"
#include "mouse.h"
#include "renderer.h"
#include "window.h"

namespace shimmer
{
class shimmer
{
public:
    shimmer();

    virtual ~shimmer();

    void create_window ( coords_2i& coords,
                         dims_2u&   dims );

    void create_window ( std::string& title,
                         coords_2i&   coords,
                         dims_2u&     dims );

    void    set_window_title ( std::string& title );

    dims_2u app_surface_dims();

    void    init_renderer();

    void    resize_window ( dims_2u& dims );

    void    move_window ( coords_2i& coords );

    void    refresh_display();

    dims_2u application_resolution() const;

    dims_2u window_resolution() const;

    void    capture_application_texture();

    void    create_application_framebuffer();

    void    bind_application_framebuffer();

    void    unbind_application_framebuffer();

    bool    limit_refresh_rate();

    void    application_texture_flip_y ( bool flip_y );

    void    mouse_coords ( coords_2i& coords );

private:
    event_exchange _exchange;

    std::shared_ptr<config> _config;

    std::shared_ptr<renderer> _renderer;

    display _display;

    mouse _mouse;

    window _window;
};
}

#endif // ifndef SHIMMER_SHIMMER_H
