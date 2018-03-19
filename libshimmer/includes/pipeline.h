#ifndef SHIMMER_PIPELINE_H

#include "json/json.hpp"

#include <string>
#include <vector>

namespace shimmer
{
struct texture {
    std::string id;
    std::string path;
    std::string filter;
};

struct texture_binding {
    std::string variable;
    std::string texture_id;
};

struct uniform {
    std::string variable;
    std::string value;
};

struct shader {
    std::string vertex;
    std::string fragment;
};

struct pass
{
    std::string                  blend_function;
    std::vector<texture_binding> texture_bindings;
    std::vector<uniform>         uniforms;
    struct shader                shader;
};

struct stage
{
    std::string       input;
    std::string       output;
    float             scale;
    std::vector<pass> passes;
};

struct pipeline
{
    std::vector<stage> stages;

    void load ( const std::string& path );
};


void to_json ( nlohmann::json& json,
               const texture&  obj );

void from_json ( const nlohmann::json& json,
                 texture&              obj );


void to_json ( nlohmann::json&        json,
               const texture_binding& obj );

void from_json ( const nlohmann::json& json,
                 texture_binding&      obj );


void to_json ( nlohmann::json& json,
               const uniform&  obj );

void from_json ( const nlohmann::json& json,
                 uniform&              obj );


void to_json ( nlohmann::json& json,
               const shader&   obj );

void from_json ( const nlohmann::json& json,
                 shader&               obj );


void to_json ( nlohmann::json& json,
               const pass&     obj );

void from_json ( const nlohmann::json& json,
                 pass&                 obj );


void to_json ( nlohmann::json& json,
               const stage&    obj );

void from_json ( const nlohmann::json& json,
                 stage&                obj );


void to_json ( nlohmann::json& json,
               const pipeline& obj );

void from_json ( const nlohmann::json& json,
                 pipeline&             obj );
}

#endif // ifndef SHIMMER_PIPELINE_H
