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

        case SDL_VIDEORESIZE:

            if ( shim.video && ( event->resize.w <= 1920 ) &&
                 ( event->resize.h <= 1080 ) ) {
                shim.window_dims =
                    glpp::dims_2u ( event->resize.w, event->resize.h );

                shim.video = sym::SDL_SetVideoMode ( shim.window_dims.width,
                                                     shim.window_dims.height,
                                                     24,
                                                     SDL_HWSURFACE | SDL_OPENGL |
                                                     SDL_RESIZABLE );

                libshimmer->resize_window ( shim.window_dims );

                libshimmer->init_renderer();

                libshimmer->create_application_framebuffer();
            }

            //            if ( shimmer_->video()->video_resolution() !=
            // shimmer::dimensions<> (
            //                        target->w,
            //                        target->h ) ) {
            //                target = sym::SDL_SetVideoMode (
            //
            //
            //                        shimmer_->video()->video_resolution().w,
            //
            //
            //                        shimmer_->video()->video_resolution().h,
            //                             32,
            //                             SDL_RESIZABLE | SDL_OPENGL );
            //            }

            // Do not propagate resize event to application
            event->active.type = SDL_NOEVENT;
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
