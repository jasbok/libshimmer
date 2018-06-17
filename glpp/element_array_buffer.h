#ifndef GLPP_ELEMENT_ARRAY_BUFFER_H
#define GLPP_ELEMENT_ARRAY_BUFFER_H

#include "buffer.h"

namespace glpp
{
class element_array_buffer : public _buffer<GL_ELEMENT_ARRAY_BUFFER,
                                            element_array_buffer>
{
    typedef _buffer<GL_ELEMENT_ARRAY_BUFFER, element_array_buffer> parent;

public:
    explicit element_array_buffer( enum usage usage = usage::static_draw );

    element_array_buffer( element_array_buffer&& move ) = default;

    element_array_buffer( const element_array_buffer& copy ) = delete;

    virtual ~element_array_buffer() = default;

    element_array_buffer& operator=( element_array_buffer&& move ) = default;

    element_array_buffer& operator=( const element_array_buffer& copy ) =
        delete;

    element_array_buffer& data ( const std::vector<GLuint>& vec );

    element_array_buffer& data ( const std::vector<GLuint>& vec,
                                 enum usage                 usage );
};

typedef element_array_buffer ebo;
}

#endif // ifndef GLPP_ELEMENT_ARRAY_BUFFER_H
