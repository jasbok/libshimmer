#include "gl_quad.h"

using namespace shimmer;
using namespace std;

shared_ptr<gl_buffer> gl_quad::_ebo;

gl_quad::gl_quad( shared_ptr<gl_program>         program,
                  vector<shared_ptr<gl_texture>> textures )
    : _program ( program ),
      _textures ( textures ),
      _vbo ( make_shared<gl_buffer>( GL_ARRAY_BUFFER,
                                     sizeof( GLfloat ) * 20 ) ),
      _vao ( make_shared<gl_vertex_array>() )
{
    if ( !_ebo ) {
        _ebo = make_shared<gl_buffer>(
            GL_ELEMENT_ARRAY_BUFFER,
            sizeof( GLuint ) * 6,
            std::vector<GLuint>( { 1, 2, 3, 3, 4, 1 } ).data() );
    }
    shape ( 1.0 );
}

gl_quad::gl_quad( shared_ptr<gl_program>         program,
                  vector<shared_ptr<gl_texture>> textures,
                  float                          aspect_ratio,
                  bool                           flip_y )
    : _program ( program ),
      _textures ( textures ),
      _vbo ( make_shared<gl_buffer>( GL_ARRAY_BUFFER,
                                     sizeof( GLfloat ) * 20 ) ),
      _vao ( make_shared<gl_vertex_array>() )
{
    if ( !_ebo ) {
        _ebo = make_shared<gl_buffer>(
            GL_ELEMENT_ARRAY_BUFFER,
            sizeof( GLuint ) * 6,
            std::vector<GLuint>( { 1, 2, 3, 3, 4, 1 } ).data() );
    }

    shape ( aspect_ratio, flip_y );
}

gl_quad& gl_quad::shape ( float aspect_ratio, bool flip_y )
{
    float x = aspect_ratio >= 1.0f ? 1.0f : aspect_ratio;
    float y = aspect_ratio >= 1.0f ? 1.0f / aspect_ratio : 1.0f;

    float flip = flip_y ? -1.0f : 1.0f;

    vector<GLfloat> vertices = { -x, y,  0.0f, -1.0f,  1.0f * flip,
                                 -x, -y, 0.0f, -1.0f, -1.0f * flip,
                                 x,  -y, 0.0f,  1.0f, -1.0f * flip,
                                 x,  y,  0.0f,  1.0f, 1.0f * flip };

    _vbo->data ( vertices.data() );

    return *this;
}

void gl_quad::draw() {
    _program->bind();
    _vao->bind();
    glDrawElements ( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0 );
}
