#include "options.h"

using json = nlohmann::json;
using namespace std;

namespace shimmer
{
void to_json ( nlohmann::json&        json,
               const general_options& obj )
{
    json["resource_paths"] = obj.resource_paths;
}

void from_json ( const nlohmann::json& json,
                 general_options&      obj )
{
    obj.resource_paths = json["resource_paths"].get<vector<string>>();
}

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

void to_json ( nlohmann::json& json, const video_options& obj )
{
    json["application_shader"] = obj.application_shader;
    json["background_shader"]  = obj.background_shader;
    json["aspect_ratio"]       = obj.aspect_ratio;
}

void from_json ( const nlohmann::json& json, video_options& obj )
{
    obj.application_shader = json.at ( "application_shader" );
    obj.background_shader  = json.at ( "background_shader" );
    obj.aspect_ratio       = json.at ( "aspect_ratio" );
}

void to_json ( nlohmann::json& json, const options& obj )
{
    json["general"] = obj.general;
    json["video"]   = obj.video;
}

void from_json ( const nlohmann::json& json, options& obj )
{
    obj.general = json.at ( "general" );
    obj.video   = json.at ( "video" );
}

void to_json ( nlohmann::json& json, const aspect_ratio& obj )
{
    switch ( obj ) {
    case aspect_ratio::original:
        json = "original";
        break;

    case aspect_ratio::stretch:
        json = "stretch";
        break;

    case aspect_ratio::zoom:
        json = "zoom";
        break;

    default:
        json = "original";
        break;
    }
}

void from_json ( const nlohmann::json& json, aspect_ratio& obj )
{
    string ar = json;

    if ( ar.compare ( "stretch" ) == 0 ) {
        obj = aspect_ratio::stretch;
    }
    else if ( ar.compare ( "zoom" ) == 0 ) {
        obj = aspect_ratio::zoom;
    }
    else {
        obj = aspect_ratio::original;
    }
}
}

namespace glpp
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
