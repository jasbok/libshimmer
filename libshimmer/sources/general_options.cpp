#include "general_options.h"

namespace shimmer
{
void to_json ( nlohmann::json&        json,
               const general_options& obj )
{
    json["font_paths"]   = obj.font_paths;
    json["image_paths"]  = obj.image_paths;
    json["shader_paths"] = obj.shader_paths;
}

void from_json ( const nlohmann::json& json,
                 general_options&      obj )
{
    using namespace std;

    obj.font_paths   = json["font_paths"].get<vector<string>>();
    obj.image_paths  = json["image_paths"].get<vector<string>>();
    obj.shader_paths = json["shader_paths"].get<vector<string>>();
}

std::string to_json ( const general_options& options )
{
    return nlohmann::json ( options ).dump();
}
}
