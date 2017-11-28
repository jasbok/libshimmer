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
    SDL_GLContext gl_context;

    glpp::dims_2u   window_dims;
    glpp::coords_2i window_coords;
    glpp::coords_2i mouse_coords;

    bool opengl_initiliased = false;
};

extern struct shim shim;


SHIM ( int,  SDL_Init, Uint32 flags );
SHIM ( void, SDL_Quit, void );


#endif // ifndef SHIMS_SDL2_SHIM_H
