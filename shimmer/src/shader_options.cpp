#include "shader_options.h"

namespace shimmer
{
void to_json ( nlohmann::json& json, const shader_options& obj )
{
    json["vertex"]        = obj.vertex;
    json["fragment"]      = obj.fragment;
    json["linear_filter"] = obj.linear_filter;
    json["scale"]         = obj.scale;
}

void from_json ( const nlohmann::json& json, shader_options& obj )
{
    obj.vertex        = json.at ( "vertex" );
    obj.fragment      = json.at ( "fragment" );
    obj.linear_filter = json.at ( "linear_filter" );
    obj.scale         = json.at ( "scale" );
}
}
