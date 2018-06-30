#include "video.h"

#include "shim.h"

#include "shimmer/input.h"
#include "shimmer/video.h"

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

common::dims_2f video::aspect()
{
    return _aspect;
}

common::dims_2f video::absolute_transform()
{
    return _absolute_transform;
}

common::dims_2f video::relative_transform()
{
    return _relative_transform;
}

SDL_Surface* video::setup ( int w, int h, int bpp, Uint32 flags ) {
    if ( ( w == 0 ) || ( h == 0 ) ) return nullptr;

    if ( flags & SDL_OPENGL ) {
        printf ( "[DEBUG] Software requested OpenGL renderer.\n" );
        _mode = mode::opengl;
    }
    else {
        printf ( "[DEBUG] Software requested software renderer.\n" );
        _mode = mode::software;
    }

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

    _calculate_transforms();

    _renderer->resize();

    return _surface;
}

void video::resize ( int w, int h )
{
    _surface = sym::SDL_SetVideoMode (
        w, h, 32,
        SDL_HWSURFACE | SDL_OPENGL |
        SDL_RESIZABLE | SDL_DOUBLEBUF );

    _calculate_transforms();

    if ( _renderer ) _renderer->resize();
}

SDL_Surface* video::surface() {
    return _surface;
}

int video::refresh ( SDL_Surface* screen )
{
    int ret = 0;

    if ( screen == _surface ) {
        _renderer->render();

        sym::SDL_GL_SwapBuffers();

        // ret = sym::SDL_Flip ( screen );

        _renderer->capture();
    }
    else {
        ret = sym::SDL_Flip ( screen );
    }

    return ret;
}

void video::swap_buffers() {
    if ( _limiter.check() ) return;

    _renderer->render();

    sym::SDL_GL_SwapBuffers();

    _renderer->capture();
}

void video::_calculate_transforms()
{
    _aspect = shimmer::video::aspect_transform ( _resolution,
                                                 _shim->window.dims(),
                                                 _shim->config );

    _absolute_transform = shimmer::input::absolute_transform ( _resolution,
                                                               _shim->window.dims(),
                                                               _aspect );

    _relative_transform = shimmer::input::relative_transform ( _resolution,
                                                               _shim->window.dims() );
}
