#ifndef SHIMS_SDL_INPUT_H
#define SHIMS_SDL_INPUT_H

#include "api/SDL_sym.h"

#include "common/dims.h"

class input
{
    class shim* _shim;

    common::dims_2u _source_resolution;

    common::dims_2u _target_resolution;

    common::dims_2f _absolute_transform;

    common::dims_2f _relative_transform;

public:
    input( class shim* shim );

    virtual ~input() = default;

    void         source_resolution ( const common::dims_2u& dims );

    void         target_resolution ( const common::dims_2u& dims );

    SDL_GrabMode grab ( SDL_GrabMode mode );

    void         mouse_motion_absolute ( Uint16& x,
                                         Uint16& y );

    void mouse_motion_relative ( Sint16& xrel,
                                 Sint16& yrel );

    void mouse_warp ( Uint16 x,
                      Uint16 y );

private:
    void _calculate_transforms();
};

#endif // ifndef SHIMS_SDL_INPUT_H
