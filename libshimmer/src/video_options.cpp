#include "video_options.h"

namespace shimmer
{
void to_json ( nlohmann::json& json, const video_options& obj )
{
    json["application_shader"]   = obj.application_shader;
    json["background_shader"]    = obj.background_shader;
    json["aspect_ratio"]         = obj.aspect_ratio;
    json["refresh_rate_limiter"] = obj.refresh_rate_limiter;
}

void from_json ( const nlohmann::json& json, video_options& obj )
{
    obj.application_shader   = json.at ( "application_shader" );
    obj.background_shader    = json.at ( "background_shader" );
    obj.aspect_ratio         = json.at ( "aspect_ratio" );
    obj.refresh_rate_limiter = json.at ( "refresh_rate_limiter" );
}

std::string to_json ( const video_options& options )
{
    return nlohmann::json ( options ).dump();
}
}

namespace common {
std::string to_json ( const common::limiter& limiter )
{
    return nlohmann::json ( limiter ).dump();
}

void to_json ( nlohmann::json& json, const common::limiter& obj )
{
    json["limit"]   = obj.limit();
    json["samples"] = obj.samples();
}

void from_json ( const nlohmann::json& json, common::limiter& obj )
{
    obj.limit ( json.at ( "limit" ) );
    obj.samples ( json.at ( "samples" ) );
}
}
