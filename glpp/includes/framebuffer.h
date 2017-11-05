#ifndef GLPP_FRAMEBUFFER_H
#define GLPP_FRAMEBUFFER_H

#include <texture_2d.h>

namespace glpp
{
class framebuffer
{
public:
    framebuffer();

    framebuffer( framebuffer&& move );

    framebuffer( const framebuffer& copy ) = delete;

    virtual ~framebuffer();

    framebuffer& operator=( framebuffer&& move );

    framebuffer& operator=( const framebuffer& copy ) = delete;

    framebuffer& bind();

    framebuffer& unbind();

    framebuffer& attach ( const texture_2d& texture,
                          GLint             mipmap_level = 0 );

    GLenum check_status() const;

private:
    GLuint _handle;
};
}

#endif // ifndef GLPP_FRAMEBUFFER_H
