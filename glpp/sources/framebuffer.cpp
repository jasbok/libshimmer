#include "framebuffer.h"

using namespace glpp;


framebuffer::framebuffer()
    : _handle()
{
    glGenFramebuffers ( 1, &_handle );
}

framebuffer::framebuffer( framebuffer&& move )
    : _handle ( move._handle )
{
    move._handle = 0;
}

framebuffer::~framebuffer()
{
    glDeleteFramebuffers ( 1, &_handle );
}

framebuffer& framebuffer::operator=( framebuffer&& move )
{
    _handle      = move._handle;
    move._handle = 0;

    return *this;
}

framebuffer& framebuffer::bind()
{
    glBindFramebuffer ( GL_FRAMEBUFFER, _handle );

    return *this;
}

framebuffer& framebuffer::unbind()
{
    glBindFramebuffer ( GL_FRAMEBUFFER, 0 );

    return *this;
}

GLenum framebuffer::check_status() const
{
    return glCheckFramebufferStatus ( GL_FRAMEBUFFER );
}

framebuffer& framebuffer::attach ( const texture_2d& texture,
                                   GLint             mipmap_level )
{
    glFramebufferTexture2D ( GL_FRAMEBUFFER,
                             GL_COLOR_ATTACHMENT0,
                             GL_TEXTURE_2D,
                             texture.handle(),
                             mipmap_level );

    return *this;
}
