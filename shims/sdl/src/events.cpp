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

            if ( _is_valid_resize ( event->resize.w, event->resize.h ) ) {
                _shim->target_resolution ( _resize_dims ( event ) );
            }

            // Do not propagate resize event to application
            event->resize.w    = static_cast<int>( _source_resolution.width );
            event->resize.h    = static_cast<int>( _source_resolution.height );
            event->active.type = SDL_NOEVENT;
            result             = 0;

            break;

        default:
            break;
        }
    }

    return result;
}

void events::source_resolution ( const common::dims_2u& dims )
{
    _source_resolution = dims;
}

void events::target_resolution ( const common::dims_2u& dims )
{
    _target_resolution = dims;
}

bool events::_is_valid_resize ( int w, int h )
{
    return ( w > 0 ) && ( h > 0 ) &&
           ( w <= 1920 ) && ( h <= 1080 );
}

common::dims_2u events::_resize_dims ( SDL_Event* event )
{
    return { static_cast<unsigned int>( event->resize.w ),
             static_cast<unsigned int>( event->resize.h ) };
}
