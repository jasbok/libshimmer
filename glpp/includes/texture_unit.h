#ifndef GLPP_TEXTURE_UNIT_H
#define GLPP_TEXTURE_UNIT_H

#include "GL/glew.h"

namespace glpp
{
class texture_unit
{
public:
    texture_unit( GLint index );

    virtual ~texture_unit() = default;

    texture_unit& activate();

    GLint         index();

private:
    GLenum _unit;
};
}

#endif // ifndef GLPP_TEXTURE_UNIT_H
