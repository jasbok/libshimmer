#ifndef SHIMS_SDL2_INPUT_H
#define SHIMS_SDL2_INPUT_H

#include "api/SDL2_sym.h"

#include "common/dims.h"

#include "shimmer/input.h"

class input
{
    class shim* _shim;

    common::dims_2u _source_resolution;

    common::dims_2u _target_resolution;

    common::dims_2f _aspect;

    struct shimmer::input::transform _absolute_transform;

    struct shimmer::input::transform _relative_transform;

public:
    input( class shim* shim );

    virtual ~input() = default;

    void   source_resolution ( const common::dims_2u& dims );

    void   target_resolution ( const common::dims_2u& dims );

    Uint32 mouse_state ( int* x,
                         int* y );

    void mouse_motion_absolute ( Sint32& x,
                                 Sint32& y );

    void mouse_motion_relative ( Sint32& xrel,
                                 Sint32& yrel );

private:
    void _calculate_transforms();
};

#endif // ifndef SHIMS_SDL2_INPUT_H
