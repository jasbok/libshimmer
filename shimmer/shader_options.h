#ifndef SHIMMER_SHADER_OPTIONS_H
#define SHIMMER_SHADER_OPTIONS_H

#include "external/json/json.hpp"

#include <string>

namespace shimmer
{
struct shader_options {
    std::string vertex = "/glsl1.3/default.vert";

    std::string fragment = "/glsl1.3/default.frag";

    bool linear_filter = false;

    float scale = 1.0f;
};

void to_json ( nlohmann::json&       json,
               const shader_options& obj );

void from_json ( const nlohmann::json& json,
                 shader_options&       obj );
}

#endif // ifndef SHIMMER_SHADER_OPTIONS_H
