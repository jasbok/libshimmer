#ifndef SHIMS_SDL2_EVENT_H
#define SHIMS_SDL2_EVENT_H

#include "shim.h"

SHIM ( int,  SDL_PollEvent,  SDL_Event * event );

SHIM ( void, SDL_PumpEvents, void );

SHIM ( int,
       SDL_PeepEvents,
       SDL_Event * events,
       int numevents,
       SDL_eventaction action,
       Uint32 minType,
       Uint32 maxType );

#endif // ifndef SHIMS_SDL2_EVENT_H
