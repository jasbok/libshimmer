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

string to_json ( const options& obj )
{
    return nlohmann::json ( obj ).dump();
}
