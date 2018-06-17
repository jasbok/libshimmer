#ifndef GLPP_SHADER_H
#define GLPP_SHADER_H

#include <GL/glew.h>

#include <memory>
#include <string>

namespace glpp
{
class shader
{
    struct builder
    {
        static shader compute ( const ::std::string& source );

        static shader fragment ( const ::std::string& source );

        static shader geometry ( const ::std::string& source );

        static shader tess_control ( const ::std::string& source );

        static shader tess_evaluation ( const ::std::string& source );

        static shader vertex ( const ::std::string& source );
    };

public:
    enum class type : GLenum {
        compute         = GL_COMPUTE_SHADER,
        fragment        = GL_FRAGMENT_SHADER,
        geometry        = GL_GEOMETRY_SHADER,
        tess_control    = GL_TESS_CONTROL_SHADER,
        tess_evaluation = GL_TESS_EVALUATION_SHADER,
        vertex          = GL_VERTEX_SHADER
    };

    shader( enum type          type,
            const std::string& source );

    shader( shader&& move );

    shader( const shader& copy ) = delete;

    virtual ~shader();

    static struct builder create();


    shader& operator=( shader&& move );

    shader& operator=( const shader& copy ) = delete;


    GLuint      handle() const;

    enum type   type() const;

    std::string source() const;


    shader&     compile();

    bool        compile_status() const;

    std::string info_log ( size_t size = 1024 ) const;

    shader&     compile_and_throw ( size_t log_size = 1024 );

    struct compile_exception : public std::runtime_error {
        compile_exception( const std::string& source,
                           const std::string& log );

        virtual ~compile_exception();
    };

private:
    GLuint _handle;

    enum type _type;

    std::string _source;
};
}

#endif // ifndef GLPP_SHADER_H
