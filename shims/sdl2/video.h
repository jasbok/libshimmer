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
        renderer,
        opengl
    };
    enum mode _mode;

    SDL_Renderer* _sdl_renderer     = nullptr;
    bool _use_software_sdl_renderer = false;
    SDL_Texture* _sdl_render_target;

    std::unique_ptr<shimmer::renderer> _renderer;

public:
    static const common::logger& logger;

    video( class shim* shim );

    virtual ~video();

    SDL_Surface* source_surface();

    void         setup ( int    w,
                         int    h,
                         Uint32 flags );

    SDL_Renderer* renderer ( SDL_Window* window,
                             int         index,
                             Uint32      flags );

    void            update();

    common::dims_2u source_resolution();

    void            source_resolution ( const common::dims_2u& res );

    void            target_resolution ( const common::dims_2u& res );

    void            update ( SDL_Renderer* renderer );

    void            size ( SDL_Renderer* renderer,
                           int*          w,
                           int*          h );

    void destroy ( SDL_Renderer* renderer );

private:
    SDL_Surface* _software_surface ( const common::dims_2u& dims );

    void         _setup_opengl_context();

    void         _setup_renderer();

    void         _setup_sdl_render_target();
};

#endif // ifndef SHIMS_SDL2_VIDEO_H
