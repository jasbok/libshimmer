#include "glsl_variable.h"
#include "spdlog.h"

using namespace std;
using namespace shimmer;

static std::shared_ptr<spdlog::logger> LOGGER
    = spdlog::stdout_color_mt ( "glsl_variable" );

const unordered_map<string, enum glsl_type>
glsl_variable::_type_from_str_map = {
    {"bool", glsl_type::BOOL},
    {"int", glsl_type::INT},
    {"uint", glsl_type::UINT},
    {"float", glsl_type::FLOAT},
    {"double", glsl_type::DOUBLE},

    {"bvec2", glsl_type::BVEC2},
    {"bvec3", glsl_type::BVEC3},
    {"bvec4", glsl_type::BVEC4},

    {"ivec2", glsl_type::IVEC2},
    {"ivec3", glsl_type::IVEC3},
    {"ivec4", glsl_type::IVEC4},

    {"uvec2", glsl_type::UVEC2},
    {"uvec3", glsl_type::UVEC3},
    {"uvec4", glsl_type::UVEC4},

    {"vec2", glsl_type::VEC2},
    {"vec3", glsl_type::VEC3},
    {"vec4", glsl_type::VEC4},

    {"dvec2", glsl_type::DVEC2},
    {"dvec3", glsl_type::DVEC3},
    {"dvec4", glsl_type::DVEC4},

    {"sampler1D", glsl_type::SAMPLER1D},
    {"sampler2D", glsl_type::SAMPLER2D},
    {"sampler3D", glsl_type::SAMPLER3D},

    {"isampler1D", glsl_type::ISAMPLER1D},
    {"isampler2D", glsl_type::ISAMPLER2D},
    {"isampler3D", glsl_type::ISAMPLER3D},

    {"usampler1D", glsl_type::USAMPLER1D},
    {"usampler2D", glsl_type::USAMPLER2D},
    {"usampler3D", glsl_type::USAMPLER3D},

    {"mat2", glsl_type::MAT2},
    {"mat3", glsl_type::MAT3},
    {"mat4", glsl_type::MAT4},

    {"mat2x3", glsl_type::MAT2X3},
    {"mat3x2", glsl_type::MAT3X2},

    {"mat2x4", glsl_type::MAT2X4},
    {"mat4x2", glsl_type::MAT4X2},

    {"mat3x4", glsl_type::MAT3X4},
    {"mat4x3", glsl_type::MAT4X3}
};

glsl_variable::glsl_variable()
    : _size ( 1 ),
      _name(),
      _location ( -1 )
{}

glsl_variable::glsl_variable (
    glsl_qualifier qualifier,
    glsl_type type,
    const string& name )
    : _qualifier ( qualifier ),
      _type ( type ),
      _size ( 1 ),
      _name ( name ),
      _location ( -1 )
{}

glsl_variable::glsl_variable (
    glsl_qualifier qualifier,
    glsl_type type,
    unsigned int size,
    const string& name )
    : _qualifier ( qualifier ),
      _type ( type ),
      _size ( size ),
      _name ( name ),
      _location ( -1 )
{}

glsl_qualifier glsl_variable::qualifier_from ( const string& str )
{
    if ( str.compare ( "uniform" ) == 0 ) {
        return glsl_qualifier::UNIFORM;
    } else if ( str.compare ( "attribute" ) == 0 ) {
        return glsl_qualifier::ATTRIBUTE;
    } else if ( str.compare ( "varying" ) == 0 ) {
        return glsl_qualifier::VARYING;
    }

    LOGGER->warn("Unknown glsl_qualifier: {}", str);
    return glsl_qualifier::UNKNOWN;
}

glsl_type glsl_variable::type_from ( const string& str )
{
    if ( _type_from_str_map.find ( str ) != _type_from_str_map.end() ) {
        return _type_from_str_map.at ( str );
    }

    LOGGER->warn("Unknown glsl_type: {}", str);
    return glsl_type::UNKNOWN;
}

string glsl_variable::str_from ( glsl_qualifier qualifier )
{
    switch ( qualifier ) {
    case glsl_qualifier::ATTRIBUTE:
        return "attribute";
    case glsl_qualifier::UNIFORM:
        return "uniform";
    case glsl_qualifier::VARYING:
        return "varying";
    default:
        return "unknown";
    }
}

string glsl_variable::str_from ( glsl_type type )
{
    for (
        auto it = _type_from_str_map.begin();
        it != _type_from_str_map.end();
        it++ ) {
        if ( it->second == type ) {
            return it->first;
        }
    }

    return "unknown";
}
