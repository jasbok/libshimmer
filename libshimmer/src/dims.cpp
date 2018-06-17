#include "dims.h"

namespace shimmer
{
void to_json ( nlohmann::json& json, const dims_2f& obj )
{
    json["width"]  = obj.width;
    json["height"] = obj.height;
}

void from_json ( const nlohmann::json& json, dims_2f& obj )
{
    obj.width  = json.at ( "width" );
    obj.height = json.at ( "height" );
}
}
