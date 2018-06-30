#ifndef SHIMS_SDL_SHIM_H
#define SHIMS_SDL_SHIM_H

#include "events.h"
#include "input.h"
#include "video.h"
#include "window.h"

#include "api/SDL_sym.h"

#include "shimmer/configuration.h"

#include <memory>

class events;

class shim
{
    //
    // Main
    //
    Uint32 _flags;

public:
    shim();

    virtual ~shim();

    struct shimmer::config config;

    class events events;

    class input input;

    class video video;

    class window window;

    //
    // Main
    //
    int  init ( Uint32 flags );

    void quit();
};

extern class shim shim;

#endif // ifndef SHIMS_SDL_SHIM_H
