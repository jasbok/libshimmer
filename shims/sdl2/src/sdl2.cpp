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

int SDL_PeepEvents (
    SDL_Event*      events,
    int             numevents,
    SDL_eventaction action,
    Uint32          minType,
    Uint32          maxType )
{
    return sym::SDL_PeepEvents ( events, numevents, action, minType, maxType );
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

SDL_Renderer* SDL_CreateRenderer ( SDL_Window* window,
                                   int         index,
                                   Uint32      flags )
{
    return sym::SDL_CreateRenderer ( window, index, flags );
}

int SDL_CreateWindowAndRenderer ( int            width,
                                  int            height,
                                  Uint32         window_flags,
                                  SDL_Window**   window,
                                  SDL_Renderer** renderer )
{
    return sym::SDL_CreateWindowAndRenderer ( width,
                                              height,
                                              window_flags,
                                              window,
                                              renderer );
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

void SDL_RenderPresent ( SDL_Renderer* renderer )
{
    sym::SDL_RenderPresent ( renderer );
}

void SDL_SetWindowTitle ( SDL_Window* window,
                          const char* title ) {
    shim.window.title ( window, title );
}

int SDL_SetWindowDisplayMode ( SDL_Window*            window,
                               const SDL_DisplayMode* mode ) {
    return sym::SDL_SetWindowDisplayMode ( window, mode );
}

void SDL_DestroyWindow ( SDL_Window* window ) {
    sym::SDL_DestroyWindow ( window );
}

void SDL_DestroyRenderer ( SDL_Renderer* renderer ) {
    sym::SDL_DestroyRenderer ( renderer );
}

void SDL_GetWindowSize ( SDL_Window* window,
                         int*        w,
                         int*        h ) {
    sym::SDL_GetWindowSize ( window, w, h );
}

void SDL_SetWindowSize ( SDL_Window* window,
                         int         w,
                         int         h ) {
    shim.window.resize ( window, w, h );
}
