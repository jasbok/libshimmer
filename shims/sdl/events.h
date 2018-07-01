#ifndef SHIMS_SDL_EVENTS_H
#define SHIMS_SDL_EVENTS_H

#include "api/SDL_sym.h"
#include "common/dims.h"

class shim;

class events
{
    class shim* _shim;

    common::dims_2u _source_resolution;

    common::dims_2u _target_resolution;

public:
    events( class shim* shim );

    virtual ~events() = default;

    int poll ( SDL_Event* event );

    int peep ( SDL_Event*      events,
               int             numevents,
               SDL_eventaction action,
               Uint32          mask );

    void source_resolution ( const common::dims_2u& dims );

    void target_resolution ( const common::dims_2u& dims );

private:
    bool _is_valid_resize ( int w,
                            int h );

    common::dims_2u _resize_dims ( SDL_Event* event );

    void            _process ( SDL_Event* event );
    void            _process_mouse ( SDL_Event* event );
    void            _process_resize ( SDL_Event* event );
};

#endif // ifndef SHIMS_SDL_EVENTS_H
