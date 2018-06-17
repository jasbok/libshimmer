#ifndef SHIMMER_GENERAL_OPTIONS_H
#define SHIMMER_GENERAL_OPTIONS_H

#include "environment.h"

#include "external/json/json.hpp"

namespace shimmer
{
struct general_options
{
    std::vector<std::string> font_paths;

    std::vector<std::string> image_paths;

    std::vector<std::string> shader_paths;

    void set_env ( const environment& env );
};

void to_json ( nlohmann::json&        json,
               const general_options& obj );

void from_json ( const nlohmann::json& json,
                 general_options&      obj );

std::string to_json ( const general_options& options );
}

#endif // ifndef SHIMMER_GENERAL_OPTIONS_H
