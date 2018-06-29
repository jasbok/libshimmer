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

            if ( ( event->resize.w > 0 ) && ( event->resize.h > 0 ) &&
                 ( event->resize.w <= 1920 ) && ( event->resize.h <= 1080 ) ) {
                _shim->window.resize ( event->resize.w, event->resize.h );
                _shim->video.resize ( event->resize.w, event->resize.h );

                // Do not propagate resize event to application
                event->resize.w =
                    static_cast<int>( _shim->video.resolution().width );
                event->resize.h =
                    static_cast<int>( _shim->video.resolution().height );
                event->active.type = SDL_NOEVENT;
                result             = 0;
            }

            break;

        default:
            break;
        }
    }

    return result;
}
