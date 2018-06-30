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

    SDL_Surface* _software;

    enum mode {
        software,
        opengl
    };
    enum mode _mode;

    int _bpp;

    Uint32 _flags;

    common::dims_2u _resolution;

    common::dims_2f _aspect;

    common::dims_2f _absolute_transform;

    common::dims_2f _relative_transform;

    std::unique_ptr<renderer> _renderer;

    common::limiter _limiter;

public:
    video( class shim* shim );

    virtual ~video() = default;

    common::dims_2u resolution();

    common::dims_2f aspect();

    common::dims_2f absolute_transform();

    common::dims_2f relative_transform();

    SDL_Surface*    setup ( int    w,
                            int    h,
                            int    bpp,
                            Uint32 flags );

    void resize ( int w,
                  int h );

    SDL_Surface* surface();

    int          refresh ( SDL_Surface* screen );

    void         swap_buffers();

    void         _calculate_transforms();
};

#endif // ifndef SHIMS_SDL_VIDEO_H
