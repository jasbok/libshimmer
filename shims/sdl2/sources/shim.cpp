#include "shim.h"

std::shared_ptr<class ::shimmer::shimmer> libshimmer = nullptr;

int SDL_Init ( Uint32 flags ) {
    SHIM_LOG ( 1 );

    if ( !libshimmer ) {
        libshimmer = std::make_shared<class shimmer::shimmer>();
    }

    return sym::SDL_Init ( flags );
}

void SDL_Quit() {
    SHIM_LOG ( 1 );
    sym::SDL_Quit();
}
