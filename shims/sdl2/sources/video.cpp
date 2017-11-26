#include "video.h"

#include "SDL_render.h"


SDL_Window* SDL_CreateWindow ( const char* title,
                               int         x,
                               int         y,
                               int         w,
                               int         h,
                               Uint32      flags ) {
    SHIM_LOG();

    std::string wtitle = title;
    glpp::coords_2i coords ( x, y );
    glpp::dims_2u   dims ( w, h );

    libshimmer->create_window ( wtitle, coords, dims );

    // if ( libshimmer->scaling_enabled() )

    flags |= SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL;

    shim.window = sym::SDL_CreateWindow ( wtitle.c_str(),
                                          coords.x,
                                          coords.y,
                                          dims.width,
                                          dims.height,
                                          flags );

    return shim.window;
}

SDL_Renderer* SDL_CreateRenderer ( SDL_Window* window,
                                   int         index,
                                   Uint32      flags ) {
    SHIM_LOG ( 10 );
    shim.renderer = sym::SDL_CreateRenderer ( window, index, flags );

    int w, h;
    SDL_GetWindowSize ( window, &w, &h );

    shim.target = SDL_CreateTexture ( shim.renderer,
                                      SDL_PIXELFORMAT_ABGR8888,
                                      SDL_TEXTUREACCESS_TARGET,
                                      w, h );

    SDL_SetRenderTarget ( shim.renderer, shim.target );

    glewExperimental = GL_TRUE;

    GLenum glew_err = glewInit();

    if ( glew_err ) {
        std::cerr << "Error) Unable to initialise GLEW: "
                  << glewGetErrorString ( glew_err ) << std::endl;
    }

    libshimmer->init_renderer();

    libshimmer->activate_application_texture();
    SDL_GL_BindTexture ( shim.target, nullptr, nullptr );

    return shim.renderer;
}

int SDL_CreateWindowAndRenderer ( int            width,
                                  int            height,
                                  Uint32         window_flags,
                                  SDL_Window**   window,
                                  SDL_Renderer** renderer ) {
    SHIM_LOG ( 10 );

    return sym::SDL_CreateWindowAndRenderer ( width,
                                              height,
                                              window_flags,
                                              window,
                                              renderer );
}

void SDL_RenderPresent ( SDL_Renderer* renderer ) {
    SHIM_LOG ( 10 );

    if ( ( shim.renderer == renderer ) && ( shim.target != nullptr ) ) {
        libshimmer->refresh_display();

        glBindFramebuffer ( GL_FRAMEBUFFER, 0 );
        SDL_GL_SwapWindow ( shim.window );
    }
    else {
        sym::SDL_RenderPresent ( renderer );
    }
}

void SDL_GL_SwapWindow ( SDL_Window* window ) {
    SHIM_LOG ( 1 );
    sym::SDL_GL_SwapWindow ( window );
}
