#ifndef SHIMMER_SHIMMER_H
#define SHIMMER_SHIMMER_H

#include "macros.h"
#include "options.h"
#include "renderer.h"
#include "specs.h"

namespace shimmer
{
class shimmer
{
public:
    shimmer();

    virtual ~shimmer();

    void create_window ( std::string&     title,
                         glpp::coords_2i& coords,
                         glpp::dims_2u&   dims );

    void resize_window ( glpp::dims_2u& dims );

    bool scaling_enabled() const;

private:
    struct application _app;
    struct options _options;
};
}

#endif // ifndef SHIMMER_SHIMMER_H
