#include "display.h"

namespace shimmer
{
display::display( event_receiver& exchange )
    : _exchange ( &exchange ),
      _resolution(),
      _depth()
{}

display::~display() {}

display& display::resolution ( const dims_2u resolution ) {
    _resolution = resolution;
    _exchange->send ( display_resolution_change ( resolution ) );

    return *this;
}

dims_2u display::resolution() const {
    return _resolution;
}

display& display::depth ( unsigned int depth ) {
    _depth = depth;
    _exchange->send ( display_depth_change ( depth ) );

    return *this;
}

unsigned int display::depth() const {
    return _depth;
}
}
