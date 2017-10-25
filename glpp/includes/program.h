#ifndef GLPP_PROGRAM_H
#define GLPP_PROGRAM_H

#include "shader.h"

#include <GL/glew.h>

namespace glpp
{
class program
{
public:
    program();

    program( program&& move );

    program( const program& copy ) = delete;

    virtual ~program();

    program&    operator=( program&& move );

    program&    operator=( const program& copy ) = delete;

    void        attach ( const glpp::shader& shader );

    void        detach ( const glpp::shader& shader );

    void        link();

    bool        link_status() const;

    std::string info_log ( size_t size = 1024 ) const;

    void        use() const;

    GLint       attribute_location ( const std::string& name ) const;

    GLint       uniform_location ( const std::string& name ) const;

private:
    GLuint _handle;
};
}

#endif // ifndef GLPP_PROGRAM_H
