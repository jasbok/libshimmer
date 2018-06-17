#include "texture_unit.h"

using namespace glpp;

texture_unit::texture_unit( GLint index )
    : _unit ( GL_TEXTURE0 + index )
{}

texture_unit& texture_unit::activate()
{
    glActiveTexture ( _unit );

    return *this;
}

GLint texture_unit::index()
{
    return _unit - GL_TEXTURE0;
}
