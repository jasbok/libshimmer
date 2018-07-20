#include "video.h"

#include "shim.h"

video::video( class shim* shim )
    : _shim ( shim ),
      _source_surface ( nullptr ),
      _renderer ( nullptr )
{}

video::~video() {
    if ( _source_surface == nullptr ) {
        sym::SDL_FreeSurface ( _source_surface );
    }
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
            printf ( "[Debug] Using OpenGL mode...\n" );
            _mode = mode::opengl;
        }
        else {
            printf ( "[Debug] Using software mode...\n" );
            _mode = mode::software;
        }
    }
}

void video::update()
{
    if ( !_renderer ) {
        _setup_renderer();
    }

    if ( _mode == mode::software ) {
        _renderer->copy_source (
            static_cast<uint8_t*>( _source_surface->pixels ),
            _source_resolution,
            4 );
        _renderer->render();
    }
    else {
        _renderer->reset_fbo();
        _renderer->render();
        _renderer->capture_fbo();
    }
}

void video::source_resolution ( const common::dims_2u& dims )
{
    printf ( "[DEBUG] Setting source resolution: %s\n",
             dims.to_json().c_str() );
    _source_resolution = dims;
    _source_surface    = _software_surface ( _source_resolution );

    if ( _renderer ) {
        _renderer->source_resolution ( _source_resolution );
    }
}

void video::target_resolution ( const common::dims_2u& dims )
{
    printf ( "[DEBUG] Setting target resolution: %s\n",
             dims.to_json().c_str() );
    _target_resolution = dims;

    if ( _renderer ) {
        _renderer->target_resolution ( _target_resolution );
    }
}

void video::_setup_opengl_context()
{
    _gl_context = sym::SDL_GL_GetCurrentContext();

    if ( ( _mode == mode::opengl ) && ( _gl_context == nullptr ) ) {
        printf ( "[WARNING] Failed to get current OpenGL context: %s\n",
                 SDL_GetError() );
        printf ( "[INFO] Assuming application is using software mode.\n" );

        _gl_context =
            sym::SDL_GL_CreateContext ( _shim->window.source_window() );

        if ( _gl_context == nullptr ) {
            printf ( "[Error] Unable to create OpenGL context: %s",
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

        printf (
            "[INFO] Application is using the following GL version: %i.%i\n",
            major_version,
            minor_version );

        _mode = mode::opengl;
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
