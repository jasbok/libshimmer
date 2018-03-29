#include "window.h"

namespace shimmer
{
window::window( event_exchange& exchange )
    : _exchange ( &exchange )
{}

window::~window() {}

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
