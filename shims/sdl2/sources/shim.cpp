#include "shim.h"

std::shared_ptr<class ::shimmer::shimmer> libshimmer = nullptr;

struct shim shim;

void init_shimmer() {
    SHIM_LOG();

    if ( !libshimmer ) {
        libshimmer = std::make_shared<class shimmer::shimmer>();
        libshimmer->init();
    }
}

int SDL_Init ( Uint32 flags ) {
    SHIM_LOG();

    init_shimmer();

    return sym::SDL_Init ( flags );
}

void SDL_Quit() {
    SHIM_LOG();
    sym::SDL_Quit();
}
