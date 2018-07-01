#include "input.h"

#include "shim.h"

#include "shimmer/input.h"
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

SDL_GrabMode input::grab ( SDL_GrabMode mode ) {
    if ( _shim->config.input.grab ) {
        sym::SDL_WM_GrabInput ( SDL_GRAB_ON );
    }
    else {
        sym::SDL_WM_GrabInput ( SDL_GRAB_OFF );
    }

    return mode;
}

void input::mouse_motion_absolute ( Uint16& x, Uint16& y )
{
    shimmer::input::transform ( x, y, _absolute_transform );
}

void input::mouse_motion_relative ( Sint16& xrel, Sint16& yrel )
{
    //    shimmer::input::transform ( xrel, yrel,
    //                                _shim->video.relative_transform() );
}

void input::mouse_warp ( Uint16 x, Uint16 y ) {
    mouse_motion_absolute ( x, y );

    sym::SDL_WarpMouse ( x, y );
}

void input::_calculate_transforms()
{
    auto aspect = shimmer::video::aspect_transform ( _source_resolution,
                                                     _target_resolution,
                                                     _shim->config );

    _absolute_transform = shimmer::input::absolute_transform (
        _target_resolution,
        _source_resolution,
        aspect );

    _relative_transform = shimmer::input::relative_transform (
        _target_resolution,
        _source_resolution );
}
