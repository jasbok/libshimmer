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

SHIM ( void, SDL_RenderPresent, SDL_Renderer* );


SHIM ( GLenum, glewInit, void );

#endif // ifndef SHIMS_SDL2_VIDEO_H
