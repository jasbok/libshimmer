#include "events.h"

#include "shim.h"

events::events( class shim* shim )
    : _shim ( shim )
{}

int events::poll ( SDL_Event* event )
{
    int result = sym::SDL_PollEvent ( event );

    if ( event ) {
        switch ( event->type ) {
        case SDL_MOUSEMOTION:
            _shim->input.mouse_motion_absolute ( event->motion.x,
                                                 event->motion.y );
            _shim->input.mouse_motion_relative ( event->motion.xrel,
                                                 event->motion.yrel );
            break;

        case SDL_VIDEORESIZE:
            _shim->window.resize ( event->resize.w, event->resize.h );

            // Do not propagate resize event to application
            event->active.type = SDL_NOEVENT;
            result             = 0;

            break;

        default:
            break;
        }
    }

    return result;
}
