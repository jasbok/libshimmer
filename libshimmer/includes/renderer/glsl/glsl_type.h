#ifndef LIBSHIMMER_RENDER_GLSL_GLSL_TYPE
#define LIBSHIMMER_RENDER_GLSL_GLSL_TYPE

#include <string>

namespace shimmer
{
namespace glsl
{
enum class type
{
    UNKNOWN = 0,
    BOOL, INT, UINT, FLOAT, DOUBLE,
    BVEC2, BVEC3, BVEC4,
    IVEC2, IVEC3, IVEC4,
    UVEC2, UVEC3, UVEC4,
    VEC2, VEC3, VEC4,
    DVEC2, DVEC3, DVEC4,
    SAMPLER1D, ISAMPLER1D, USAMPLER1D,
    SAMPLER2D, ISAMPLER2D, USAMPLER2D,
    SAMPLER3D, ISAMPLER3D, USAMPLER3D,
    MAT2, MAT3, MAT4,
    MAT2X3, MAT3X2,
    MAT2X4, MAT4X2,
    MAT3X4, MAT4X3
};

type        type_from ( const std::string& str );

std::string str_from ( glsl::type type );
}
}

#endif // ifndef LIBSHIMMER_RENDER_GLSL_GLSL_TYPE
