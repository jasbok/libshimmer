#ifndef GLPP_ATTRIBUTE_H
#define GLPP_ATTRIBUTE_H

#include <GL/glew.h>

#include <string>
#include <vector>

namespace glpp
{
class attribute
{
public:
    attribute( GLint              location,
               const std::string& name );

    attribute( attribute&& move );

    attribute( const attribute& copy ) = delete;

    virtual ~attribute();

    attribute& operator=( attribute&& move );

    attribute& operator=( const attribute& copy ) = delete;


    GLint       location() const;

    std::string name() const;

private:
    GLint _location;

    std::string _name;
};
}

#endif // ifndef GLPP_ATTRIBUTE_H
