#ifndef GLPP_MBUFFER_H
#define GLPP_MBUFFER_H

#include "buffer.h"

namespace glpp
{
class mbuffer : public buffer
{
public:
    enum class target : GLenum {
        gl_array_buffer         = GL_ARRAY_BUFFER,
        gl_element_array_buffer = GL_ELEMENT_ARRAY_BUFFER,
        gl_pixel_pack_buffer    = GL_PIXEL_PACK_BUFFER,
        gl_pixel_unpack_buffer  = GL_PIXEL_UNPACK_BUFFER
    };

    enum class access : GLenum {
        gl_read_only_buffer  = GL_READ_ONLY,
        gl_write_only_buffer = GL_WRITE_ONLY,
        gl_read_write_buffer = GL_READ_WRITE
    };


    mbuffer( enum target target );

    mbuffer( mbuffer&& move );

    mbuffer( const mbuffer& copy ) = delete;

    virtual ~mbuffer();

    mbuffer& operator=( mbuffer&& move );

    mbuffer& operator=( const mbuffer& copy ) = delete;


    buffer_data map ( enum access access );

    bool        unmap();
};
}

#endif // ifndef GLPP_MBUFFER_H
