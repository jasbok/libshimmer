#ifndef LIBSHIMMER_API_WINDOW_API_H
#define LIBSHIMMER_API_WINDOW_API_H

#include <string>

namespace shimmer
{
class window_api
{
public:
    virtual ~window_api () {}

    virtual void resize ( int* width,  int* height ) = 0;

    virtual void title ( std::string* title ) = 0;
};
}

#endif
