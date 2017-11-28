#include "shimmer.h"

#include "debug.h"
#include "glpp.h"

#include <iostream>

using namespace glpp;
using namespace std;

namespace shimmer
{
shimmer::shimmer()
{}

shimmer::~shimmer()
{}

void shimmer::create_window ( string&    title,
                              coords_2i& coords,
                              dims_2u&   dims )
{
    _app.window.title = title;
    _app.surface.dims = dims;

    if ( _app.window.dims.area() == 0 ) {
        _app.window.coords = coords;
        _app.window.dims   = dims;
    }
    else {
        coords = _app.window.coords;
        dims   = _app.window.dims;
    }

    set_window_title ( title );
}

dims_2u shimmer::app_surface_dims()
{
    return _app.surface.dims;
}

void shimmer::set_window_title ( string& title )
{
    title += " [shimmer]";
}

void shimmer::init()
{}

void shimmer::init_renderer()
{
    _renderer = std::make_shared<renderer>();
    _renderer->init ( _app, _options );
}

void shimmer::resize_window ( glpp::dims_2u& dims )
{
    _app.window.dims = dims;
    _renderer->update ( _app );
    dims = _app.surface.dims;
}

void shimmer::move_window ( coords_2i& coords )
{
    _app.window.coords = coords;
}

void shimmer::refresh_display()
{
    _renderer->render();
}

bool shimmer::scaling_enabled() const
{
    return _options.video.scaling_shader.has_value();
}

void shimmer::capture_application_texture()
{
    _renderer->create_application_texture_from_bound ( _app, _options );
}

void shimmer::mouse_coords ( coords_2i& coords )
{
    const auto& app_dims = _app.surface.dims;
    const auto& win_dims = _app.window.dims;

    coords.x *= app_dims.width / ( float )win_dims.width;
    coords.y *= app_dims.height / ( float )win_dims.height;
}
}
