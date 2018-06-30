#ifndef SHIMMER_VIDEO_OPTIONS_H
#define SHIMMER_VIDEO_OPTIONS_H

#include "aspect_ratio.h"
#include "shader_options.h"

#include "common/limiter.h"

namespace shimmer
{
struct video_options {
    shader_options application_shader;

    shader_options background_shader;

    enum aspect_ratio aspect_ratio = aspect_ratio::original;

    common::limiter refresh_rate_limiter;
};

std::string to_json ( const video_options& options );

void        to_json ( nlohmann::json&      json,
                      const video_options& obj );

void from_json ( const nlohmann::json& json,
                 video_options&        obj );
}

namespace common {
std::string to_json ( const common::limiter& limiter );

void        to_json ( nlohmann::json& json,
                      const common::limiter&  obj );

void from_json ( const nlohmann::json& json,
                 common::limiter&              obj );
}

#endif
