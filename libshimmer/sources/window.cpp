#include "window.h"

namespace shimmer
{
window::window() : system ( "window" ) {}

window::~window() {}

void    window::send ( const event& base_event ) {}

window& window::dimensions ( const dims_2u& dimensions ) {
    _dimensions = dimensions;
    send_parent ( window_dims_change ( dimensions ) );

    return *this;
}

dims_2u window::dimensions() const {
    return _dimensions;
}

window& window::title ( const std::string& title ) {
    _title = title;
    send_parent ( window_title_change ( title ) );

    return *this;
}

std::string window::title() const {
    return _title;
}
}
