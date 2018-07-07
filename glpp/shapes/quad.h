#ifndef GLPP_SHAPES_QUAD_H
#define GLPP_SHAPES_QUAD_H

#include "common/dims.h"

#include <vector>

namespace glpp::shapes
{
class quad
{
    common::dims_2f _dims;
    bool _flip_x;
    bool _flip_y;

public:
    quad();

    virtual ~quad() = default;

    quad&              dims ( const common::dims_2f& aspect );

    quad&              flip_x();

    quad&              flip_x ( bool flip_x );

    quad&              flip_y();

    quad&              flip_y ( bool flip_y );

    std::vector<float> position();

    std::vector<float> position_texcoord();

    static std::vector<unsigned int> triangles_indices;

    static std::vector<unsigned int> triangle_fan_indices;
};
}

#endif // ifndef GLPP_SHAPES_H
