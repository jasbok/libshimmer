#ifndef SHIMS_SDL2_SHIM_H
#define SHIMS_SDL2_SHIM_H

#include "events.h"
#include "input.h"
#include "video.h"
#include "window.h"

#include "shimmer/configuration.h"

#include "api/SDL2_sym.h"

class shim
{
    Uint32 _flags;

public:
    shim();

    virtual ~shim() = default;

    shimmer::config config;

    class events events;

    class input input;

    class video video;

    class window window;

    void init ( Uint32 flags );

    void quit();

    void source_resolution ( const common::dims_2u& dims );

    void target_resolution ( const common::dims_2u& dims );
};

extern class shim shim;

#endif // ifndef SHIMS_SDL2_SHIM_H
