#include "aspect.h"

namespace shimmer
{
aspect::aspect( event_connector& connector )
    : _connector ( &connector ),
      _display ( 1.0f, 1.0f ),
      _window ( 1.0f, 1.0f ),
      _aspect_ratio ( aspect_ratio::original ),
      _transform ( 1.0f, 1.0f )
{
    _connector->connect ( display_resolution_change::type(), *this );
    _connector->connect ( video_options_change::type(),      *this );
    _connector->connect ( window_dims_change::type(),        *this );
}

aspect::~aspect() {
    _connector->disconnect ( display_resolution_change::type(), *this );
    _connector->disconnect ( video_options_change::type(),      *this );
    _connector->disconnect ( window_dims_change::type(),        *this );
}

void aspect::send ( const event& event ) {
    switch ( event.type() ) {
    case event::type::display_resolution_change:
        _display_event ( event );
        break;

    case event::type::video_options_change:
        _video_options_event ( event );
        break;

    case event::type::window_dims_change:
        _window_event ( event );
        break;

    default:
        break;
    }
}

dims_2f aspect::transform() const {
    return _transform;
}

void aspect::_video_options_event ( const video_options_change& event ) {
    _aspect_ratio = event.data().aspect_ratio;
    _calculate_transform();
}

void aspect::_display_event ( const display_resolution_change& event ) {
    _display = event.data();
    _calculate_transform();
}

void aspect::_window_event ( const window_dims_change& event ) {
    _window = event.data();
    _calculate_transform();
}

void aspect::_calculate_transform() {
    _transform = { 1.0f, 1.0f };

    if ( _aspect_ratio != aspect_ratio::stretch ) {
        float ar_factor = _display.wh_ratio() / _window.wh_ratio();

        if ( _aspect_ratio == aspect_ratio::zoom ) {
            _transform = { ar_factor < 1.0f ?  1.0f : ar_factor,
                           ar_factor < 1.0f ? 1.0f / ar_factor : 1.0f };
        } else {
            _transform = { ar_factor > 1.0f ?  1.0f : ar_factor,
                           ar_factor > 1.0f ? 1.0f / ar_factor : 1.0f };
        }
    }

    _connector->send ( aspect_ratio_change ( _transform ) );
}
}
