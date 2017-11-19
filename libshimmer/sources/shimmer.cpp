#include "shimmer.h"

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

    title += " [shimmer]";
}

void shimmer::resize_window ( glpp::dims_2u& dims )
{
    _app.surface.dims = dims;
}

bool shimmer::scaling_enabled() const
{
    return _options.video.scaling_shader.has_value();
}
}
