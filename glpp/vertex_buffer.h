#ifndef GLPP_VERTEX_BUFFER_H
#define GLPP_VERTEX_BUFFER_H

#include "mbuffer.h"

#include "external/gsl/gsl"

namespace glpp
{
typedef mbuffer<GL_ARRAY_BUFFER> vertex_buffer;
typedef vertex_buffer            vbo;
}

#endif // ifndef GLPP_VERTEX_BUFFER_H
