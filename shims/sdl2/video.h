#ifndef SHIMS_SDL2_VIDEO_H
#define SHIMS_SDL2_VIDEO_H

#include "api/SDL2_sym.h"

#include "common/dims.h"

#include "shimmer/renderer.h"

#include <memory>

class video
{
    Uint32 _flags;

    class shim* _shim;

    SDL_Surface* _source_surface;
    SDL_Renderer* _source_renderer;

    SDL_GLContext _gl_context;

    common::dims_2u _source_resolution;
    common::dims_2u _target_resolution;

    enum class mode {
        software,
        opengl
    };
    enum mode _mode;

    std::unique_ptr<shimmer::renderer> _renderer;

public:
    video( class shim* shim );

    virtual ~video();

    SDL_Surface* source_surface();

    void         setup ( int    w,
                         int    h,
                         Uint32 flags );

    void update();

    void source_resolution ( const common::dims_2u& res );

    void target_resolution ( const common::dims_2u& res );

private:
    SDL_Surface* _software_surface ( const common::dims_2u& dims );

    void         _setup_opengl_context();

    void         _setup_renderer();
};

#endif // ifndef SHIMS_SDL2_VIDEO_H
