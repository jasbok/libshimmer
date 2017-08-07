#include "gl_model.h"

using namespace shimmer;
using namespace std;

gl_model::gl_model() {}

gl_model::~gl_model() {}

void shimmer::gl_model::render()
{
    auto texture_unit = GL_TEXTURE0;

    for ( const auto& texture : _textures ) {
        glActiveTexture ( texture_unit++ );
        texture->bind();
    }
    _vao->bind();
}
