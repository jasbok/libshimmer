#ifndef SHIMMER_OPTIONS_H
#define SHIMMER_OPTIONS_H

#include "specs.h"

#include <optional>
#include <string>
#include <vector>

namespace shimmer
{
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

struct options {
    struct general {
        std::optional<std::vector<std::string>> resource_paths;
    };

    struct video {
        struct shader {
            std::string vertex;

            std::string fragment;
        };

        std::optional<shader> application_shader;

        std::optional<shader> background_shader;

        std::optional<shader> scaling_shader;

        std::optional<glpp::dims_2u> application_resolution;

        std::optional<glpp::dims_2u> surface_resolution;
    };

    struct general general;

    struct video video;
};
}

#endif // ifndef SHIMMER_OPTIONS_H
