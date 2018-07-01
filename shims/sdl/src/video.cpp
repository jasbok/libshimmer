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

    _bpp   = bpp;
    _flags = flags;

    source_resolution ( { static_cast<unsigned int>( w ),
                          static_cast<unsigned int>( h ) } );

    return _source;
}

void video::source_resolution ( const common::dims_2u& dims )
{
    _source_resolution = dims;

    if ( !_target ) {
        _target_resolution = _source_resolution;
        _target            = _target_surface ( _target_resolution );
        _source            = _target;
        _renderer          = _create_renderer ( _source_resolution,
                                                _target_resolution );
    }
    else {
        _renderer->source_resolution ( _source_resolution );
    }
}

void video::target_resolution ( const common::dims_2u& dims )
{
    _target_resolution = dims;
    _target            = _target_surface ( _target_resolution );
    _source            = _target;

    if ( _renderer ) {
        _renderer->target_resolution ( _target_resolution );
    }
}

SDL_Surface* video::surface() {
    return _source;
}

int video::refresh ( SDL_Surface* screen )
{
    int ret = 0;

    if ( screen == _source ) {
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

SDL_Surface* video::_source_surface ( const common::dims_2u& dims )
{
    return sym::SDL_SetVideoMode (
        static_cast<int>( dims.width ),
        static_cast<int>( dims.height ),
        32,
        SDL_HWSURFACE | SDL_OPENGL |
        SDL_RESIZABLE | SDL_DOUBLEBUF );
}

SDL_Surface* video::_target_surface ( const common::dims_2u& dims )
{
    return sym::SDL_SetVideoMode (
        static_cast<int>( dims.width ),
        static_cast<int>( dims.height ),
        32,
        SDL_HWSURFACE | SDL_OPENGL |
        SDL_RESIZABLE | SDL_DOUBLEBUF );
}

std::unique_ptr<renderer> video::_create_renderer (
    const common::dims_2u& source,
    const common::dims_2u& target )
{
    if ( _renderer == nullptr ) renderer::init();

    auto renderer = std::make_unique<::renderer>( _shim );

    renderer->source_resolution ( source );
    renderer->target_resolution ( target );

    return renderer;
}
