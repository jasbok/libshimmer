#include "gl_texture_loader.h"

#include "gl_pixel.h"

#include "spdlog/spdlog.h"

using namespace shimmer;
using namespace std;

static std::shared_ptr<spdlog::logger> LOGGER
    = spdlog::stdout_color_mt ( "gl_texture_loader" );

gl_texture_loader::gl_texture_loader( unsigned int buffer_count )
    : _pbo_array(),
      _pbo_count ( buffer_count ),
      _pbo_index ( 0 )
{
    glGenBuffers ( _pbo_count, _pbo_array );
}

gl_texture_loader::~gl_texture_loader()
{
    glDeleteBuffers ( _pbo_count, _pbo_array );
}

void gl_texture_loader::upload ( const std::shared_ptr<gl_texture>& texture,
                                 GLenum                             format,
                                 GLenum                             type,
                                 const GLvoid*                      data )
{
    auto size = texture->width()
                * texture->height()
                * opengl::bytes_per_pixel ( format, type );

    auto buffer = _map_buffer ( _next_pbo(),
                                GL_PIXEL_UNPACK_BUFFER,
                                size,
                                GL_WRITE_ONLY,
                                GL_STATIC_DRAW );

    std::memcpy ( buffer, data, size );
    glUnmapBuffer ( GL_PIXEL_UNPACK_BUFFER );

    texture->upload ( format, type, nullptr );
}

void gl_texture_loader::upload ( const std::shared_ptr<gl_texture>& texture,
                                 GLenum                             format,
                                 GLenum                             type,
                                 const GLvoid*                      data,
                                 GLint                              x_offset,
                                 GLint                              y_offset,
                                 GLsizei                            width,
                                 GLsizei                            height )
{
    auto size = width * height * opengl::bytes_per_pixel ( format, type );

    // TODO:    Check whether we need to allocate a PBO with the same size as
    //          the target texture in order to write data to a sub-region.
    auto buffer = _map_buffer ( _next_pbo(),
                                GL_PIXEL_UNPACK_BUFFER,
                                size,
                                GL_WRITE_ONLY,
                                GL_STATIC_DRAW );

    std::memcpy ( buffer, data, size );
    glUnmapBuffer ( GL_PIXEL_UNPACK_BUFFER );

    texture->upload ( format, type, nullptr, x_offset, y_offset, width,
                      height );
}

GLuint gl_texture_loader::_next_pbo()
{
    _pbo_index = ++_pbo_index < _pbo_count ? _pbo_index : 0;

    return _pbo_array[_pbo_index];
}

void* gl_texture_loader::_map_buffer ( GLuint     pbo,
                                       GLenum     target,
                                       GLsizeiptr size,
                                       GLenum     access,
                                       GLenum     usage )
{
    glBindBuffer ( target, pbo );
    glBufferData ( target, size, 0, usage );

    return glMapBuffer ( target, access );
}
