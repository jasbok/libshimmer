#ifndef GLPP_DEBUG_H
#define GLPP_DEBUG_H

#include <GL/glew.h>

#include <iostream>
#include <string>

#define GLPP_CHECK_ERROR( LABEL ) glpp::gl_get_errors ( __FILE__, \
                                                        __LINE__, \
                                                        LABEL )

namespace glpp
{
std::string gl_error_to_string ( GLenum err ) {
    switch ( err ) {
    case GL_NO_ERROR:

        return
            "(GL_NO_ERROR) No error has been recorded. The value of this symbolic constant is guaranteed to be 0.";

    case GL_INVALID_ENUM:

        return
            "(GL_INVALID_ENUM) An unacceptable value is specified for an enumerated argument. The offending command is ignored and has no other side effect than to set the error flag.";

    case GL_INVALID_VALUE:

        return
            "(GL_INVALID_VALUE) A numeric argument is out of range. The offending command is ignored and has no other side effect than to set the error flag.";

    case GL_INVALID_OPERATION:

        return
            "(GL_INVALID_OPERATION) The specified operation is not allowed in the current state. The offending command is ignored and has no other side effect than to set the error flag.";

    case GL_INVALID_FRAMEBUFFER_OPERATION:

        return
            "(GL_INVALID_FRAMEBUFFER_OPERATION) The framebuffer object is not complete. The offending command is ignored and has no other side effect than to set the error flag.";

    case GL_OUT_OF_MEMORY:

        return
            "(GL_OUT_OF_MEMORY) There is not enough memory left to execute the command. The state of the GL is undefined, except for the state of the error flags, after this error is recorded.";

    case GL_STACK_UNDERFLOW:

        return
            "(GL_STACK_UNDERFLOW) An attempt has been made to perform an operation that would cause an internal stack to underflow.";

    case GL_STACK_OVERFLOW:

        return
            "(GL_STACK_OVERFLOW) An attempt has been made to perform an operation that would cause an internal stack to overflow.";
    }

    return "Error code not recognised.";
}

bool gl_get_errors (
    const std::string& file,
    int                line,
    const std::string& label = "GL_ERROR"
    ) {
    bool   found_errors = false;
    GLenum err;

    while ( ( err = glGetError() ) != GL_NO_ERROR ) {
        found_errors = true;
        std::cerr << "[" << label << "] " << file
                  << ":" << line
                  << " => " << glpp::gl_error_to_string ( err )
                  << std::endl;
    }

    return found_errors;
}
}

#endif // ifndef GLPP_DEBUG_H
