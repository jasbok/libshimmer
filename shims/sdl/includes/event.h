#ifndef SHIMS_SDL_EVENT_H
#define SHIMS_SDL_EVENT_H

#include "shim.h"

void process_event ( SDL_Event* event );

SHIM ( int, SDL_PollEvent,
       SDL_Event* event );

SHIM ( Uint8, SDL_EventState,
       Uint8 type,
       int state );

#endif
