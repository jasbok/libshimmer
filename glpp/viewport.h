#ifndef GLPP_VIEWPORT_H
#define GLPP_VIEWPORT_H

#include "common/dims.h"

namespace glpp
{
/**
 * @brief viewport Sets the viewport with an offset of (0, 0) and the given
 * dimensions.
 * @param dims The dimensions of the viewport.
 */
void viewport ( const common::dims_2u& dims );
}

#endif // ifndef GLPP_VIEWPORT_H
