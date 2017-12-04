#ifndef SHIMS_SDL_SHIM_H
#define SHIMS_SDL_SHIM_H

#include "limiter.h"
#include "shimmer.h"

#include <SDL.h>

#include <memory>

struct shim {
    SDL_Surface* video;
    bool         do_resize = false;

    glpp::dims_2u   window_dims;
    glpp::coords_2i window_coords;
    std::string     window_title;
    glpp::coords_2i mouse_coords;
};

extern struct shim shim;

extern std::shared_ptr<class ::shimmer::shimmer> libshimmer;

void init_shimmer();

SHIM ( int,  SDL_Init,
       Uint32 flags );

SHIM ( void, SDL_Quit,
       void );

#endif // ifndef SHIMS_SDL_SHIM_H
