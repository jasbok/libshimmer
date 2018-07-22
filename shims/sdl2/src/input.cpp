#include "input.h"

#include "shim.h"

#include "shimmer/video.h"

input::input( class shim* shim )
    : _shim ( shim )
{}

void input::source_resolution ( const common::dims_2u& dims )
{
    _source_resolution = dims;
    _calculate_transforms();
}

void input::target_resolution ( const common::dims_2u& dims )
{
    _target_resolution = dims;
    _calculate_transforms();
}

Uint32 input::mouse_state ( int* x_ptr, int* y_ptr )
{
    Uint32 button_state = sym::SDL_GetMouseState ( x_ptr, y_ptr );

    int x = x_ptr ? *x_ptr : 0;
    int y = y_ptr ? *y_ptr : 0;

    shimmer::input::transform ( x, y, _absolute_transform );
    shimmer::input::constrain ( x, y, _source_resolution );

    if ( x_ptr ) *x_ptr = x;

    if ( y_ptr ) *y_ptr = y;

    return button_state;
}

void input::mouse_motion_absolute ( Sint32& x, Sint32& y )
{
    shimmer::input::transform ( x, y, _absolute_transform );
    shimmer::input::constrain ( x, y, _source_resolution );
}

void input::mouse_motion_relative ( Sint32& xrel, Sint32& yrel )
{
    shimmer::input::transform_relative ( xrel, yrel, _relative_transform );
}

void input::_calculate_transforms()
{
    _aspect = shimmer::video::aspect_transform ( _source_resolution,
                                                 _target_resolution,
                                                 _shim->config );

    _absolute_transform = shimmer::input::absolute_transform (
        _source_resolution,
        _target_resolution,
        _aspect );

    _relative_transform = shimmer::input::relative_transform (
        _source_resolution,
        _target_resolution );
}
