#include "mouse.h"

#include "logger.h"

using namespace shimmer;

mouse::mouse()
    : _connector ( nullptr ),
      _display(),
      _window ( 1, 1 )
{}

mouse::mouse( event_connector& connector )
    : _connector ( &connector ),
      _display(),
      _window ( 1, 1 )
{
    _connector->connect ( display_resolution_change::type(), *this );
    _connector->connect ( window_dims_change::type(),        *this );
}

mouse::~mouse() {
    if ( _connector ) {
        LOGD << "Disconnecting mouse system from events connector.";
        _connector->disconnect ( display_resolution_change::type(), *this );
        _connector->disconnect ( window_dims_change::type(),        *this );
    }
}

coords_2i mouse::transform ( const coords_2i& coords ) {
    _coords = coords;

    return _coords * _transform;
}

void mouse::send ( const event& event ) {
    switch ( event.type() ) {
    case event::type::display_resolution_change:
        _display_event ( event );
        break;

    case event::type::window_dims_change:
        _window_event ( event );
        break;

    default:
        break;
    }
}

mouse& mouse::display ( const dims_2u& display ) {
    _display = display;
    _update_transform();

    return *this;
}

mouse& mouse::window ( const dims_2u& window ) {
    _window = window;
    _update_transform();

    return *this;
}

void mouse::_update_transform() {
    auto div = _display / _window;

    _transform = { div.width, div.height };
}

void mouse::_display_event ( const display_resolution_change& event ) {
    display ( event.data() );
}

void mouse::_window_event ( const window_dims_change& event ) {
    window ( event.data() );
}
