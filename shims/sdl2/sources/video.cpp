#include "video.h"

void SDL_RenderPresent ( SDL_Renderer* renderer ) {
    SHIM_LOG(10);
    sym::SDL_RenderPresent(renderer);
}
