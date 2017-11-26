#ifndef SHIMS_SDL2_VIDEO_H
#define SHIMS_SDL2_VIDEO_H

#include "shim.h"

#include <GL/glew.h>

SHIM ( SDL_Window*, SDL_CreateWindow,
       const char*,
       int,
       int,
       int,
       int,
       Uint32 );

SHIM ( SDL_Renderer*, SDL_CreateRenderer,
       SDL_Window*,
       int,
       Uint32 );


SHIM ( void, SDL_RenderPresent, SDL_Renderer* );

SHIM ( int,  SDL_CreateWindowAndRenderer,
       int,
       int,
       Uint32,
       SDL_Window * *,
       SDL_Renderer * * );

SHIM ( void*, SDL_GL_GetProcAddress, const char* );


SHIM ( void,  SDL_GL_SwapWindow,
       SDL_Window* );

SHIM ( void,  SDL_SetWindowTitle,
       SDL_Window*,
       const char* );

SHIM ( int, SDL_SetWindowDisplayMode,
       SDL_Window*,
       const SDL_DisplayMode* );

SHIM ( void, SDL_DestroyWindow,
       SDL_Window* );

SHIM ( void, SDL_DestroyRenderer,
       SDL_Renderer* );

SHIM ( void, SDL_GetWindowSize,
       SDL_Window*,
       int*,
       int* );

#endif // ifndef SHIMS_SDL2_VIDEO_H
