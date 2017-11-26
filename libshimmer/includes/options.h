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
        std::vector<std::string> resource_paths =
        { "./data", };
    };

    struct video {
        struct shader {
            std::string vertex;

            std::string fragment;
        };

        shader application_shader = { "glsl2.1/example.vert",
                                      "glsl2.1/default.frag" };

        bool application_linear_filter = false;

        float application_aspect_ratio = 4.0f / 3.0f;

        std::optional<shader> background_shader;

        bool background_linear_filter = false;


        std::optional<shader> scaling_shader;

        bool scaling_linear_filter = false;


        std::optional<glpp::dims_2u> application_resolution;

        std::optional<glpp::dims_2u> surface_resolution;
    };

    struct general general;

    struct video video;
};
}

#endif // ifndef SHIMMER_OPTIONS_H
