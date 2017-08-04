#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_TEXTURE_2D_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_TEXTURE_2D_H

#include "gl_pixel_buffer.h"
#include "gl_texture.h"

#include <memory>

namespace shimmer
{
namespace opengl
{
gl_texture create_texture_2d_rgb ( unsigned int width,
                                   unsigned int height );

gl_texture create_texture_2d_rgba ( unsigned int width,
                                    unsigned int height );

gl_texture create_texture_2d ( unsigned int           width,
                               unsigned int           height,
                               const gl_pixel_buffer& buffer );
}
}

#endif // ifndef LIBSHIMMER_RENDERER_OPENGL_GL_TEXTURE_2D_H
