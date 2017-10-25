#ifndef GLPP_UNIFORM_H
#define GLPP_UNIFORM_H

#include <GL/glew.h>

#include <string>
#include <vector>

namespace glpp
{
class uniform
{
public:
    uniform( GLint              location,
             const std::string& name );

    uniform( uniform&& move );

    uniform( const uniform& copy ) = delete;

    virtual ~uniform();

    uniform&    operator=( uniform&& move );

    uniform&    operator=( const uniform& copy ) = delete;

    GLint       location() const;

    std::string name() const;


    void set ( GLfloat v0 );

    void set ( GLfloat v0,
               GLfloat v1 );

    void set ( GLfloat v0,
               GLfloat v1,
               GLfloat v2 );

    void set ( GLfloat v0,
               GLfloat v1,
               GLfloat v2,
               GLfloat v3 );

    void set ( GLint v0 );

    void set ( GLint v0,
               GLint v1 );

    void set ( GLint v0,
               GLint v1,
               GLint v2 );

    void set ( GLint v0,
               GLint v1,
               GLint v2,
               GLint v3 );

    void set ( GLuint v0 );

    void set ( GLuint v0,
               GLuint v1 );

    void set ( GLuint v0,
               GLuint v1,
               GLuint v2 );

    void set ( GLuint v0,
               GLuint v1,
               GLuint v2,
               GLuint v3 );

    void set ( const std::vector<GLfloat>& value );

    void set ( const std::vector<GLint>& value );

    void set ( const std::vector<GLuint>& value );

    void set ( const std::vector<GLfloat>& value,
               unsigned int                cols,
               bool                        transpose = false );

private:
    GLint _location;
    std::string _name;
};
}

#endif // ifndef GLPP_UNIFORM_H
