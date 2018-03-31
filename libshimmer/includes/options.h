#ifndef SHIMMER_OPTIONS_H
#define SHIMMER_OPTIONS_H

#include "aspect_ratio.h"
#include "environment.h"
#include "general_options.h"
#include "video_options.h"

namespace shimmer
{
struct options
{
    struct general_options general;

    struct video_options video;

    void set_env ( const environment& env );
};

void to_json ( nlohmann::json& json,
               const options&  obj );

void from_json ( const nlohmann::json& json,
                 options&              obj );

std::string to_json ( const options& obj );
}

#endif // ifndef SHIMMER_OPTIONS_H
