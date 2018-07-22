#include "shim.h"

int SDL_Init ( Uint32 flags ) {
    auto ret = sym::SDL_Init ( flags );

    shim.init ( flags );

    return ret;
}

void SDL_Quit() {
    shim.quit();
    sym::SDL_Quit();
}

int SDL_PollEvent ( SDL_Event* event )
{
    return shim.events.poll ( event );
}

Uint32 SDL_GetMouseState ( int* x,
                           int* y ) {
    return shim.input.mouse_state ( x, y );
}

SDL_Window* SDL_CreateWindow ( const char* title,
                               int         x,
                               int         y,
                               int         w,
                               int         h,
                               Uint32      flags )
{
    return shim.window.setup ( title, x, y, w, h, flags );
}

SDL_Surface* SDL_GetWindowSurface ( SDL_Window* window ) {
    return shim.window.surface ( window );
}

int SDL_UpdateWindowSurface ( SDL_Window* window ) {
    return shim.window.update ( window );
}

void SDL_GL_SwapWindow ( SDL_Window* window ) {
    shim.window.update ( window );
}

SDL_Renderer* SDL_CreateRenderer ( SDL_Window* window,
                                   int         index,
                                   Uint32      flags )
{
    return shim.video.renderer ( window, index, flags );
}

void SDL_RenderPresent ( SDL_Renderer* renderer )
{
    shim.video.update ( renderer );
}

void SDL_SetWindowTitle ( SDL_Window* window,
                          const char* title ) {
    shim.window.title ( window, title );
}

void SDL_DestroyRenderer ( SDL_Renderer* renderer ) {
    shim.video.destroy ( renderer );
}

void SDL_GetWindowSize ( SDL_Window* window,
                         int*        w,
                         int*        h ) {
    shim.window.size ( window, w, h );
}

void SDL_SetWindowSize ( SDL_Window* window,
                         int         w,
                         int         h ) {
    shim.window.resize ( window, w, h );
}

void SDL_RenderGetLogicalSize ( SDL_Renderer* renderer,
                                int*          w,
                                int*          h ) {
    shim.video.size ( renderer, w, h );
}
