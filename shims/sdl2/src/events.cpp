#include "events.h"

#include "shim.h"

events::events( class shim* shim )
    : _shim ( shim )
{}


int events::poll ( SDL_Event* event )
{
    int result = sym::SDL_PollEvent ( event );

    _process ( event );

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

common::dims_2u events::_resize_dims ( SDL_WindowEvent& event )
{
    return { static_cast<unsigned int>( event.data1 ),
             static_cast<unsigned int>( event.data2 ) };
}

void events::_process ( SDL_Event* event )
{
    if ( event ) {
        switch ( event->type ) {
        case SDL_MOUSEMOTION:

            // _process_mouse ( event );
            break;

        case SDL_WINDOWEVENT:

            switch ( event->window.event ) {
            case SDL_WINDOWEVENT_RESIZED:

                // case SDL_WINDOWEVENT_SIZE_CHANGED:
                // TODO: Check whether we need to handle both resize events.
                _process ( event->window );
                event->type = SDL_FIRSTEVENT;
                break;
            }
            break;

        default:
            break;
        }
    }
}

// void events::_process_mouse ( SDL_Event* event )
// {
//    _shim->input.mouse_motion_absolute ( event->motion.x,
//                                         event->motion.y );
//    _shim->input.mouse_motion_relative ( event->motion.xrel,
//                                         event->motion.yrel );
// }

void events::_process ( SDL_WindowEvent& event )
{
    int width  = event.data1;
    int height = event.data2;

    if ( _is_valid_resize ( width, height ) ) {
        _shim->target_resolution ( _resize_dims ( event ) );
    }

    // Do not propagate resize event to application
    event.data1 = static_cast<Sint32>( _source_resolution.width );
    event.data2 = static_cast<Sint32>( _source_resolution.height );
}
