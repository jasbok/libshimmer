#include "video.h"

#include "shim.h"

void capture_application_target() {
    SDL_GL_BindTexture ( shim.target, nullptr, nullptr );
    libshimmer->capture_application_texture();
}

void set_application_render_target() {
    if ( shim.target ) {
        SDL_DestroyTexture ( shim.target );
    }

    int w, h;

    SDL_GetWindowSize ( shim.window, &w, &h );

    shim.target = SDL_CreateTexture ( shim.renderer,
                                      SDL_PIXELFORMAT_BGRA32,
                                      SDL_TEXTUREACCESS_TARGET,
                                      w, h );

    SDL_SetRenderTarget ( shim.renderer, shim.target );

    capture_application_target();
}

void init_renderer() {
    glewExperimental = GL_TRUE;
    GLenum glew_err = glewInit();

    if ( glew_err ) {
        std::cerr << "Error) Unable to initialise GLEW: "
                  << glewGetErrorString ( glew_err ) << std::endl;
    }

    libshimmer->init_renderer();
}

SDL_Window* SDL_CreateWindow ( const char* title,
                               int         x,
                               int         y,
                               int         w,
                               int         h,
                               Uint32      flags ) {
    if ( !libshimmer ) {
        init_shimmer();
    }

    std::string wtitle = title;
    shimmer::coords_2i coords ( x, y );
    shimmer::dims_2u   dims ( w, h );
    libshimmer->create_window ( wtitle, coords, dims );

    if ( !shim.window ) {
        // flags &= ~SDL_WINDOW_RESIZABLE;
        Uint32 shimmer_flags = flags | SDL_WINDOW_RESIZABLE |
                               SDL_WINDOW_OPENGL;

        shim.window = sym::SDL_CreateWindow ( title,
                                              coords.x,
                                              coords.y,
                                              dims.width,
                                              dims.height,
                                              flags );
    }
    else {
        set_application_render_target();
    }

    return shim.window;
}

SDL_Renderer* SDL_CreateRenderer ( SDL_Window* window,
                                   int         index,
                                   Uint32      flags ) {
    if (  shim.window == window  ) {
        if ( !shim.renderer ) {
            shim.renderer = sym::SDL_CreateRenderer ( window, -1,
                                                      SDL_RENDERER_ACCELERATED
                                                      |

                                                      SDL_RENDERER_TARGETTEXTURE
                                                      );

            init_renderer();

            set_application_render_target();
        }

        return shim.renderer;
    }

    return sym::SDL_CreateRenderer ( window, index, flags );
}

int SDL_CreateWindowAndRenderer ( int            width,
                                  int            height,
                                  Uint32         window_flags,
                                  SDL_Window**   window,
                                  SDL_Renderer** renderer ) {
    SDL_CreateWindow ( "SDL2 Application", 0, 0, width, height, window_flags
                       );

    if ( !shim.window ) return -1;

    SDL_CreateRenderer ( shim.window, 0, 0 );

    return shim.renderer ? 0 : -1;
}

void SDL_RenderPresent ( SDL_Renderer* renderer ) {
    if ( shim.renderer == renderer ) {
        SDL_SetRenderTarget ( shim.renderer, nullptr );

        libshimmer->refresh_display();

        sym::SDL_RenderPresent ( renderer );

        SDL_SetRenderTarget ( shim.renderer, shim.target );
    }
    else {
        sym::SDL_RenderPresent ( renderer );
    }
}

void SDL_GL_SwapWindow ( SDL_Window* window ) {
    return sym::SDL_GL_SwapWindow ( window );
}

void SDL_SetWindowTitle ( SDL_Window* window,
                          const char* title ) {
    std::string wtitle = title;

    libshimmer->set_window_title ( wtitle );
    sym::SDL_SetWindowTitle ( window, wtitle.c_str() );
}

int SDL_SetWindowDisplayMode ( SDL_Window*            window,
                               const SDL_DisplayMode* mode ) {
    return sym::SDL_SetWindowDisplayMode ( window, mode );
}

void SDL_DestroyWindow ( SDL_Window* window ) {
    if ( shim.window != window ) {
        sym::SDL_DestroyWindow ( window );
    }
}

void SDL_DestroyRenderer ( SDL_Renderer* renderer ) {
    if ( shim.renderer != renderer ) {
        sym::SDL_DestroyRenderer ( renderer );
    }
}

void SDL_GetWindowSize ( SDL_Window* window,
                         int*        w,
                         int*        h ) {
    auto dims = libshimmer->app_surface_dims();

    *w = dims.width;
    *h = dims.height;
}

SDL_Surface* SDL_GetWindowSurface ( SDL_Window* window ) {
    return sym::SDL_GetWindowSurface ( window );
}

void SDL_GL_GetDrawableSize ( SDL_Window* window,
                              int*        w,
                              int*        h ) {
    sym::SDL_GL_GetDrawableSize ( window, w, h );
}

void SDL_GetWindowMaximumSize ( SDL_Window* window,
                                int*        w,
                                int*        h ) {
    sym::SDL_GetWindowMaximumSize ( window, w, h );
}
