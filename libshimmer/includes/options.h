#ifndef SHIMMER_OPTIONS_H
#define SHIMMER_OPTIONS_H

#include "specs.h"

#include "json/json.hpp"

#include <string>
#include <vector>

namespace shimmer
{
template<typename T>
class serialisable
{
public:
    virtual void to_json ( nlohmann::json& json,
                           const T&        obj ) = 0;

    virtual void from_json ( const nlohmann::json& json,
                             T&                    obj ) = 0;
};

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

struct general_options {
    std::vector<std::string> resource_paths = { "./data", };
};

struct shader_options {
    std::string vertex = "glsl2.1/example.vert";

    std::string fragment = "glsl2.1/default.frag";

    bool linear_filter = false;

    float scale = 1.0f;
};

enum class aspect_ratio {
    original,
    stretch,
    zoom
};

struct video_options {
    shader_options application_shader;

    shader_options background_shader;

    enum aspect_ratio aspect_ratio = aspect_ratio::original;
};

struct options {
    struct general_options general;

    struct video_options video;
};

void to_json ( nlohmann::json&        json,
               const general_options& obj );

void from_json ( const nlohmann::json& json,
                 general_options&      obj );

void to_json ( nlohmann::json&       json,
               const shader_options& obj );

void from_json ( const nlohmann::json& json,
                 shader_options&       obj );

void to_json ( nlohmann::json&          json,
               const enum aspect_ratio& obj );

void from_json ( const nlohmann::json& json,
                 enum aspect_ratio&    obj );

void to_json ( nlohmann::json&      json,
               const video_options& obj );

void from_json ( const nlohmann::json& json,
                 video_options&        obj );

void to_json ( nlohmann::json& json,
               const options&  obj );

void from_json ( const nlohmann::json& json,
                 options&              obj );
}

namespace glpp
{
void to_json ( nlohmann::json& json,
               const dims_2f&  obj );

void from_json ( const nlohmann::json& json,
                 dims_2f&              obj );
}

#endif // ifndef SHIMMER_OPTIONS_H
