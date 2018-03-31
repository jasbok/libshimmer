#include "shim.h"

std::shared_ptr<class ::shimmer::shimmer> libshimmer = nullptr;

struct shim shim;

void init_shimmer() {
    SHIM_LOG();

    if ( !libshimmer ) {
        libshimmer = std::make_shared<class shimmer::shimmer>();
    }
}

int SDL_Init ( Uint32 flags ) {
    SHIM_LOG();

    init_shimmer();

    return sym::SDL_Init ( flags );
}

void SDL_Quit ( void ) {
    SHIM_LOG();
}

SDL_GrabMode SDL_WM_GrabInput ( SDL_GrabMode mode ) {
    SHIM_LOG();

    sym::SDL_WM_GrabInput ( SDL_GRAB_OFF );

    return mode;
}

void SDL_WarpMouse ( Uint16 x, Uint16 y ) {
    shimmer::coords_2i coords ( x, y );
    libshimmer->mouse_coords ( coords );

    sym::SDL_WarpMouse ( coords.x, coords.y );
}
