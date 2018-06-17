#include "shimmer.h"

#include "glpp/debug.h"

#include <fstream>
#include <iostream>

using namespace glpp;
using namespace std;

namespace shimmer
{
shimmer::shimmer()
    : _exchange(),
      _config ( _exchange ),
      _aspect ( _exchange ),
      _display ( _exchange ),
      _mouse ( _exchange ),
      _window ( _exchange ),
      _renderer()
{
    _config.load();
}

void shimmer::create_window ( dims_2u& dims )
{
    _display.resolution ( dims );

    if ( _window.dimensions().area() == 0 ) {
        _window.dimensions ( dims );
    }

    dims = _window.dimensions();
}

void shimmer::create_window ( coords_2i& coords,
                              dims_2u&   dims )
{
    _display.resolution ( dims );

    if ( _window.dimensions().area() == 0 ) {
        _window.coordinates ( coords );
        _window.dimensions ( dims );
    }

    coords = _window.coordinates();
    dims   = _window.dimensions();
}

void shimmer::create_window ( string&    title,
                              coords_2i& coords,
                              dims_2u&   dims )
{
    set_window_title ( title );
    create_window ( coords, dims );
}

void shimmer::set_window_title ( string& title )
{
    _window.title ( title );
    title += " [shimmer]";
}

dims_2u shimmer::app_surface_dims()
{
    return _display.resolution();
}

void shimmer::init_renderer()
{
    _renderer = std::make_shared<renderer>( _exchange,
                                            _display.resolution(),
                                            _window.dimensions(),
                                            _config.opts );
}

void shimmer::resize_window ( dims_2u& dims )
{
    _window.dimensions ( dims );
    dims = _display.resolution();

    _renderer->update();
}

void shimmer::move_window ( coords_2i& coords )
{
    _window.coordinates ( coords );
}

void shimmer::refresh_display()
{
    _renderer->render();
}

void shimmer::capture_application_texture()
{
    _renderer->create_application_texture_from_bound();
}

void shimmer::create_application_framebuffer()
{
    _renderer->create_application_framebuffer();
}

void shimmer::bind_application_framebuffer()
{
    _renderer->bind_application_framebuffer();
}

void shimmer::unbind_application_framebuffer()
{
    _renderer->unbind_application_framebuffer();
}

bool shimmer::limit_refresh_rate()
{
    return _config.opts.video.refresh_rate_limiter.check();
}

void shimmer::application_texture_flip_y ( bool flip_y )
{
    _renderer->application_texture_flip_y ( flip_y );
}

void shimmer::mouse_coords ( coords_2i& coords )
{
    coords = _mouse.transform ( coords );
}

void shimmer::mouse_coords_relative ( coords_2i& coords )
{
    coords = _mouse.transform_relative ( coords );
}
}
