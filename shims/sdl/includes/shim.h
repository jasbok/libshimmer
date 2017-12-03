#ifndef SHIMS_SDL_SHIM_H
#define SHIMS_SDL_SHIM_H

#include "shimmer.h"

#include <SDL.h>

#include <memory>

struct shim {
    SDL_Surface* video;

    glpp::dims_2u   window_dims;
    glpp::coords_2i window_coords;
    std::string     window_title;
    glpp::coords_2i mouse_coords;

    void ( * bindFramebuffer )( GLenum,
                                GLuint );
};

extern struct shim shim;

extern std::shared_ptr<class ::shimmer::shimmer> libshimmer;

void init_shimmer();

SHIM ( int,  SDL_Init,
       Uint32 flags );

SHIM ( void, SDL_Quit,
       void );

#endif // ifndef SHIMS_SDL_SHIM_H
