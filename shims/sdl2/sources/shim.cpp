#include "shim.h"

std::shared_ptr<class ::shimmer::shimmer> libshimmer = nullptr;

struct shim shim;

int SDL_Init ( Uint32 flags ) {
    SHIM_LOG();

    if ( !libshimmer ) {
        libshimmer = std::make_shared<class shimmer::shimmer>();
        libshimmer->init();
    }

    return sym::SDL_Init ( flags );
}

void SDL_Quit() {
    SHIM_LOG();
    sym::SDL_Quit();
}
