#include "shimmer.h"

#include "debug.h"
#include "glpp.h"

#include <fstream>
#include <iostream>

using namespace glpp;
using namespace std;

namespace shimmer
{
shimmer::shimmer()
    : _config ( std::make_shared<config>() ),
      _renderer()
{}

shimmer::~shimmer()
{}

void shimmer::create_window ( string&    title,
                              coords_2i& coords,
                              dims_2u&   dims )
{
    auto& app = _config->app;

    app.window.title = title;
    app.surface.dims = dims;

    if ( app.window.dims.area() == 0 ) {
        app.window.coords = coords;
        app.window.dims   = dims;
    }
    else {
        coords = app.window.coords;
        dims   = app.window.dims;
    }

    set_window_title ( title );
}

dims_2u shimmer::app_surface_dims()
{
    return _config->app.surface.dims;
}

void shimmer::set_window_title ( string& title )
{
    title += " [shimmer]";
}

void shimmer::init()
{}

void shimmer::init_renderer()
{
    _renderer = std::make_shared<renderer>( _config );
}

void shimmer::resize_window ( glpp::dims_2u& dims )
{
    _config->app.window.dims = dims;
    dims                     = _config->app.surface.dims;
    _renderer->update();
}

void shimmer::move_window ( coords_2i& coords )
{
    _config->app.window.coords = coords;
}

void shimmer::refresh_display()
{
    _renderer->render();
}

void shimmer::capture_application_texture()
{
    _renderer->create_application_texture_from_bound();
}

void shimmer::mouse_coords ( coords_2i& coords )
{
    const auto& app_dims = _config->app.surface.dims;
    const auto& win_dims = _config->app.window.dims;

    coords.x *= app_dims.width / ( float )win_dims.width;
    coords.y *= app_dims.height / ( float )win_dims.height;
}
}
