#ifndef SHIMS_SDL2_WINDOW_H
#define SHIMS_SDL2_WINDOW_H

#include "api/SDL2_sym.h"

#include "common/dims.h"
#include "common/limiter.h"

#include <string>

class window
{
    class shim* _shim;

    Uint32 _flags;

    SDL_Window* _source_window;

    std::string _title;

    common::limiter _limiter;

    common::dims_2u _source_resolution;
    common::dims_2u _target_resolution;

public:
    window( class shim* shim );

    virtual ~window();

    SDL_Window* source_window();

    window&     title ( SDL_Window* window,
                        const char* title );

    window&      title ( const std::string& title );

    std::string  title() const;

    SDL_Surface* surface ( SDL_Window* window );

    void         update();

    int          update ( SDL_Window* window );

    SDL_Window*  setup ( const char* title,
                         int         x,
                         int         y,
                         int         w,
                         int         h,
                         Uint32      flags );


    void resize ( SDL_Window* window,
                  int         w,
                  int         h );

    void size ( SDL_Window* window,
                int*        w,
                int*        h );

    void source_resolution ( const common::dims_2u& res );

    void target_resolution ( const common::dims_2u& res );
};

#endif // ifndef SHIMS_SDL2_WINDOW_H
