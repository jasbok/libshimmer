#include "gl_shapes.h"

#include <vector>

using namespace shimmer;
using namespace std;

gl_mesh opengl::create_textured_quad ( float aspect_ratio, bool flip_y ) {
    float x = aspect_ratio >= 1.0f ? 1.0f : aspect_ratio;
    float y = aspect_ratio >= 1.0f ? 1.0f / aspect_ratio : 1.0f;

    float flip = flip_y ? -1.0f : 1.0f;

    vector<GLfloat> vertices = { -x, y,  0.0f, -1.0f,  1.0f * flip,
                                 -x, -y, 0.0f, -1.0f, -1.0f * flip,
                                 x,  -y, 0.0f,  1.0f, -1.0f * flip,
                                 x,  y,  0.0f,  1.0f, 1.0f * flip };

    vector<GLsizeiptr> elements = { 1, 2, 3,
                                    3, 4, 1 };

    return gl_mesh ( vertices, elements, 5, 3 );
}
