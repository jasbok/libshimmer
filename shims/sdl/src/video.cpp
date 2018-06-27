#include "video.h"

#include "shim.h"

#include <GL/glew.h>

video::video( class shim* shim )
    : _shim ( shim )
{
    _limiter.limit ( 0 );
    _limiter.samples ( 3 );
}

common::dims_2u video::resolution() {
    return _resolution;
}

SDL_Surface* video::setup ( int w, int h, int bpp, Uint32 flags ) {
    if ( ( w == 0 ) || ( h == 0 ) ) return nullptr;

    _resolution = { static_cast<unsigned int>( w ),
                    static_cast<unsigned int>( h ) };

    _bpp = bpp;

    _flags = flags;

    if ( !_surface ) {
        resize ( w, h );
        _shim->window.dims ( _resolution );

        if ( _renderer == nullptr ) renderer::init();

        _renderer = std::make_unique<renderer>( _shim );
        _renderer->internal_resolution ( _resolution );

        _renderer->capture();
    }
    else {
        _renderer->internal_resolution ( _resolution );
    }

    return _surface;
}

void video::resize ( int w, int h )
{
    _surface = sym::SDL_SetVideoMode (
        w, h, 32,
        SDL_HWSURFACE | SDL_OPENGL |
        SDL_RESIZABLE | SDL_DOUBLEBUF );
}

SDL_Surface* video::surface() {
    return _surface;
}

int video::refresh ( SDL_Surface* screen )
{
    _renderer->render();

    auto ret = sym::SDL_Flip ( screen );

    _renderer->capture();

    return ret;
}

void video::swap_buffers() {
    if ( _limiter.check() ) return;

    _renderer->render();

    sym::SDL_GL_SwapBuffers();

    _renderer->capture();
}
