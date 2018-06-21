#include "input.h"

input::input( class shim* shim )
    : _shim ( shim )
{}

SDL_GrabMode input::grab ( SDL_GrabMode mode ) {
    sym::SDL_WM_GrabInput ( SDL_GRAB_OFF );

    return mode;
}

void input::mouse_motion_absolute ( Uint16& x, Uint16& y )
{
    // _lib->mouse_coords ( x, y );
}

void input::mouse_motion_relative ( Sint16& xrel, Sint16& yrel )
{
    // _lib->mouse_coords_relative ( xrel, yrel );
}

void input::mouse_warp ( Uint16 x, Uint16 y ) {
    mouse_motion_absolute ( x, y );

    sym::SDL_WarpMouse ( x, y );
}
