#include "window.h"

#include "shim.h"

#include "api/SDL2_sym.h"

window::window( class shim* shim )
    : _shim ( shim )
{
    _limiter.limit ( shim->config.video.limiter.rate );
    _limiter.samples ( shim->config.video.limiter.samples );
}

window::~window() {}

SDL_Window* window::source_window()
{
    return _source_window;
}

window& window::title ( SDL_Window* window,
                        const char* src_title ) {
    if ( window == _source_window ) {
        _title = src_title;
        sym::SDL_SetWindowTitle ( window, title().c_str() );
    }
    else {
        sym::SDL_SetWindowTitle ( window, src_title );
    }

    return *this;
}

window& window::title ( const std::string& title ) {
    _title = title;

    return *this;
}

std::string window::title() const {
    return "[shimmer] " + _title;
}

SDL_Surface* window::surface ( SDL_Window* window )
{
    if ( window == _source_window ) {
        return shim.video.source_surface();
    }

    return sym::SDL_GetWindowSurface ( window );
}

void window::update() {
    sym::SDL_GL_SwapWindow ( _source_window );
}

int window::update ( SDL_Window* window )
{
    if ( window == _source_window ) {
        if ( !_limiter.check() ) {
            shim.video.update();
            sym::SDL_GL_SwapWindow ( window );
        }

        return 0;
    }

    return sym::SDL_UpdateWindowSurface ( window );
}

SDL_Window* window::setup ( const char* src_title,
                            int         x,
                            int         y,
                            int         w,
                            int         h,
                            Uint32      flags ) {
    _title         = src_title;
    _flags         = flags;
    _source_window = sym::SDL_CreateWindow ( title().c_str(),
                                             x,
                                             y,
                                             w,
                                             h,
                                             flags
                                             | SDL_WINDOW_RESIZABLE
                                             | SDL_WINDOW_OPENGL );

    _shim->video.setup ( w, h, _flags );

    return _source_window;
}

void window::resize ( SDL_Window* window,
                      int         w,
                      int         h ) {
    if ( window == _source_window ) {
        _shim->source_resolution ( {
            static_cast<unsigned int>( w ),
            static_cast<unsigned int>( h )
        } );
    }
    else {
        sym::SDL_SetWindowSize ( window, w, h );
    }
}

void window::size ( SDL_Window* window,
                    int*        w,
                    int*        h ) {
    if ( window == _source_window ) {
        auto size = _shim->video.source_resolution();
        *w = static_cast<int>( size.width );
        *h = static_cast<int>( size.height );
    }
    else {
        sym::SDL_GetWindowSize ( window, w, h );
    }
}

void window::source_resolution ( const common::dims_2u& res )
{
    _source_resolution = res;
}

void window::target_resolution ( const common::dims_2u& res )
{
    _target_resolution = res;
}
