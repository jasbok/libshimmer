#include "mouse.h"

#include "shim.h"

int SDL_CaptureMouse ( SDL_bool enabled )
{
    return sym::SDL_CaptureMouse ( enabled );
}

SDL_Cursor* SDL_GetCursor ( void )
{
    return sym::SDL_GetCursor();
}

SDL_Cursor* SDL_GetDefaultCursor ( void )
{
    return sym::SDL_GetDefaultCursor();
}

void SDL_SetCursor ( SDL_Cursor* cursor )
{
    return sym::SDL_SetCursor ( cursor );
}

SDL_Cursor* SDL_CreateCursor ( const Uint8* data,
                               const Uint8* mask,
                               int          w,
                               int          h,
                               int          hot_x,
                               int          hot_y )
{
    return sym::SDL_CreateCursor ( data, mask, w, h, hot_x, hot_y );
}

SDL_Cursor* SDL_CreateColorCursor ( SDL_Surface* surface,
                                    int          hot_x,
                                    int          hot_y )
{
    return sym::SDL_CreateColorCursor ( surface, hot_x, hot_y );
}

Uint32 SDL_GetGlobalMouseState ( int* x,
                                 int* y )
{
    return sym::SDL_GetGlobalMouseState ( x, y );
}

Uint32 SDL_GetMouseState ( int* x, int* y )
{
    return sym::SDL_GetMouseState ( x, y );
}

Uint32 SDL_GetRelativeMouseState ( int* x, int* y )
{
    return sym::SDL_GetRelativeMouseState ( x, y );
}

int SDL_WarpMouseGlobal ( int x, int y )
{
    return sym::SDL_WarpMouseGlobal ( x, y );
}

void SDL_WarpMouseInWindow ( SDL_Window* window,
                             int         x,
                             int         y )
{
    sym::SDL_WarpMouseInWindow ( window, x, y );
}
