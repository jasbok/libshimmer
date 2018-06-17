#include "pipeline.h"

#include "logger.h"

#include <fstream>
#include <iostream>

using namespace std;

void shimmer::to_json ( nlohmann::json& json, const shimmer::texture& obj )
{
    json["id"]     = obj.id;
    json["path"]   = obj.path;
    json["filter"] = obj.filter;
}

void shimmer::from_json ( const nlohmann::json& json, shimmer::texture& obj )
{
    obj.id     = json.at ( "id" );
    obj.path   = json.at ( "path" );
    obj.filter = json.at ( "filter" );
}

void shimmer::to_json ( nlohmann::json&                 json,
                        const shimmer::texture_binding& obj )
{
    json["variable"]   = obj.variable;
    json["terture_id"] = obj.texture_id;
}

void shimmer::from_json ( const nlohmann::json&     json,
                          shimmer::texture_binding& obj )
{
    obj.variable   = json.at ( "variable" );
    obj.texture_id = json.at ( "texture_id" );
}

void shimmer::to_json ( nlohmann::json&         json,
                        const shimmer::uniform& obj )
{
    json["variable"] = obj.variable;
    json["value"]    = obj.value;
}

void shimmer::from_json ( const nlohmann::json& json,
                          shimmer::uniform&     obj )
{
    obj.variable = json.at ( "variable" );
    obj.value    = json.at ( "value" );
}

void shimmer::to_json ( nlohmann::json& json, const shimmer::shader& obj )
{
    json["vertex"]   = obj.vertex;
    json["fragment"] = obj.fragment;
}

void shimmer::from_json ( const nlohmann::json& json, shimmer::shader& obj )
{
    obj.vertex   = json.at ( "vertex" );
    obj.fragment = json.at ( "fragment" );
}

void shimmer::to_json ( nlohmann::json& json, const shimmer::pass& obj )
{
    json["blend_function"]   = obj.blend_function;
    json["texture_bindings"] = obj.texture_bindings;
    json["shader"]           = obj.shader;
}

void shimmer::from_json ( const nlohmann::json& json, shimmer::pass& obj )
{
    obj.blend_function = json.at ( "blend_function" );

    obj.texture_bindings =
        json.at ( "texture_bindings" ).get<std::vector<texture_binding>>();

    obj.uniforms = json.at ( "uniforms" ).get<std::vector<uniform>>();

    obj.shader = json.at ( "shader" );
}

void shimmer::to_json ( nlohmann::json& json, const shimmer::stage& obj ) {
    json["input"]  = obj.input;
    json["output"] = obj.output;
    json["scale"]  = obj.scale;
    json["passes"] = obj.passes;
}

void shimmer::from_json ( const nlohmann::json& json, shimmer::stage& obj ) {
    obj.input  = json.at ( "input" );
    obj.output = json.at ( "output" );
    obj.scale  = json.at ( "scale" );
    obj.passes = json.at ( "passes" ).get<std::vector<pass>>();
}

void shimmer::to_json ( nlohmann::json& json, const shimmer::pipeline& obj ) {
    json["stages"] = obj.stages;
}

void shimmer::from_json ( const nlohmann::json& json, shimmer::pipeline& obj ) {
    obj.stages = json.at ( "stages" ).get<std::vector<stage>>();
}

void shimmer::pipeline::load ( const std::string& path )
{
    using json = nlohmann::json;
    json pipeline_json;

    try {
        ifstream fstream ( path );

        if ( fstream.is_open() ) {
            fstream >> pipeline_json;
            *this = pipeline_json;
        }
        else {
            cout << "Unable to find pipeline file: " << path;
        }
    }
    catch ( json::exception ex ) {
        std::cerr << "Unable to parse pipeline file (" << path << "): "
                  << ex.what() << "\n"
                  << std::setw ( 2 ) << pipeline_json << std::endl;
    }
    catch ( exception ex ) {
        std::cerr << "Unable to parse pipeline file (" << path << "): "
                  << ex.what() << std::endl;
    }
}
