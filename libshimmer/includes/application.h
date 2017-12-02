#ifndef SHIMMER_APPLICATION_H
#define SHIMMER_APPLICATION_H

#include "specs.h"

namespace shimmer{
struct application {
    struct surface {
        glpp::dims_2u dims;
    };

    struct window {
        std::string title;

        glpp::coords_2i coords;

        glpp::dims_2u dims;
    };

    struct surface surface;

    struct window window;
};
}

#endif
