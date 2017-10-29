#ifndef GLPP_SHADER_H
#define GLPP_SHADER_H

#include <GL/glew.h>

#include <memory>
#include <string>

namespace glpp
{
class shader
{
public:
    enum class type : GLenum {
        compute         = GL_COMPUTE_SHADER,
        vertex          = GL_VERTEX_SHADER,
        tess_control    = GL_TESS_CONTROL_SHADER,
        tess_evaluation = GL_TESS_EVALUATION_SHADER,
        geometry        = GL_GEOMETRY_SHADER,
        fragment        = GL_FRAGMENT_SHADER
    };

    shader( enum type          type,
            const std::string& source );

    shader( shader&& move );

    shader( const shader& copy ) = delete;

    virtual ~shader();

    shader& operator=( shader&& move );

    shader& operator=( const shader& copy ) = delete;


    GLuint      handle() const;

    enum type   type() const;

    std::string source() const;


    shader&     compile();

    bool        compile_status() const;

    std::string info_log ( size_t size = 1024 ) const;

private:
    GLuint _handle;

    enum type _type;

    std::string _source;
};
}

#endif // ifndef GLPP_SHADER_H
