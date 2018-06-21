#ifndef SHIMS_SDL_VIDEO_H
#define SHIMS_SDL_VIDEO_H

#include "api/SDL_sym.h"

#include "renderer.h"

#include "common/dims.h"
#include "common/limiter.h"

class video
{
    class shim* _shim;

    SDL_Surface* _surface;

    int _bpp;

    Uint32 _flags;

    common::dims_2u _resolution;

    std::unique_ptr<renderer> _renderer;

    common::limiter _limiter;

public:
    video( class shim* shim );

    virtual ~video() = default;

    common::dims_2u resolution();

    SDL_Surface*    setup ( int    w,
                            int    h,
                            int    bpp,
                            Uint32 flags );

    void resize ( unsigned int w,
                  unsigned int h );

    SDL_Surface* surface();

    int          refresh ( SDL_Surface* screen );

    void         swap_buffers();
};

#endif // ifndef SHIMS_SDL_VIDEO_H
