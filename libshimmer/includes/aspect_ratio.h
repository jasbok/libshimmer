#ifndef SHIMMER_ASPECT_RATIO_H
#define SHIMMER_ASPECT_RATIO_H

#include "json/json.hpp"

#include <string>

namespace shimmer
{
enum class aspect_ratio {
    original,
    stretch,
    zoom
};

void to_json ( nlohmann::json&          json,
               const enum aspect_ratio& obj );

void from_json ( const nlohmann::json& json,
                 enum aspect_ratio&    obj );

std::string to_json ( const aspect_ratio ratio );
}
#endif // ifndef SHIMMER_ASPECT_RATIO_H
