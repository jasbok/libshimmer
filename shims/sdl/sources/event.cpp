#include "event.h"
#include "video.h"

void process_event ( SDL_Event* event )
{
    if ( event ) {
        switch ( event->type ) {
        //        case SDL_KEYDOWN:
        //        case SDL_KEYUP:
        //            break;

        //        case SDL_MOUSEMOTION:
        //        case SDL_MOUSEBUTTONUP:
        //        case SDL_MOUSEBUTTONDOWN:
        //            break;

        case SDL_MOUSEMOTION:
            libshimmer->mouse_coords ( event->motion.x, event->motion.y );
            libshimmer->mouse_coords_relative ( event->motion.xrel,
                                                event->motion.yrel );
            break;

        case SDL_VIDEORESIZE:

            if ( shim.video && ( event->resize.w <= 1920 ) &&
                 ( event->resize.h <= 1080 ) ) {
                shim.window_dims =
                    shimmer::dims_2u ( event->resize.w, event->resize.h );

                setup_video();

                libshimmer->resize_window ( shim.window_dims );
            }

            // Do not propagate resize event to application
            event->active.type = SDL_NOEVENT;
            event->resize.w    = libshimmer->app_surface_dims().width;
            event->resize.h    = libshimmer->app_surface_dims().height;

            break;

        default:
            break;
        }
    }
}

int SDL_PollEvent ( SDL_Event* event )
{
    SHIM_LOG();
    int result = sym::SDL_PollEvent ( event );
    process_event ( event );

    return result;
}

Uint8 SDL_EventState ( Uint8 type, int state )
{
    SHIM_LOG();

    return sym::SDL_EventState ( type, state );
}
