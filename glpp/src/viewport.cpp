#include "viewport.h"

#include <GL/glew.h>

namespace glpp
{
void viewport ( const common::dims_2u& dims )
{
    glViewport ( 0,
                 0,
                 static_cast<GLint>( dims.width ),
                 static_cast<GLint>( dims.height ) );
}
}
