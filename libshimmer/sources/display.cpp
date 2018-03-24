#include "display.h"

namespace shimmer
{
display::display()
    : system ( "display" ),
      _resolution(),
      _depth()
{}

display::~display() {}

void     display::send ( const event& event ) {}

display& display::resolution ( const dims_2u resolution ) {
    _resolution = resolution;
    send_parent ( display_resolution_change ( resolution ) );

    return *this;
}

dims_2u display::resolution() const {
    return _resolution;
}

display& display::depth ( unsigned int depth ) {
    _depth = depth;
    send_parent ( display_depth_change ( depth ) );

    return *this;
}

unsigned int display::depth() const {
    return _depth;
}
}
