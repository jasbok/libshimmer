#ifndef LIBSHIMMER_RENDERER_RENDERER_H
#define LIBSHIMMER_RENDERER_RENDERER_H

#include "renderer_api.h"

namespace shimmer
{
class renderer :  public renderer_api
{
public:
    renderer();

    virtual ~renderer() {}

    void refresh() override;

    void resize ( int* width,
                  int* height ) override;
};
}

#endif // ifndef LIBSHIMMER_RENDERER_RENDERER_H
