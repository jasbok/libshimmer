#ifndef GLPP_PROGRAM_H
#define GLPP_PROGRAM_H

#include <glm/glm.hpp>
#include <GL/glew.h>

#include <string>
#include <unordered_map>
#include <vector>

namespace glpp
{
class shader;

class program
{
public:
    program();

    program( program&& move );

    program( const program& copy ) = delete;

    virtual ~program();

    program& operator=( program&& move );

    program& operator=( const program& copy ) = delete;


    program&    attach ( const glpp::shader& shader );

    program&    detach ( const glpp::shader& shader );

    program&    link();

    bool        link_status() const;

    std::string info_log ( size_t size = 1024 ) const;

    program&    link_and_throw ( size_t log_size = 1024 );

    program&    use();

    static void unbind();


    GLint attribute_location ( const std::string& name ) const;

    GLint uniform_location ( const std::string& name ) const;


    program& uniform ( const std::string& name,
                       GLfloat            v0 );

    program& uniform ( const std::string& name,
                       GLfloat            v0,
                       GLfloat            v1 );

    program& uniform ( const std::string& name,
                       GLfloat            v0,
                       GLfloat            v1,
                       GLfloat            v2 );

    program& uniform ( const std::string& name,
                       GLfloat            v0,
                       GLfloat            v1,
                       GLfloat            v2,
                       GLfloat            v3 );

    program& uniform ( const std::string& name,
                       GLint              v0 );

    program& uniform ( const std::string& name,
                       GLint              v0,
                       GLint              v1 );

    program& uniform ( const std::string& name,
                       GLint              v0,
                       GLint              v1,
                       GLint              v2 );

    program& uniform ( const std::string& name,
                       GLint              v0,
                       GLint              v1,
                       GLint              v2,
                       GLint              v3 );

    program& uniform ( const std::string& name,
                       GLuint             v0 );

    program& uniform ( const std::string& name,
                       GLuint             v0,
                       GLuint             v1 );

    program& uniform ( const std::string& name,
                       GLuint             v0,
                       GLuint             v1,
                       GLuint             v2 );

    program& uniform ( const std::string& name,
                       GLuint             v0,
                       GLuint             v1,
                       GLuint             v2,
                       GLuint             v3 );


    program& uniform ( const std::string&          name,
                       const std::vector<GLfloat>& value );

    program& uniform ( const std::string&        name,
                       const std::vector<GLint>& value );

    program& uniform ( const std::string&         name,
                       const std::vector<GLuint>& value );


    program& uniform ( const std::string&          name,
                       const std::vector<GLfloat>& value,
                       unsigned int                cols,
                       bool                        transpose = false );


    program& uniform ( const std::string& name,
                       const glm::mat2&   value,
                       bool               transpose = false );

    program& uniform ( const std::string& name,
                       const glm::mat3&   value,
                       bool               transpose = false );

    program& uniform ( const std::string& name,
                       const glm::mat4&   value,
                       bool               transpose = false );


    struct link_exception : public std::runtime_error {
        link_exception( const std::string& log );

        virtual ~link_exception();
    };

private:
    GLuint _handle;

    mutable std::unordered_map<std::string, GLint> _attrib_locations;

    mutable std::unordered_map<std::string, GLint> _uniform_locations;
};
}

#endif // ifndef GLPP_PROGRAM_H
