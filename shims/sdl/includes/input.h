#ifndef SHIMS_SDL_INPUT_H
#define SHIMS_SDL_INPUT_H

#include "api/sym/SDL_sym.h"

#include "shimmer.h"

class input {
    class shimmer::shimmer* _lib;

public:
    input(class shimmer::shimmer* lib);

    virtual ~input() = default;

    SDL_GrabMode grab ( SDL_GrabMode mode );

    void         mouse_motion_absolute ( Uint16& x,
                                         Uint16& y );

    void mouse_motion_relative ( Sint16& xrel,
                                 Sint16& yrel );

    void mouse_warp ( Uint16 x,
                      Uint16 y );
};

#endif
