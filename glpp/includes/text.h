#ifndef GLPP_TEXT_H
#define GLPP_TEXT_H

#include "mesh.h"

#include <string>

namespace glpp
{
class text
{
public:
    text( const std::string& content );

    text( text&& move );

    text( const text& copy ) = delete;

    virtual ~text();

    text& operator=( text&& move );

    text& operator=( const text& copy ) = delete;


    text& bind();

    text& unbind();


    text&       content ( const std::string& content );

    std::string content() const;


    text& draw();

private:
    std::string _content;

    mesh<GLuint> _mesh;

    void _update();
};
}


#endif // ifndef GLPP_TEXT_H
