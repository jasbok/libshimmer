#include "shimmer.h"

#include "debug.h"

#include <iostream>

using namespace glpp;
using namespace std;

namespace shimmer
{
shimmer::shimmer()
{
    std::cout << "Shimmer: initialising...\n";
    std::cout << "Shimmer: initialised.\n";
}

shimmer::~shimmer()
{
    std::cout << "Shimmer: cleaning resources...\n";
    std::cout << "Shimmer: cleaned resources.\n";
}

void shimmer::create_window ( string&    title,
                              coords_2i& coords,
                              dims_2u&   dims )
{
    _app.window.title  = title;
    _app.window.coords = coords;
    _app.window.dims   = dims;
    _app.surface.dims  = dims;

    title += " [shimmer]";

    std::cout << "Create Window: " << title
              << ", coords: " << coords.to_json()
              << ", dims: " << dims.to_json() << std::endl;
}

void shimmer::init()
{}

void shimmer::init_renderer()
{
    _renderer.init ( _app, _options );
}

void shimmer::resize_window ( glpp::dims_2u& dims )
{
    std::cout << "Resizing window: " << dims.to_json() << std::endl;

    _app.window.dims = dims;
    _renderer.update ( _app );
    dims = _app.surface.dims;
}

void shimmer::refresh_display()
{
    _renderer.render();
}

bool shimmer::scaling_enabled() const
{
    return _options.video.scaling_shader.has_value();
}

void shimmer::activate_application_texture()
{
    _renderer.activate_application_texture();
}

void shimmer::mouse_coords ( coords_2i& coords )
{
    const auto& app_dims = _app.surface.dims;
    const auto& win_dims = _app.window.dims;

    coords.x *= app_dims.width / ( float )win_dims.width;
    coords.y *= app_dims.height / ( float )win_dims.height;
}
}
