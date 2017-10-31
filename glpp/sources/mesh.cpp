#include "mesh.h"

using namespace glpp;
using namespace std;

mesh& mesh::vertices ( vertex_buffer<GLfloat>&& vbo,
                       element_array_buffer&&   ebo )
{
    _vbo = std::move ( vbo );
    _ebo = std::move ( ebo );

    return *this;
}

mesh& mesh::shader ( const std::shared_ptr<program>& program )
{
    _program = program;
    _program->use();

    auto position = _program->attribute_location ( "position" );
    auto colour   = _program->attribute_location ( "colour" );
    auto texcoord = _program->attribute_location ( "texcoord" );

    _vao.bind();
    _ebo.bind();
    _vbo.bind().attribute_pointers ( {
        { position, 3 },
        { colour, 3 },
        { texcoord, 2 }
    } );
    _vao.enable_attribute_arrays ( { position, colour, texcoord } )
        .unbind();

    _vbo.unbind();
    _ebo.unbind();

    return *this;
}

mesh& mesh::bind()
{
    _vao.bind();

    return *this;
}

mesh& mesh::unbind()
{
    _vao.unbind();

    return *this;
}

mesh& mesh::draw()
{
    glDrawElements ( GL_TRIANGLES, _ebo.elements(), GL_UNSIGNED_INT, 0 );

    return *this;
}
