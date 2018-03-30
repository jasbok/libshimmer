#include "window.h"

#include "plog/Log.h"

namespace shimmer
{
window::window( event_receiver& exchange )
    : _exchange ( &exchange )
{}

window::~window() {}

window& window::coordinates ( const coords_2i& coordinates )
{
    _coordinates = coordinates;
    _exchange->send ( window_coords_change ( coordinates ) );

    return *this;
}

coords_2i window::coordinates() const
{
    return _coordinates;
}

window& window::dimensions ( const dims_2u& dimensions ) {
    _dimensions = dimensions;
    _exchange->send ( window_dims_change ( dimensions ) );

    return *this;
}

dims_2u window::dimensions() const {
    return _dimensions;
}

window& window::title ( const std::string& title ) {
    _title = title;
    _exchange->send ( window_title_change ( title ) );

    return *this;
}

std::string window::title() const {
    return _title;
}
}
