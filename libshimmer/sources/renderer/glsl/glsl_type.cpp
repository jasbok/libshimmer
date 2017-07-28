#include "glsl_type.h"

#include "spdlog/spdlog.h"

#include <unordered_map>

using namespace shimmer;
using namespace std;

static std::shared_ptr<spdlog::logger> LOGGER
    = spdlog::stdout_color_mt ( "glsl_type" );

const unordered_map<string, enum glsl::type>
type_str_map = {
    {"bool", glsl::type::BOOL},
    {"int", glsl::type::INT},
    {"uint", glsl::type::UINT},
    {"float", glsl::type::FLOAT},
    {"double", glsl::type::DOUBLE},

    {"bvec2", glsl::type::BVEC2},
    {"bvec3", glsl::type::BVEC3},
    {"bvec4", glsl::type::BVEC4},

    {"ivec2", glsl::type::IVEC2},
    {"ivec3", glsl::type::IVEC3},
    {"ivec4", glsl::type::IVEC4},

    {"uvec2", glsl::type::UVEC2},
    {"uvec3", glsl::type::UVEC3},
    {"uvec4", glsl::type::UVEC4},

    {"vec2", glsl::type::VEC2},
    {"vec3", glsl::type::VEC3},
    {"vec4", glsl::type::VEC4},

    {"dvec2", glsl::type::DVEC2},
    {"dvec3", glsl::type::DVEC3},
    {"dvec4", glsl::type::DVEC4},

    {"sampler1D", glsl::type::SAMPLER1D},
    {"sampler2D", glsl::type::SAMPLER2D},
    {"sampler3D", glsl::type::SAMPLER3D},

    {"isampler1D", glsl::type::ISAMPLER1D},
    {"isampler2D", glsl::type::ISAMPLER2D},
    {"isampler3D", glsl::type::ISAMPLER3D},

    {"usampler1D", glsl::type::USAMPLER1D},
    {"usampler2D", glsl::type::USAMPLER2D},
    {"usampler3D", glsl::type::USAMPLER3D},

    {"mat2", glsl::type::MAT2},
    {"mat3", glsl::type::MAT3},
    {"mat4", glsl::type::MAT4},

    {"mat2x3", glsl::type::MAT2X3},
    {"mat3x2", glsl::type::MAT3X2},

    {"mat2x4", glsl::type::MAT2X4},
    {"mat4x2", glsl::type::MAT4X2},

    {"mat3x4", glsl::type::MAT3X4},
    {"mat4x3", glsl::type::MAT4X3}
};

glsl::type glsl::type_from ( const string& str )
{
    if ( type_str_map.find ( str ) != type_str_map.end() ) {
        return type_str_map.at ( str );
    }

    LOGGER->warn("Unknown glsl::type: {}", str);
    return type::UNKNOWN;
}

string glsl::str_from ( glsl::type type )
{
    for (
        auto it = type_str_map.begin();
        it != type_str_map.end();
        it++ ) {
        if ( it->second == type ) {
            return it->first;
        }
    }

    return "unknown";
}
