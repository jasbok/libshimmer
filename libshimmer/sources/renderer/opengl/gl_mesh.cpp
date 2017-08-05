#include "gl_mesh.h"

using namespace shimmer;
using namespace std;

gl_mesh::gl_mesh( vector<GLfloat> vertices,
                  vector<GLsizeiptr> elements,
                  unsigned int  vertices_stride,
                  unsigned int  elements_stride )
    : _vertices ( GL_ARRAY_BUFFER, sizeof(GLfloat) * vertices.size() ),
      _vertices_stride ( vertices_stride ),
      _vertices_count ( vertices.size() / vertices_stride ),
      _elements ( GL_ELEMENT_ARRAY_BUFFER, sizeof(GLsizeiptr) * elements.size() ),
      _elements_stride ( elements_stride ),
      _elements_count ( elements.size() / elements_stride )
{}

gl_mesh::~gl_mesh() {}

void gl_mesh::bind() const {
    _vertices.bind();
    _elements.bind();
}

void gl_mesh::unbind() const {
    _vertices.unbind();
    _elements.unbind();
}
