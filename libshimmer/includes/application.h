#ifndef SHIMMER_APPLICATION_H
#define SHIMMER_APPLICATION_H

#include "common.h"

namespace shimmer
{
struct application {
    struct surface {
        dims_2u dims;
    };

    struct window {
        std::string title;

        coords_2i coords;

        dims_2u dims;
    };

    struct surface surface;

    struct window window;
};
}

#endif // ifndef SHIMMER_APPLICATION_H
