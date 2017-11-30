#include "event.h"

int SDL_PollEvent ( SDL_Event* event )
{
    SHIM_LOG();

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
            case SDL_WINDOWEVENT_MOVED:
                shim.window_coords =
                { event->window.data1, event->window.data2 };
                libshimmer->move_window ( shim.window_coords );
                event->window.data2 = shim.window_coords.x;
                event->window.data2 =  shim.window_coords.y;
                break;

            case SDL_WINDOWEVENT_RESIZED:
                shim.window_dims = glpp::dims_2u ( event->window.data1,
                                                   event->window.data2 );
                libshimmer->resize_window ( shim.window_dims );
                event->type = 0;
                break;
            }
            break;
        }
    }

    return available;
}
