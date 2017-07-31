#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_ENUM_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_ENUM_H

#include <GL/glew.h>

#include <string>

namespace shimmer
{
namespace opengl
{
std::string enum_to_string ( GLenum gl_enum );
}
}

#endif // ifndef LIBSHIMMER_RENDERER_OPENGL_GL_ENUM_H
