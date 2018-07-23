#include "video.h"

#include "shim.h"

const common::logger& video::logger = common::logger::get (
    "shimmer::sdl2::video" );

video::video( class shim* shim )
    : _shim ( shim ),
      _source_surface ( nullptr ),
      _renderer ( nullptr )
{}

video::~video() {
    if ( _source_surface == nullptr ) sym::SDL_FreeSurface ( _source_surface );

    if ( _sdl_renderer ) sym::SDL_DestroyRenderer ( _sdl_renderer );

    if ( _sdl_render_target ) sym::SDL_DestroyTexture ( _sdl_render_target );
}

SDL_Surface* video::source_surface() {
    if ( _source_surface == nullptr ) {
        _source_surface = _software_surface ( _source_resolution );
    }

    return _source_surface;
}

void video::setup ( int    w,
                    int    h,
                    Uint32 flags ) {
    _source_resolution = { static_cast<unsigned int>( w ),
                           static_cast<unsigned int>( h ) };

    if ( _renderer == nullptr ) {
        _target_resolution = _source_resolution;
        _flags             = flags;

        if ( _flags & SDL_WINDOW_OPENGL ) {
            logger.info ( "Using OpenGL mode..." );
            _mode = mode::opengl;
        }
        else {
            logger.info ( "Using software mode..." );
            _mode = mode::software;
        }

        _shim->source_resolution ( _source_resolution );
        _shim->target_resolution ( _target_resolution );
    }
}

SDL_Renderer* video::renderer ( SDL_Window* window, int index, Uint32 flags )
{
    if ( _use_software_sdl_renderer ) {
        logger.info ( "Creating software SDL Renderer." );

        _sdl_renderer = sym::SDL_CreateSoftwareRenderer ( source_surface() );
        _mode         = video::mode::software;
    }
    else if ( !_sdl_renderer ) {
        logger.info ( "Creating OpenGL SDL Renderer." );

        _sdl_renderer = sym::SDL_CreateRenderer ( window, index, flags );

        _mode = video::mode::renderer;
        _setup_renderer();
        _setup_sdl_render_target();
    }

    return _sdl_renderer;
}

void video::update()
{
    if ( !_renderer ) {
        _setup_renderer();
    }

    if ( _renderer ) {
        if ( _mode == mode::software ) {
            _renderer->copy_source (
                static_cast<uint8_t*>( _source_surface->pixels ),
                _source_resolution,
                4 );
            _renderer->render();
        }
        else if ( _mode == mode::opengl ) {
            _renderer->reset_fbo();
            _renderer->render();
            _renderer->capture_fbo();
        }
        else {
            _renderer->render();
        }
    }
}

void video::update ( SDL_Renderer* renderer )
{
    if ( renderer == _sdl_renderer ) {
        update();
        shim.window.update();
    }
    else {
        sym::SDL_RenderPresent ( renderer );
    }
}

common::dims_2u video::source_resolution() {
    return _source_resolution;
}

void video::source_resolution ( const common::dims_2u& dims )
{
    if ( _source_resolution != dims ) {
        logger.debug ( "Setting source resolution: {}", dims.to_json() );
        _source_resolution = dims;
        _source_surface    = _software_surface ( _source_resolution );

        if ( _renderer ) {
            _renderer->source_resolution ( _source_resolution );
        }

        if ( _mode == mode::renderer ) {
            _setup_sdl_render_target();
        }
    }
}

void video::target_resolution ( const common::dims_2u& dims )
{
    if ( _target_resolution != dims ) {
        logger.debug ( "Setting target resolution: {}", dims.to_json() );

        _target_resolution = dims;

        if ( _renderer ) {
            _renderer->target_resolution ( _target_resolution );
        }
    }
}

void video::size ( SDL_Renderer* renderer, int* w, int* h )
{
    if ( renderer == _sdl_renderer ) {
        auto size = _source_resolution;
        *w = static_cast<int>( size.width );
        *h = static_cast<int>( size.height );
    }
    else {
        sym::SDL_RenderGetLogicalSize ( renderer, w, h );
    }
}

void video::destroy ( SDL_Renderer* renderer ) {
    if ( renderer != _sdl_renderer ) {
        sym::SDL_DestroyRenderer ( renderer );
    }
}

void video::_setup_opengl_context()
{
    _gl_context = sym::SDL_GL_GetCurrentContext();

    if ( _mode == mode::software ) {
        logger.info ( "Assuming application is using software mode." );

        _gl_context =
            sym::SDL_GL_CreateContext ( _shim->window.source_window() );

        if ( _gl_context == nullptr ) {
            logger.error ( "Unable to create OpenGL context: {}",
                           SDL_GetError() );
        }
    }
    else if ( ( ( _mode == mode::opengl ) || ( _mode == mode::renderer ) )
              && ( _gl_context == nullptr ) ) {
        logger.warn ( "Failed to get current OpenGL context: {}",
                      SDL_GetError() );
        logger.info ( "Assuming application is using software mode." );

        _gl_context = sym::SDL_GL_CreateContext (
            _shim->window.source_window() );

        if ( _gl_context == nullptr ) {
            logger.error ( "Unable to create OpenGL context: {}",
                           SDL_GetError() );
        }

        _mode = mode::software;
    }
    else {
        int major_version = 0;
        int minor_version = 0;

        sym::SDL_GL_GetAttribute ( SDL_GL_CONTEXT_MAJOR_VERSION,
                                   &major_version );
        sym::SDL_GL_GetAttribute ( SDL_GL_CONTEXT_MINOR_VERSION,
                                   &minor_version );

        logger.info ( "Application is using the following GL version: {}.{}",
                      major_version,
                      minor_version );
    }
}

void video::_setup_renderer()
{
    _setup_opengl_context();

    shimmer::renderer::init();
    _renderer = std::make_unique<shimmer::renderer>( &_shim->config );

    _renderer->source_resolution ( _source_resolution );
    _renderer->target_resolution ( _target_resolution );

    if ( _mode == mode::software ) {
        _renderer->flip_target ( true );
    }
    else if ( _mode == mode::renderer ) {
        _renderer->flip_target ( true );
    }
}

void video::_setup_sdl_render_target()
{
    if ( _sdl_render_target ) {
        sym::SDL_DestroyTexture ( _sdl_render_target );
    }

    _sdl_render_target = sym::SDL_CreateTexture ( _sdl_renderer,
                                                  SDL_PIXELFORMAT_RGB24,
                                                  SDL_TEXTUREACCESS_TARGET,
                                                  _source_resolution.width,
                                                  _source_resolution.height );

    sym::SDL_SetRenderTarget ( _sdl_renderer, _sdl_render_target );

    if ( _renderer ) {
        _renderer->activate_source_texture_unit();
        sym::SDL_GL_BindTexture ( _sdl_render_target, nullptr, nullptr );
    }
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

    return SDL_CreateRGBSurface ( _flags,
                                  static_cast<int>( dims.width ),
                                  static_cast<int>( dims.height ),
                                  32,
                                  rmask,
                                  gmask,
                                  bmask,
                                  amask );
}
