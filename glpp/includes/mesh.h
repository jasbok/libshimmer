#ifndef GLPP_MESH_H
#define GLPP_MESH_H

#include "element_array_buffer.h"
#include "program.h"
#include "vertex_array.h"
#include "vertex_buffer.h"

#include <memory>
#include <vector>

namespace glpp
{
class mesh
{
public:
    mesh() = default;

    mesh( mesh&& move ) = default;

    mesh( const mesh& copy ) = delete;

    virtual ~mesh() = default;

    mesh& operator=( mesh&& move ) = default;

    mesh& operator=( const mesh& copy ) = delete;


    mesh& vertices ( vertex_buffer<GLfloat>&& vbo,
                     element_array_buffer&&   ebo );

    mesh& shader ( const std::shared_ptr<program>& program );

    mesh& bind();

    mesh& unbind();

    mesh& draw();

private:
    element_array_buffer _ebo;

    vertex_array _vao;

    vertex_buffer<GLfloat> _vbo;

    std::shared_ptr<program> _program;
};
}

#endif // ifndef GLPP_MESH_H
