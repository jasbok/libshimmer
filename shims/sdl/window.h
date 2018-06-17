#ifndef SHIMS_SDL_WINDOW_H
#define SHIMS_SDL_WINDOW_H

#include "api/SDL_sym.h"
#include "libshimmer/shimmer.h"

class window
{
    class shimmer::shimmer* _lib;

    shimmer::dims_2u _dims;

    shimmer::coords_2i _coords;

    std::string _window_title;

public:
    window( class shimmer::shimmer* lib );

    virtual ~window() = default;


    void resize ( int& w,
                  int& h );

    void title ( const char* title,
                 const char* icon );

    void title ( char** title,
                 char** icon );
};

#endif // ifndef SHIMS_SDL_WINDOW_H
