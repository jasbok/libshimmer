#include "options.h"

using namespace shimmer;
using namespace std;

void options::set_env ( const environment& env )
{
    general.set_env ( env );
}

void general_options::set_env ( const environment& env )
{
    if ( !env.font_paths().empty() ) {
        if ( font_paths.empty() ) {
            font_paths = env.font_paths();
        }
        else {
            font_paths.insert ( font_paths.begin(),
                                env.font_paths().begin(),
                                env.font_paths().end() );
        }
    }

    if ( !env.image_paths().empty() ) {
        if ( image_paths.empty() ) {
            image_paths = env.image_paths();
        }
        else {
            image_paths.insert ( image_paths.begin(),
                                 env.image_paths().begin(),
                                 env.image_paths().end() );
        }
    }

    if ( !env.shader_paths().empty() ) {
        if ( shader_paths.empty() ) {
            shader_paths = env.shader_paths();
        }
        else {
            shader_paths.insert ( shader_paths.begin(),
                                  env.shader_paths().begin(),
                                  env.shader_paths().end() );
        }
    }
}

void shimmer::to_json ( nlohmann::json&        json,
                        const general_options& obj )
{
    json["font_paths"]   = obj.font_paths;
    json["image_paths"]  = obj.image_paths;
    json["shader_paths"] = obj.shader_paths;
}

void shimmer::from_json ( const nlohmann::json& json,
                          general_options&      obj )
{
    obj.font_paths   = json["font_paths"].get<vector<string>>();
    obj.image_paths  = json["image_paths"].get<vector<string>>();
    obj.shader_paths = json["shader_paths"].get<vector<string>>();
}

void shimmer::to_json ( nlohmann::json& json, const shader_options& obj )
{
    json["vertex"]        = obj.vertex;
    json["fragment"]      = obj.fragment;
    json["linear_filter"] = obj.linear_filter;
    json["scale"]         = obj.scale;
}

void shimmer::from_json ( const nlohmann::json& json, shader_options& obj )
{
    obj.vertex        = json.at ( "vertex" );
    obj.fragment      = json.at ( "fragment" );
    obj.linear_filter = json.at ( "linear_filter" );
    obj.scale         = json.at ( "scale" );
}

void shimmer::to_json ( nlohmann::json& json, const video_options& obj )
{
    json["application_shader"]   = obj.application_shader;
    json["background_shader"]    = obj.background_shader;
    json["aspect_ratio"]         = obj.aspect_ratio;
    json["refresh_rate_limiter"] = obj.refresh_rate_limiter;
}

void shimmer::from_json ( const nlohmann::json& json, video_options& obj )
{
    obj.application_shader   = json.at ( "application_shader" );
    obj.background_shader    = json.at ( "background_shader" );
    obj.aspect_ratio         = json.at ( "aspect_ratio" );
    obj.refresh_rate_limiter = json.at ( "refresh_rate_limiter" );
}

void shimmer::to_json ( nlohmann::json& json, const options& obj )
{
    json["general"] = obj.general;
    json["video"]   = obj.video;
}

void shimmer::from_json ( const nlohmann::json& json, options& obj )
{
    obj.general = json.at ( "general" );
    obj.video   = json.at ( "video" );
}

void shimmer::to_json ( nlohmann::json& json, const aspect_ratio& obj )
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

void shimmer::from_json ( const nlohmann::json& json, aspect_ratio& obj )
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
