#include "video.h"

video::video( class shimmer::shimmer* lib )
    : _lib ( lib )
{}

SDL_Surface* video::setup ( int w, int h, int bpp, Uint32 flags ) {
    _resolution = { static_cast<unsigned int>( w ),
                    static_cast<unsigned int>( h ) };

    _bpp = bpp;

    _flags = flags;

    // _lib->create_window ( _resolution );

    if ( !_surface ) {
        _surface = sym::SDL_SetVideoMode (
            1920,
            1080,

            //            static_cast<int>( _resolution.width ),
            //            static_cast<int>( _resolution.height ),
            32,
            SDL_HWSURFACE | SDL_OPENGL |
            SDL_RESIZABLE | SDL_DOUBLEBUF );
    }

    // init_renderer();

    // _lib->application_texture_flip_y ( true );

    // _lib->create_application_framebuffer();

    return _surface;
}

SDL_Surface* video::surface() {
    return _surface;
}

int video::refresh ( SDL_Surface* screen )
{
    // if ( _lib->limit_refresh_rate() ) return 0;

    // libshimmer->refresh_display();

    return sym::SDL_Flip ( screen );
}

void video::swap_buffers() {
    // if ( _lib->limit_refresh_rate() ) return;

    // _lib->unbind_application_framebuffer();

    // _lib->refresh_display();

    sym::SDL_GL_SwapBuffers();

    // _lib->bind_application_framebuffer();
}

void video::init_renderer() {
    glewExperimental = GL_TRUE;
    GLenum glew_err = glewInit();

    if ( glew_err ) {
        std::cerr << "Error) Unable to initialise GLEW: "
                  << glewGetErrorString ( glew_err ) << std::endl;
    }

    _lib->init_renderer();
}
