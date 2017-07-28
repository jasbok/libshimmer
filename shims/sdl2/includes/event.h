#ifndef SHIMS_SDL2_EVENT_H
#define SHIMS_SDL2_EVENT_H

#include "shim.h"

SHIM ( int, SDL_PollEvent, SDL_Event * event );

#endif // ifndef SHIMS_SDL2_EVENT_H
