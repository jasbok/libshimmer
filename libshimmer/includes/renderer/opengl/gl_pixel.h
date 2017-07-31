#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_PIXEL_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_PIXEL_H

#include <GL/glew.h>

namespace shimmer
{
namespace opengl
{
unsigned int bytes_per_pixel ( GLenum format,
                               GLenum type );
}
}

#endif // ifndef LIBSHIMMER_RENDERER_OPENGL_GL_PIXEL_H
