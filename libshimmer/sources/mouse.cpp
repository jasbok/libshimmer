#include "mouse.h"

#include "logger.h"

#include <cmath>

using namespace shimmer;

mouse::mouse()
    : _connector ( nullptr ),
      _aspect ( 1.0f, 1.0f ),
      _display(),
      _window ( 1.0f, 1.0f )
{}

mouse::mouse( event_connector& connector )
    : _connector ( &connector ),
      _aspect ( 1.0f, 1.0f ),
      _display(),
      _window ( 1.0f, 1.0f )
{
    LOGD << "Connecting to connector.";
    _connector->connect ( aspect_ratio_change::type(),       *this );
    _connector->connect ( display_resolution_change::type(), *this );
    _connector->connect ( window_dims_change::type(),        *this );
}

mouse::~mouse() {
    if ( _connector ) {
        LOGD << "Disconnecting from connector.";
        _connector->disconnect ( aspect_ratio_change::type(),       *this );
        _connector->disconnect ( display_resolution_change::type(), *this );
        _connector->disconnect ( window_dims_change::type(),        *this );
    }
}

void mouse::send ( const event& event ) {
    switch ( event.type() ) {
    case event::type::aspect_ratio_change:
        _aspect_ratio_event ( event );
        break;

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

coords_2i mouse::transform ( const coords_2i& coords ) {
    auto ret = static_cast<coords_2f>( coords ) * _transform;

    LOGV << "transformed coordinates: " << _coords << " -> " << ret;

    return ret;
}

coords_2i mouse::transform_relative ( const coords_2i& coords )
{
    coords_2f ret = static_cast<coords_2f>( coords ) * _transform_relative;

    ret.x = ceilf ( ret.x );
    ret.y = ceilf ( ret.y );

    LOGV << "transformed relative coordinates: " << coords << " -> " << ret;

    return ret;
}

mouse& mouse::aspect ( const dims_2f& aspect )
{
    LOGD << "setting aspect: " << aspect;
    _aspect = aspect;
    _update_transform();

    return *this;
}

mouse& mouse::display ( const dims_2u& display ) {
    LOGD << "setting display: " << display;
    _display = display;
    _update_transform();

    return *this;
}

mouse& mouse::window ( const dims_2u& window ) {
    LOGD << "setting window: " << window;
    _window = window;
    _update_transform();

    return *this;
}

void mouse::_update_transform() {
    auto relative = _display / _window;
    auto position = relative * _aspect;

    _transform          = { position.width, position.height };
    _transform_relative = { relative.width, relative.height };

    LOGD << "updated transform: " << _transform;
    LOGD << "updated relative transform: " << _transform_relative;
}

void mouse::_aspect_ratio_event ( const aspect_ratio_change& event )
{
    aspect ( event.data() );
}

void mouse::_display_event ( const display_resolution_change& event ) {
    display ( event.data() );
}

void mouse::_window_event ( const window_dims_change& event ) {
    window ( event.data() );
}
