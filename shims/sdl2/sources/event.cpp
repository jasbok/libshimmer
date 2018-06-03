#include "event.h"

void process_event ( SDL_Event* event ) {
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
            shim.window_dims = shimmer::dims_2u ( event->window.data1,
                                                  event->window.data2 );
            libshimmer->resize_window ( shim.window_dims );

            event->window.data1 = libshimmer->app_surface_dims().width;
            event->window.data2 = libshimmer->app_surface_dims().height;
            break;
        }
        break;
    }
}

int SDL_PollEvent ( SDL_Event* event )
{
    SHIM_LOG();

    auto available = sym::SDL_PollEvent ( event );

    if ( available ) {
        process_event ( event );
    }

    return available;
}

void SDL_PumpEvents() {
    SHIM_LOG();

    return sym::SDL_PumpEvents();
}

int SDL_PeepEvents (
    SDL_Event*      events,
    int             numevents,
    SDL_eventaction action,
    Uint32          minType,
    Uint32          maxType ) {
    SHIM_LOG();

    int ret =
        sym::SDL_PeepEvents ( events, numevents, action, minType, maxType );

    for ( int i = 0; i < numevents; i++ ) {
        process_event ( events + i );
    }

    return ret;
}
