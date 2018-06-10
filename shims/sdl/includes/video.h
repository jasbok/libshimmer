#ifndef SHIMS_SDL_VIDEO_H
#define SHIMs_SDL_VIDEO_H

#include "api/sym/SDL_sym.h"
#include "shimmer.h"

class video
{
    class shimmer::shimmer* _lib;

    SDL_Surface* _surface;

    shimmer::dims_2u _resolution;

    int _bpp;

    Uint32 _flags;

public:
    video( class shimmer::shimmer* lib );

    virtual ~video() = default;

    void         init_renderer ( void );

    SDL_Surface* setup ( int    w,
                         int    h,
                         int    bpp,
                         Uint32 flags );

    SDL_Surface* surface();

    int          refresh ( SDL_Surface* screen );

    void         swap_buffers();
};

#endif // ifndef SHIMS_SDL_VIDEO_H
