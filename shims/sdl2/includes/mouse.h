#ifndef SHIMS_SDL2_MOUSE_H
#define SHIMS_SDL2_MOUSE_H

#include "shim.h"

SHIM ( int, SDL_CaptureMouse,
       SDL_bool enabled );

SHIM ( SDL_Cursor*, SDL_GetCursor,
       void );

SHIM ( SDL_Cursor*, SDL_GetDefaultCursor,
       void );

SHIM ( void, SDL_SetCursor,
       SDL_Cursor* cursor );

SHIM ( SDL_Cursor*, SDL_CreateCursor,
       const Uint8* data,
       const Uint8* mask,
       int w,
       int h,
       int hot_x,
       int hot_y );

SHIM ( SDL_Cursor*, SDL_CreateColorCursor,
       SDL_Surface* surface,
       int hot_x,
       int hot_y );

SHIM ( Uint32, SDL_GetGlobalMouseState,
       int* x,
       int* y );

SHIM ( Uint32, SDL_GetMouseState,
       int* x,
       int* y );

SHIM ( Uint32, SDL_GetRelativeMouseState,
       int* x,
       int* y );

SHIM ( int, SDL_WarpMouseGlobal,
       int x,
       int y );

SHIM ( void, SDL_WarpMouseInWindow,
       SDL_Window* window,
       int x,
       int y );

#endif
