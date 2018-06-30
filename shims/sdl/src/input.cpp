#include "input.h"

#include "shim.h"

#include "libshimmer/input.h"

input::input( class shim* shim )
    : _shim ( shim )
{}

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
    shimmer::input::transform ( x, y,
                                _shim->video.absolute_transform() );
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
