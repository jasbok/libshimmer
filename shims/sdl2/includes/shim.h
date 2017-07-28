#ifndef SHIMS_SDL2_SHIM_H
#define SHIMS_SDL2_SHIM_H

#include "shimmer.h"

#include <SDL.h>

#include <memory>

extern std::shared_ptr<class::shimmer::shimmer> libshimmer;

SHIM ( int, SDL_Init, Uint32 flags );
SHIM ( void, SDL_Quit, void );



#endif
