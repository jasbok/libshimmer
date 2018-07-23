#include "video.h"

#include "shim.h"

#include <GL/glew.h>

const common::logger video::logger =
    common::logger::get ( "shimmer::sdl::video" );

video::video( class shim* shim )
    : _shim ( shim ),
      _source ( nullptr ),
      _target ( nullptr ),
      _renderer ( nullptr )
{
    _limiter.limit ( shim->config.video.limiter.rate );
    _limiter.samples ( shim->config.video.limiter.samples );
}

video::~video()
{
    if ( _source ) sym::SDL_FreeSurface ( _source );
}

SDL_Surface* video::setup ( int w, int h, int bpp, Uint32 flags ) {
    if ( ( w == 0 ) || ( h == 0 ) ) {
        logger.warn ( "Unsupported resolution: {}x{}", w, h );

        return nullptr;
    }

    common::dims_2u requested_resolution = { static_cast<unsigned int>( w ),
                                             static_cast<unsigned int>( h ) };

    _bpp   = bpp;
    _flags = flags;


    if ( flags & SDL_OPENGL ) {
        logger.debug ( "Software requested OpenGL renderer." );
        _mode = mode::opengl;
    }
    else {
        logger.debug ( "Software requested software renderer." );
        _mode = mode::software;
    }

    if ( _renderer == nullptr ) {
        _shim->target_resolution ( requested_resolution );
        _shim->source_resolution ( requested_resolution );

        shimmer::renderer::init();
        _renderer = _create_renderer ( requested_resolution,
                                       requested_resolution );
    }
    else {
        _shim->source_resolution ( requested_resolution );
    }

    return _source;
}

void video::source_resolution ( const common::dims_2u& dims )
{
    logger.debug ( "Setting source resolution: {}", dims.to_json() );
    _source_resolution = dims;
    _source            = _software_surface ( _source_resolution );

    if ( _renderer ) {
        _renderer->source_resolution ( _source_resolution );
    }
}

void video::target_resolution ( const common::dims_2u& dims )
{
    logger.debug ( "Setting target resolution: {}", dims.to_json() );
    _target_resolution = dims;
    _target            = _hardware_surface ( _target_resolution );

    if ( _renderer ) {
        _renderer->target_resolution ( _target_resolution );
        _renderer->setup_viewport();
        refresh();
    }
}

SDL_Surface* video::surface() {
    return _source;
}

void video::refresh() {
    _renderer->setup_viewport();

    if ( _mode == mode::software ) {
        refresh ( _source );
    }
    else {
        swap_buffers();
    }
}

int video::refresh ( SDL_Surface* screen )
{
    int ret = 0;

    if ( screen == _source  ) {
        if ( _limiter.check() ) return ret;

        _renderer->copy_source ( static_cast<uint8_t*>( _source->pixels ),
                                 _source_resolution,
                                 4 );
        _renderer->render();

        sym::SDL_GL_SwapBuffers();
    }
    else {
        ret = sym::SDL_Flip ( screen );
    }

    return ret;
}

void video::refresh ( SDL_Surface* screen,
                      Sint32       x,
                      Sint32       y,
                      Uint32       w,
                      Uint32       h ) {
    if ( screen == _source ) {
        // TODO: Optimise to not refresh the whole screen.
        refresh ( screen );
    }
    else {
        sym::SDL_UpdateRect ( screen, x, y, w, h );
    }
}

void video::refresh ( SDL_Surface* screen,
                      int          numrects,
                      SDL_Rect*    rects ) {
    if ( screen == _source ) {
        // TODO: Optimise to not refresh the whole screen.
        refresh ( screen );
    }
    else {
        sym::SDL_UpdateRects ( screen, numrects, rects );
    }
}

void video::swap_buffers() {
    if ( _limiter.check() ) return;

    _renderer->reset_fbo();
    _renderer->render();

    sym::SDL_GL_SwapBuffers();

    _renderer->capture_fbo();
}

SDL_Surface* video::_create_surface()
{
    _target = _hardware_surface ( _target_resolution );

    if ( _source ) {
        sym::SDL_FreeSurface ( _source );
    }

    _source = _software_surface ( _source_resolution );

    return _source;
}

SDL_Surface* video::_software_surface ( const common::dims_2u& dims )
{
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;
#else // if SDL_BYTEORDER == SDL_BIG_ENDIAN
    Uint32 rmask = 0x000000ff;
    Uint32 gmask = 0x0000ff00;
    Uint32 bmask = 0x00ff0000;
    Uint32 amask = 0xff000000;
#endif // if SDL_BYTEORDER == SDL_BIG_ENDIAN

    return SDL_CreateRGBSurface ( SDL_HWSURFACE,
                                  static_cast<int>( dims.width ),
                                  static_cast<int>( dims.height ),
                                  32,
                                  rmask,
                                  gmask,
                                  bmask,
                                  amask );
}

SDL_Surface* video::_hardware_surface ( const common::dims_2u& dims )
{
    return sym::SDL_SetVideoMode (
        static_cast<int>( dims.width ),
        static_cast<int>( dims.height ),
        32,
        SDL_HWSURFACE | SDL_OPENGL |
        SDL_RESIZABLE | SDL_DOUBLEBUF );
}

std::unique_ptr<shimmer::renderer> video::_create_renderer (
    const common::dims_2u& source,
    const common::dims_2u& target )
{
    auto renderer = std::make_unique<shimmer::renderer>( &_shim->config );

    if ( _mode == mode::software ) renderer->flip_target ( true );

    renderer->source_resolution ( source );
    renderer->target_resolution ( target );

    return renderer;
}
