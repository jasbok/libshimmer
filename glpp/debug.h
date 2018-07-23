#ifndef GLPP_DEBUG_H
#define GLPP_DEBUG_H

#include <GL/glew.h>

#include <iostream>
#include <string>

#define __FILENAME__ ( strrchr ( __FILE__, '/' )       \
                       ? strrchr ( __FILE__, '/' ) + 1 \
                       : __FILE__ )

#ifndef DEBUG
# define GLPP_CHECK_ERROR( LABEL )

# define GLPP_CHECK_FRAMEBUFFER( LABEL )

#else // ifndef DEBUG

# define GLPP_CHECK_ERROR( LABEL ) \
    glpp::gl_get_errors ( __FILENAME__, __LINE__, LABEL )

# define GLPP_CHECK_FRAMEBUFFER( LABEL ) \
    glpp::gl_check_framebuffer ( __FILENAME__, __LINE__, LABEL )

#endif // ifndef DEBUG

namespace glpp
{
std::string gl_error_to_string ( GLenum err );

bool        gl_get_errors ( const std::string& file,
                            int                line,
                            const std::string& label = "GL_ERROR" );


bool gl_check_framebuffer ( const std::string& file,
                            int                line,
                            const std::string& label = "GL_ERROR" );

std::string gl_framebuffer_status_to_string ( GLenum status );
} // namespace glpp

#endif // ifndef GLPP_DEBUG_H
