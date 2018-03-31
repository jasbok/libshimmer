#ifndef SHIMS_SDL_SHIM_H
#define SHIMS_SDL_SHIM_H

#include "limiter.h"
#include "shimmer.h"

#include <SDL.h>

#include <memory>

struct shim {
    SDL_Surface* video;
    bool         do_resize = false;

    shimmer::dims_2u   window_dims;
    shimmer::coords_2i window_coords;
    std::string        window_title;
    shimmer::coords_2i mouse_coords;
};

extern struct shim shim;

extern std::shared_ptr<class ::shimmer::shimmer> libshimmer;

void init_shimmer();

SHIM ( int,          SDL_Init,
       Uint32 flags );

SHIM ( void,         SDL_Quit,
       void );

SHIM ( SDL_GrabMode, SDL_WM_GrabInput,
       SDL_GrabMode mode );

SHIM ( void,         SDL_WarpMouse, Uint16 x, Uint16 y );

#endif // ifndef SHIMS_SDL_SHIM_H
