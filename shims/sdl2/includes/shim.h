#ifndef SHIMS_SDL2_SHIM_H
#define SHIMS_SDL2_SHIM_H

#include "shimmer.h"

#include <SDL.h>

#include <memory>

extern std::shared_ptr<class ::shimmer::shimmer> libshimmer;

struct shim {
    SDL_Window*   window;
    SDL_Renderer* renderer;
    SDL_Texture*  target;

    shimmer::dims_2u   window_dims;
    shimmer::coords_2i window_coords;
    shimmer::coords_2i mouse_coords;
};

extern struct shim shim;

void init_shimmer();

SHIM ( int,  SDL_Init, Uint32 flags );
SHIM ( void, SDL_Quit, void );

#endif // ifndef SHIMS_SDL2_SHIM_H
