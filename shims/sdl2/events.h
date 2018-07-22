#ifndef SHIMS_SDL2_EVENTS_H
#define SHIMS_SDL2_EVENTS_H

#include "api/SDL2_sym.h"

#include "common/dims.h"

class events
{
    class shim* _shim;

    common::dims_2u _source_resolution;

    common::dims_2u _target_resolution;

public:
    events( class shim* shim );

    virtual ~events() = default;

    int  poll ( SDL_Event* event );

    void source_resolution ( const common::dims_2u& dims );

    void target_resolution ( const common::dims_2u& dims );

private:
    bool            _is_valid_resize ( const common::dims_2u& dims );

    common::dims_2u _resize_dims ( SDL_WindowEvent& event );

    void            _process ( SDL_Event* event );

    void            _process ( SDL_MouseMotionEvent& event );

    void            _process ( SDL_MouseButtonEvent& event );

    void            _process ( SDL_WindowEvent& event );
};
#endif // ifndef SHIMS_SDL2_EVENTS_H
