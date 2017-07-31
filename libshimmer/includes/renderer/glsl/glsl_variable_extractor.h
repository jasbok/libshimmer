#ifndef LIBSHIMMER_RENDERER_GLSL_GL_VARIABLE_EXTRACTOR_H
#define LIBSHIMMER_RENDERER_GLSL_GL_VARIABLE_EXTRACTOR_H

#include "glsl_variable.h"

#include <string>
#include <vector>

namespace shimmer
{
namespace glsl_variable_extractor
{
std::vector<glsl_variable> extract ( const std::string& source );
}
}

#endif // ifndef LIBSHIMMER_RENDERER_GLSL_GL_VARIABLE_EXTRACTOR_H
