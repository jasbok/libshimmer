#include "video.h"

#include <chrono>
#include <cmath>

void init_renderer() {
    glewExperimental = GL_TRUE;
    GLenum glew_err = glewInit();

    if ( glew_err ) {
        std::cerr << "Error) Unable to initialise GLEW: "
                  << glewGetErrorString ( glew_err ) << std::endl;
    }

    libshimmer->init_renderer();
}

void setup_video()
{
    shim.video = sym::SDL_SetVideoMode ( shim.window_dims.width,
                                         shim.window_dims.height,
                                         32,
                                         SDL_HWSURFACE | SDL_OPENGL |
                                         SDL_RESIZABLE | SDL_DOUBLEBUF );
}

SDL_Surface* SDL_SetVideoMode ( int    width,
                                int    height,
                                int    bitsperpixel,
                                Uint32 flags ) {
    SHIM_LOG();

    libshimmer->init();
    shim.window_coords = glpp::coords_2i ( 0, 0 );
    shim.window_dims   = glpp::dims_2u ( width, height );
    libshimmer->create_window ( shim.window_coords, shim.window_dims );

    if ( !shim.video ) setup_video();

    init_renderer();
    libshimmer->application_texture_flip_y ( true );

    libshimmer->create_application_framebuffer();

    return shim.video;
}

SDL_Surface* SDL_GetVideoSurface ( void ) {
    SHIM_LOG();

    return shim.video;
}

void SDL_UpdateRect ( SDL_Surface* screen,
                      Sint32       x,
                      Sint32       y,
                      Sint32       w,
                      Sint32       h ) {
    SHIM_LOG();

    sym::SDL_UpdateRect ( screen,
                          x,
                          y,
                          w,
                          h );
}

void SDL_UpdateRects ( SDL_Surface* screen, int numrects, SDL_Rect* rects ) {
    SHIM_LOG();

    sym::SDL_UpdateRects ( screen, numrects, rects );
}

int SDL_Flip ( SDL_Surface* screen ) {
    SHIM_LOG();

    if ( libshimmer->limit_refresh_rate() ) return 0;

    // libshimmer->refresh_display();

    return sym::SDL_Flip ( screen );
}

void SDL_GL_SwapBuffers ( void ) {
    SHIM_LOG();

    if ( libshimmer->limit_refresh_rate() ) return;

    if ( shim.do_resize ) {
        setup_video();

        libshimmer->resize_window ( shim.window_dims );

        shim.do_resize = false;
    }

    libshimmer->unbind_application_framebuffer();

    libshimmer->refresh_display();

    sym::SDL_GL_SwapBuffers();

    libshimmer->bind_application_framebuffer();
    glViewport ( 0,
                 0,
                 libshimmer->app_surface_dims().width,
                 libshimmer->app_surface_dims().height );
}

void SDL_WM_SetCaption ( const char* title, const char* icon ) {
    SHIM_LOG();

    std::string title_str ( title );
    shim.window_title = title_str;
    libshimmer->set_window_title ( title_str );

    sym::SDL_WM_SetCaption ( title_str.c_str(), icon );
}

void SDL_WM_GetCaption ( char** title, char** icon ) {
    SHIM_LOG();

    sym::SDL_WM_GetCaption ( title, icon );

    // TODO: Check that shim.window_title.size() is always smaller than current
    // title.
    if ( !shim.window_title.empty() ) {
        strcpy ( *title, shim.window_title.c_str() );
    }
}
