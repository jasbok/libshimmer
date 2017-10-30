#ifndef GLPP_ELEMENT_ARRAY_BUFFER_H
#define GLPP_ELEMENT_ARRAY_BUFFER_H

#include "buffer.h"

namespace glpp
{
class element_array_buffer : public _buffer<GL_ELEMENT_ARRAY_BUFFER,
                                            element_array_buffer>
{
public:
    element_array_buffer& data ( const std::vector<GLuint>& vec );

    element_array_buffer& data ( const std::vector<GLuint>& vec,
                                 enum usage                 usage );
};
}

#endif // ifndef GLPP_ELEMENT_ARRAY_BUFFER_H
