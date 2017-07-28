#ifndef LIBSHIMMER_API_RENDERER_API_H
#define LIBSHIMMER_API_RENDERER_API_H

namespace shimmer
{
class renderer_api
{
public:
    virtual ~renderer_api() {}

    virtual void refresh() = 0;

    virtual void resize ( int* width,
                          int* height ) = 0;
};
}

#endif // ifndef LIBSHIMMER_API_RENDERER_API_H
