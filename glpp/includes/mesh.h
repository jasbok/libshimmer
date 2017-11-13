#ifndef GLPP_MESH_H
#define GLPP_MESH_H

#include "element_array_buffer.h"
#include "program.h"
#include "vertex_array.h"
#include "vertex_attrib.h"
#include "vertex_buffer.h"

#include <memory>
#include <vector>

namespace glpp
{
template<typename T>
class mesh
{
    static_assert ( is_gltype<T>(), "Unsupported TYPE for mesh." );

public:
    mesh() = default;

    mesh( mesh&& move ) = default;

    mesh( const mesh& copy ) = delete;

    virtual ~mesh() = default;

    mesh& operator=( mesh&& move ) = default;

    mesh& operator=( const mesh& copy ) = delete;


    mesh& bind() {
        _vao.bind();
        _vbo.bind();
        _ebo.bind();

        return *this;
    }

    mesh& unbind() {
        _vao.unbind();
        _vbo.unbind();
        _ebo.unbind();

        return *this;
    }

    mesh& vertices ( const std::vector<T>& vertices ) {
        _vbo.data ( vertices );

        return *this;
    }

    mesh& indices ( const std::vector<GLuint>& indices ) {
        _ebo.data ( indices );

        return *this;
    }

    mesh& attribs ( const std::vector<vertex_attrib<T>>& attribs ) {
        _attribs = attribs;

        return *this;
    }

    mesh& attribs ( const std::vector<attrib>& attribs ) {
        _attribs = glpp::vertex_attrib_builder<T>::sequential ( attribs );

        return *this;
    }

    mesh& program ( const program& program ) {
        for ( auto& attrib : _attribs ) {
            attrib.location ( program.attribute_location ( attrib.name() ) );
            attrib.define_pointer();
            attrib.enable_array();
        }

        return *this;
    }

    template<GLenum MODE = GL_TRIANGLES>
    mesh& draw() {
        static_assert ( is_drawmode<MODE>(),
                        "Unsupported draw MODE for mesh draw function." );

        glDrawElements ( MODE, _ebo.elements(), GL_UNSIGNED_INT, 0 );

        return *this;
    }

private:
    vertex_buffer<T> _vbo;

    element_array_buffer _ebo;

    std::vector<vertex_attrib<T>> _attribs;

    vertex_array _vao;
};
}

#endif // ifndef GLPP_MESH_H
