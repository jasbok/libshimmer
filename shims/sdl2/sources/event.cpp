#include "event.h"

int SDL_PollEvent ( SDL_Event* event )
{
    SHIM_LOG ( 1000 );

    auto available = sym::SDL_PollEvent ( event );

    if ( available ) {
        switch ( event->type ) {
        case SDL_MOUSEBUTTONDOWN:

            //             printf ( "Mouse DOWN position: %i,  %i\n",
            //                      event->motion.x,
            //                      event->motion.y );
            //
            //             printf ( "Mouse DOWN position (rel): %i,  %i\n",
            //                      event->motion.xrel,
            //                      event->motion.yrel );
            break;

        case SDL_MOUSEBUTTONUP:

            //             printf ( "Mouse UP position: %i,  %i\n",
            //                      event->motion.x,
            //                      event->motion.y );
            //
            //             printf ( "Mouse UP position (rel): %i,  %i\n",
            //                      event->motion.xrel,
            //                      event->motion.yrel );
            break;

        case SDL_MOUSEMOTION:

            //             printf ( "Mouse MOTION position: %i,  %i\n",
            //                      event->motion.x,
            //                      event->motion.y );
            //
            //             printf ( "Mouse MOTION position (rel): %i,  %i\n",
            //                      event->motion.xrel,
            //                      event->motion.yrel );
            break;

        case SDL_WINDOWEVENT:
            switch (event->window.event){
                case SDL_WINDOWEVENT_RESIZED:
                    glpp::dims_2u dims(event->window.data1, event->window.data2);
                    libshimmer->resize_window(dims);
                    break;
            }
            break;
        }
    }

    return available;
}
