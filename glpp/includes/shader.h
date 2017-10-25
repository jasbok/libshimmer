#ifndef GLPP_SHADER_H
#define GLPP_SHADER_H

#include <GL/glew.h>

#include <memory>
#include <string>

namespace glpp
{
enum class shader_type {
    fragment, vertex
};

GLenum glEnumFrom ( shader_type type );

class shader
{
public:
    shader( shader_type        type,
            const std::string& source );

    shader( shader&& move );

    shader( const shader& copy ) = delete;

    virtual ~shader();

    shader&     operator=( shader&& move );

    shader&     operator=( const shader& copy ) = delete;

    GLuint      handle() const;

    shader_type type() const;

    std::string source() const;

    void        compile();

    bool        compile_status() const;

    std::string info_log ( size_t size = 1024 ) const;

private:
    GLuint _handle;

    shader_type _type;

    std::string _source;
};
}

#endif // ifndef GLPP_SHADER_H
