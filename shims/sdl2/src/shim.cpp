#include "shim.h"

#include "shim.h"

std::shared_ptr<class ::shimmer::shimmer> libshimmer = nullptr;

struct shim shim;

void init_shimmer() {
    if ( !libshimmer ) {
        libshimmer = std::make_shared<class shimmer::shimmer>();
    }
}

int SDL_Init ( Uint32 flags ) {
    init_shimmer();

    return sym::SDL_Init ( flags );
}

void SDL_Quit() {
    sym::SDL_Quit();
}
