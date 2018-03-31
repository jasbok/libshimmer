#ifndef SHIMMER_VIDEO_OPTIONS_H
#define SHIMMER_VIDEO_OPTIONS_H

#include "aspect_ratio.h"
#include "limiter.h"
#include "shader_options.h"

namespace shimmer
{
struct video_options {
    shader_options application_shader;

    shader_options background_shader;

    enum aspect_ratio aspect_ratio = aspect_ratio::original;

    class limiter refresh_rate_limiter;
};

std::string to_json ( const video_options& options );

void        to_json ( nlohmann::json&      json,
                      const video_options& obj );

void from_json ( const nlohmann::json& json,
                 video_options&        obj );
}

#endif // VIDEO_OPTIONS_H
