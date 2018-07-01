#ifndef SHIMS_SDL_VIDEO_H
#define SHIMS_SDL_VIDEO_H

#include "api/SDL_sym.h"

#include "renderer.h"

#include "common/dims.h"
#include "common/limiter.h"

class video
{
    class shim* _shim;

    SDL_Surface* _source;

    SDL_Surface* _target;

    enum mode {
        software,
        opengl
    };
    enum mode _mode;

    int _bpp;

    Uint32 _flags;

    common::dims_2u _source_resolution;

    common::dims_2u _target_resolution;


    std::unique_ptr<renderer> _renderer;

    common::limiter _limiter;

public:
    video( class shim* shim );

    virtual ~video() = default;


    void         source_resolution ( const common::dims_2u& dims );

    void         target_resolution ( const common::dims_2u& dims );

    SDL_Surface* setup ( int    w,
                         int    h,
                         int    bpp,
                         Uint32 flags );

    SDL_Surface*              surface();

    int                       refresh ( SDL_Surface* screen );

    void                      swap_buffers();

    SDL_Surface*              _source_surface ( const common::dims_2u& dims );

    SDL_Surface*              _target_surface ( const common::dims_2u& dims );

    std::unique_ptr<renderer> _create_renderer ( const common::dims_2u& source,
                                                 const common::dims_2u& target );
};

#endif // ifndef SHIMS_SDL_VIDEO_H
