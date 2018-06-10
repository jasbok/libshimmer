#ifndef SHIMS_SDL_EVENTS_H
#define SHIMS_SDL_EVENTS_H

#include "api/sym/SDL_sym.h"

class shim;

class events
{
    class shim* _shim;

public:
    events( class shim* shim );

    virtual ~events() = default;

    int poll ( SDL_Event* event );
};

#endif // ifndef SHIMS_SDL_EVENTS_H
