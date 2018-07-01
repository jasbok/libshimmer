#ifndef SHIMS_SDL_WINDOW_H
#define SHIMS_SDL_WINDOW_H

#include "api/SDL_sym.h"

#include "common/dims.h"

#include <string>

class window
{
    class shim* _shim;

    std::string _title;

    std::string _icon;

public:
    window( class shim* shim );

    virtual ~window() = default;

    void title ( const char* title,
                 const char* icon );

    void title ( char** title,
                 char** icon );
};

#endif // ifndef SHIMS_SDL_WINDOW_H
