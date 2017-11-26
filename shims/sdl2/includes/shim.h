#ifndef SHIMS_SDL2_SHIM_H
#define SHIMS_SDL2_SHIM_H

#include "shimmer.h"

#include <SDL.h>

#include <memory>

extern std::shared_ptr<class ::shimmer::shimmer> libshimmer;

struct shim {
    SDL_Window*     window;
    SDL_Renderer*   renderer;
    SDL_Texture*    target;
    SDL_GLContext   gl_context;
    glpp::coords_2i mouse_coords;
};

extern struct shim shim;


SHIM ( int,  SDL_Init, Uint32 flags );
SHIM ( void, SDL_Quit, void );


#endif // ifndef SHIMS_SDL2_SHIM_H
