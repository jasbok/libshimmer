#ifndef GLPP_VERTEX_ARRAY_H
#define GLPP_VERTEX_ARRAY_H

#include "enums.h"

#include <GL/glew.h>

#include <string>
#include <vector>

namespace glpp
{
class vertex_array
{
public:
    struct vertex_attribute {
        int    location;
        size_t dimensions;
    };

    typedef std::vector<vertex_attribute> vertex_attributes;


    vertex_array();

    vertex_array( vertex_array&& move );

    vertex_array( const vertex_array& copy ) = delete;

    virtual ~vertex_array();

    vertex_array& operator=( vertex_array&& move );

    vertex_array& operator=( const vertex_array& copy ) = delete;


    GLuint handle() const;


    vertex_array& bind();

    void          unbind();


    vertex_array&
    attribute_pointers ( gl_type                  type,
                         const vertex_attributes& attribs,
                         bool                     normalised = false );

    vertex_array& enable_attribute_arrays ( const std::vector<int>& locations );

    vertex_array& disable_attribute_arrays ( const std::vector<int>& locations );

private:
    GLuint _handle;
};
}

#endif // ifndef GLPP_VERTEX_ARRAY_H
