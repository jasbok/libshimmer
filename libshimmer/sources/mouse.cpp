#include "mouse.h"

#include "plog/Log.h"

using namespace shimmer;

mouse::mouse()
    : _application ( dims_2f() ),
      _window ( dims_2f ( 1, 1 ) )
{}

mouse::~mouse() {}

coords_2i mouse::transform ( const coords_2i& coords ) {
    _coords = coords;

    return _coords * _transform;
}

void mouse::send ( const event& event ) {
    switch ( event.type() ) {
    case event::type::display_resolution_change:
        _application_event ( event );
        break;

    case event::type::window_dims_change:
        _window_event ( event );
        break;

    default:
        break;
    }
}

mouse& mouse::application ( const dims_2u& application ) {
    _application = application;
    _update_transform();

    return *this;
}

mouse& mouse::window ( const dims_2u& window ) {
    _window = window;
    _update_transform();

    return *this;
}

void mouse::_update_transform() {
    auto div = _application / _window;

    _transform = { div.width, div.height };
}

void mouse::_application_event ( const display_resolution_change& event ) {
    application ( event.data() );
}

void mouse::_window_event ( const window_dims_change& event ) {
    window ( event.data() );
}
