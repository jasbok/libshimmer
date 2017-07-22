#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_VARIABLE_EXTRACTOR_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_VARIABLE_EXTRACTOR_H

#include "glsl_variable.h"
#include <vector>

namespace shimmer
{
class gl_variable_extractor
{
public:
    virtual ~gl_variable_extractor() {}

    static std::vector<glsl_variable> extract ( const std::string& source );
};
}

# endif
