#include "window.h"

#include "shim.h"

window::window( class shim* shim )
    : _shim ( shim )
{}

void window::dims ( const common::dims_2u& dims ) {
    _dims = dims;
}

common::dims_2u window::dims() {
    return _dims;
}

void window::resize ( int& w, int& h )
{
    _dims = { static_cast<unsigned int>( w ),
              static_cast<unsigned int>( h ) };

    // Do not propagate resize event to application
    w = static_cast<int>( _shim->video.resolution().width );
    h = static_cast<int>( _shim->video.resolution().height );
}

void window::title ( const char* title, const char* icon ) {
    std::string title_str ( title );

    _window_title = title_str;

    sym::SDL_WM_SetCaption ( ( "[shim] " + title_str ).c_str(), icon );
}
