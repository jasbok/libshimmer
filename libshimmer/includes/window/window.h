#ifndef LIBSHIMMER_WINDOW_WINDOW_H
#define LIBSHIMMER_WINDOW_WINDOW_H

#include "window_api.h"

namespace shimmer
{
class window : public window_api
{
public:
    window();

    virtual ~window() {}

    void resize ( int* width,
                  int* height ) override;

    void title ( std::string* title ) override;
};
}

#endif // ifndef LIBSHIMMER_WINDOW_WINDOW_H
