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
std::string gl_error_to_string ( GLenum err );

bool        gl_get_errors ( const std::string& file,
                            int                line,
                            const std::string& label = "GL_ERROR" );
}

#endif // ifndef GLPP_DEBUG_H
