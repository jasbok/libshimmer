#include "event.h"

int SDL_PollEvent ( SDL_Event* event )
{
    SHIM_LOG ( 1000 );

    auto available = sym::SDL_PollEvent ( event );

    if ( available ) {
        switch ( event->type ) {
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
        case SDL_MOUSEMOTION:
            shim.mouse_coords = { event->motion.x, event->motion.y };
            libshimmer->mouse_coords ( shim.mouse_coords );
            event->motion.x = shim.mouse_coords.x;
            event->motion.y = shim.mouse_coords.y;
            break;

        case SDL_WINDOWEVENT:

            switch ( event->window.event ) {
            case SDL_WINDOWEVENT_RESIZED:
                glpp::dims_2u dims ( event->window.data1, event->window.data2 );
                libshimmer->resize_window ( dims );
                event->type = 0;

                break;
            }
            break;
        }
    }

    return available;
}
