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
    : _app ( std::make_shared<struct application>() ),
      _options ( std::make_shared<struct options>() ),
      _renderer ( std::make_shared<renderer>( _app, _options ) )
{
    _load_config();
}

shimmer::~shimmer()
{}

void shimmer::create_window ( string&    title,
                              coords_2i& coords,
                              dims_2u&   dims )
{
    _app->window.title = title;
    _app->surface.dims = dims;

    if ( _app->window.dims.area() == 0 ) {
        _app->window.coords = coords;
        _app->window.dims   = dims;
    }
    else {
        coords = _app->window.coords;
        dims   = _app->window.dims;
    }

    set_window_title ( title );
}

dims_2u shimmer::app_surface_dims()
{
    return _app->surface.dims;
}

void shimmer::set_window_title ( string& title )
{
    title += " [shimmer]";
}

void shimmer::init()
{}

void shimmer::init_renderer()
{
    _renderer->init();
}

void shimmer::resize_window ( glpp::dims_2u& dims )
{
    _app->window.dims = dims;
    _renderer->update();
    dims = _app->surface.dims;
}

void shimmer::move_window ( coords_2i& coords )
{
    _app->window.coords = coords;
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
    const auto& app_dims = _app->surface.dims;
    const auto& win_dims = _app->window.dims;

    coords.x *= app_dims.width / ( float )win_dims.width;
    coords.y *= app_dims.height / ( float )win_dims.height;
}

void shimmer::_load_config()
{
    using json = nlohmann::json;

    try {
        ifstream fstream ( "shimmer.conf" );

        if ( fstream.is_open() ) {
            json options_json;
            fstream >> options_json;
            *_options = options_json;
        }
        else {
            _save_config();
        }
    }
    catch ( json::exception ex ) {
        std::cerr << "Unable to parse config file: " << ex.what() << std::endl;
    }
    catch ( exception ex ) {
        std::cerr << "Unable to parse config file: " << ex.what() << std::endl;
    }
}

void shimmer::_save_config() const
{
    string   path = "shimmer.conf";
    ofstream fstream ( path );

    if ( fstream.is_open() ) {
        using json = nlohmann::json;
        json options_json = *_options;
        fstream << std::setw ( 4 ) << options_json;
    }
    else {
        std::cerr << "Unable to write config to file: " << path << std::endl;
    }
}
}
