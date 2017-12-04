#ifndef SHIMS_SDL_VIDEO_H
#define SHIMS_SDL_VIDEO_H

#include "shim.h"

void init_renderer();

void setup_video();

SHIM ( SDL_Surface*, SDL_SetVideoMode,
       int width,
       int height,
       int bitsperpixel,
       Uint32 flags );

SHIM ( SDL_Surface*, SDL_GetVideoSurface,
       void );

SHIM ( void,         SDL_UpdateRect,
       SDL_Surface * screen,
       Sint32 x,
       Sint32 y,
       Sint32 w,
       Sint32 h );

SHIM ( void, SDL_UpdateRects,
       SDL_Surface * screen,
       int numrects,
       SDL_Rect * rects );

SHIM ( int,  SDL_Flip,
       SDL_Surface * screen );

SHIM ( void, SDL_GL_SwapBuffers,
       void );

SHIM ( void, SDL_WM_SetCaption,
       const char* title,
       const char* icon );

SHIM ( void, SDL_WM_GetCaption,
       char** title,
       char** icon );

#endif // ifndef SHIMS_SDL_VIDEO_H
