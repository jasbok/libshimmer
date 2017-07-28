#include "gl_texture_loader.h"

#include "gl_pixel.h"

#include "spdlog/spdlog.h"

using namespace std;
using namespace shimmer;

static std::shared_ptr<spdlog::logger> LOGGER
    = spdlog::stdout_color_mt ( "gl_texture_loader" );

gl_texture_loader::gl_texture_loader ( unsigned int write_buffer_count,
                                       unsigned int read_buffer_count )
    : _wo_pbo_array (),
      _wo_pbo_count ( write_buffer_count ),
      _wo_pbo_index ( 0 ),
      _ro_pbo_array (),
      _ro_pbo_count ( read_buffer_count ),
      _ro_pbo_index ( 0 )
{
    glGenBuffers ( _wo_pbo_count, _wo_pbo_array );
    glGenBuffers ( _ro_pbo_count, _ro_pbo_array );
}

gl_texture_loader::~gl_texture_loader()
{
    glDeleteBuffers ( _wo_pbo_count, _wo_pbo_array );
    glDeleteBuffers ( _ro_pbo_count, _ro_pbo_array );
}

void gl_texture_loader::upload ( const std::shared_ptr<gl_texture>& texture,
                                 GLenum format,
                                 GLenum type,
                                 const GLvoid* data )
{
    texture->upload ( format, type, data );
}

void gl_texture_loader::upload ( const std::shared_ptr<gl_texture>& texture,
                                 GLenum format,
                                 GLenum type,
                                 const GLvoid* data,
                                 GLint x_offset,
                                 GLint y_offset,
                                 GLsizei width,
                                 GLsizei height )
{
    GLsizeiptr size = width * height * opengl::bytes_per_pixel ( format, type );

    void* buffer = _map_buffer ( _next_wo_pbo(),
                                 GL_PIXEL_UNPACK_BUFFER,
                                 size,
                                 GL_WRITE_ONLY,
                                 GL_STATIC_DRAW );

    glMapBuffer ( GL_PIXEL_UNPACK_BUFFER,  GL_WRITE_ONLY );

    texture->upload ( format, type, data, x_offset, y_offset,  width,  height );
}

void gl_texture_loader::download ( const std::shared_ptr<gl_texture>& texture,
                                   GLenum format,
                                   GLenum type,
                                   GLvoid* data )
{
    GLsizeiptr size = texture->width()
                      * texture->height()
                      * opengl::bytes_per_pixel ( format, type );

    void* buffer = _map_buffer ( _next_ro_pbo(),
                                 GL_PIXEL_UNPACK_BUFFER,
                                 size,
                                 GL_READ_ONLY,
                                 GL_STATIC_READ );

    glMapBuffer ( GL_PIXEL_UNPACK_BUFFER,  GL_READ_ONLY );

    texture->download ( format, type, data );
}

GLuint gl_texture_loader::_next_wo_pbo()
{
    _wo_pbo_index = ++_wo_pbo_index < _wo_pbo_count ? _wo_pbo_index : 0;
    return _wo_pbo_array[_wo_pbo_index];
}

GLuint gl_texture_loader::_next_ro_pbo()
{
    _ro_pbo_index = ++_ro_pbo_index < _ro_pbo_count ? _ro_pbo_index : 0;
    return _ro_pbo_array[_ro_pbo_index];
}

void* gl_texture_loader::_map_buffer ( GLuint pbo,
                                       GLenum target,
                                       GLsizeiptr size,
                                       GLenum access,
                                       GLenum usage )
{
    glBindBuffer ( target, pbo );
    glBufferData ( target, size, 0, usage );
    return glMapBuffer ( target, access );
}

