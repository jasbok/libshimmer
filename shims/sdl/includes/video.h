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

SHIM ( SDL_Surface*,         SDL_GetVideoSurface,
       void );

SHIM ( const SDL_VideoInfo*, SDL_GetVideoInfo,
       void );

SHIM ( void,                 SDL_UpdateRect,
       SDL_Surface * screen,
       Sint32 x,
       Sint32 y,
       Sint32 w,
       Sint32 h );

SHIM ( void, SDL_UpdateRects,
       SDL_Surface * screen,
       int numrects,
       SDL_Rect * rects );


SHIM ( SDL_Surface*, SDL_CreateRGBSurface,
       Uint32 flags,
       int width,
       int height,
       int bitsPerPixel,
       Uint32 Rmask,
       Uint32 Gmask,
       Uint32 Bmask,
       Uint32 Amask );

SHIM ( SDL_Surface*, SDL_CreateRGBSurfaceFrom,
       void* pixels,
       int width,
       int height,
       int depth,
       int pitch,
       Uint32 Rmask,
       Uint32 Gmask,
       Uint32 Bmask,
       Uint32 Amask );

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

// SHIM ( void, glBindFramebuffer, GLenum, GLuint );

#endif // ifndef SHIMS_SDL_VIDEO_H
