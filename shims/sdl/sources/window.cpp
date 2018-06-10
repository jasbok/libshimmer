#include "window.h"

window::window( shimmer::shimmer* lib )
    : _lib ( lib )
{}

void window::resize ( int& w, int& h )
{
    // if ( _surface && ( w <= 1920 ) && ( h <= 1080 ) ) {
    if ( ( w <= 1920 ) && ( h <= 1080 ) ) {
        _dims = { static_cast<unsigned int>( w ),
                  static_cast<unsigned int>( h ) };

        // _lib->resize_window ( _dims );
    }

    // Do not propagate resize event to application
    w = static_cast<int>( _lib->app_surface_dims().width );
    h = static_cast<int>( _lib->app_surface_dims().height );
}

void window::title ( const char* title, const char* icon ) {
    std::string title_str ( title );

    _window_title = title_str;
    _lib->set_window_title ( title_str );

    sym::SDL_WM_SetCaption ( title_str.c_str(), icon );
}

void window::title ( char** title, char** icon ) {
    sym::SDL_WM_GetCaption ( title, icon );

    // TODO: Check that shim.window_title.size() is always smaller than
    // current
    // title.
    if ( !_window_title.empty() ) {
        strcpy ( *title, _window_title.c_str() );
    }
}
