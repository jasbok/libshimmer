#ifndef SHIMS_SDL_WINDOW_H
#define SHIMS_SDL_WINDOW_H

#include "api/SDL_sym.h"

#include "common/dims.h"

#include <string>

class window
{
    class shim* _shim;

    common::dims_2u _dims;

    std::string _window_title;

public:
    window( class shim* shim );

    virtual ~window() = default;


    void            dims ( const common::dims_2u& dims );

    common::dims_2u dims();

    void            resize ( int& w,
                             int& h );

    void title ( const char* title,
                 const char* icon );

    void title ( char** title,
                 char** icon );
};

#endif // ifndef SHIMS_SDL_WINDOW_H
