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

bool events::_is_valid_resize ( const common::dims_2u& dims )
{
    return ( dims.width > 0 ) && ( dims.height > 0 ) &&
           ( dims.width <= 1920 ) && ( dims.height <= 1080 );
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
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
            _process ( event->button );
            break;

        case SDL_MOUSEMOTION:
            _process ( event->motion );
            break;

        case SDL_WINDOWEVENT:

            switch ( event->window.event ) {
            case SDL_WINDOWEVENT_RESIZED:

            case SDL_WINDOWEVENT_SIZE_CHANGED:

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

void events::_process ( SDL_MouseMotionEvent& event )
{
    _shim->input.mouse_motion_absolute ( event.x,
                                         event.y );
    _shim->input.mouse_motion_relative ( event.xrel,
                                         event.yrel );
}

void events::_process ( SDL_MouseButtonEvent& event )
{
    _shim->input.mouse_motion_absolute ( event.x,
                                         event.y );
}

void events::_process ( SDL_WindowEvent& event )
{
    auto resize_dims = _resize_dims ( event );

    if ( ( resize_dims != _target_resolution ) &&
         _is_valid_resize ( resize_dims ) ) {
        _shim->target_resolution ( resize_dims );
    }

    // Do not propagate resize event to application
    event.data1 = static_cast<Sint32>( _source_resolution.width );
    event.data2 = static_cast<Sint32>( _source_resolution.height );
}
