#include "shim.h"

//
// Main
//
int SDL_Init ( Uint32 flags ) {
    return shim.init ( flags );
}

void SDL_Quit() {
    shim.quit();
}

//
// Event
//
int SDL_PollEvent ( SDL_Event* event )
{
    return shim.events.poll ( event );
}

//
// Input
//
SDL_GrabMode SDL_WM_GrabInput ( SDL_GrabMode mode ) {
    return shim.input.grab ( mode );
}

void SDL_WarpMouse ( Uint16 x, Uint16 y ) {
    shim.input.mouse_warp ( x, y );
}

//
// Video
//
SDL_Surface* SDL_SetVideoMode ( int    width,
                                int    height,
                                int    bitsperpixel,
                                Uint32 flags ) {
    return shim.video.setup ( width, height, bitsperpixel, flags );
}

SDL_Surface* SDL_GetVideoSurface ( void ) {
    return shim.video.surface();
}

int SDL_Flip ( SDL_Surface* screen ) {
    return shim.video.refresh ( screen );
}

void SDL_GL_SwapBuffers ( void ) {
    shim.video.swap_buffers();
}

//
// Window
//
void SDL_WM_SetCaption ( const char* title, const char* icon ) {
    shim.window.title ( title, icon );
}

void SDL_WM_GetCaption ( char** title, char** icon ) {
    shim.window.title ( title, icon );
}
