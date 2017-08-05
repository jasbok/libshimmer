#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_SHAPES_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_SHAPES_H

#include "gl_mesh.h"

namespace shimmer
{
namespace opengl
{
gl_mesh create_textured_quad ( float aspect_ratio, bool flip_y = false);
}
}

#endif // ifndef LIBSHIMMER_RENDERER_OPENGL_GL_SHAPES_H
