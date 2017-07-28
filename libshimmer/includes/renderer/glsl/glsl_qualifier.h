#ifndef LIBSHIMMER_RENDER_GLSL_GLSL_QUALIFIER
#define LIBSHIMMER_RENDER_GLSL_GLSL_QUALIFIER

#include <string>

namespace shimmer::glsl
{
enum class qualifier
{
    UNKNOWN = 0, ATTRIBUTE, UNIFORM, VARYING
};

std::string str_from ( qualifier qualifier );

qualifier   qualifier_from ( const std::string& str );
}

#endif // ifndef LIBSHIMMER_RENDER_GLSL_GLSL_QUALIFIER
