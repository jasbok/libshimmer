#ifndef SHIMS_SDL_INPUT_H
#define SHIMS_SDL_INPUT_H

#include "api/SDL_sym.h"

class input
{
    class shim* _shim;

public:
    input( class shim* shim );

    virtual ~input() = default;

    SDL_GrabMode grab ( SDL_GrabMode mode );

    void         mouse_motion_absolute ( Uint16& x,
                                         Uint16& y );

    void mouse_motion_relative ( Sint16& xrel,
                                 Sint16& yrel );

    void mouse_warp ( Uint16 x,
                      Uint16 y );
};

#endif // ifndef SHIMS_SDL_INPUT_H
