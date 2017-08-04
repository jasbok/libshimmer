#include "gl_texture_2d.h"

using namespace shimmer;

gl_texture opengl::create_texture_2d_rgb ( unsigned int width,
                                           unsigned int height ) {
    glBindBuffer ( GL_PIXEL_UNPACK_BUFFER, 0 );

    return gl_texture ( GL_TEXTURE_2D,
                        0,
                        GL_RGB,
                        width,
                        height,
                        GL_RGB,
                        GL_UNSIGNED_BYTE,
                        nullptr );
}

gl_texture opengl::create_texture_2d_rgba ( unsigned int width,
                                            unsigned int height ) {
    glBindBuffer ( GL_PIXEL_UNPACK_BUFFER, 0 );

    return gl_texture ( GL_TEXTURE_2D,
                        0,
                        GL_RGBA,
                        width,
                        height,
                        GL_RGBA,
                        GL_UNSIGNED_BYTE,
                        nullptr );
}

gl_texture opengl::create_texture_2d ( unsigned int           width,
                                       unsigned int           height,
                                       const gl_pixel_buffer& buffer ) {
    buffer.bind();

    return gl_texture ( GL_TEXTURE_2D,
                        0,
                        buffer.format(),
                        width,
                        height,
                        buffer.format(),
                        buffer.type(),
                        nullptr );
}
