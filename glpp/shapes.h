#ifndef GLPP_SHAPES_H
#define GLPP_SHAPES_H

#include "common/dims.h"

#include <vector>

namespace glpp
{
class quad
{
    common::dims_2f _aspect;
    bool _flip_x;
    bool _flip_y;

public:
    quad();

    virtual ~quad() = default;

    quad&              aspect ( const common::dims_2f& aspect );

    quad&              flip_x();

    quad&              flip_x ( bool flip_x );

    quad&              flip_y();

    quad&              flip_y ( bool flip_y );

    std::vector<float> position();

    std::vector<float> position_texcoord();

    std::vector<float> position_texcoord_lens_distortion (
        unsigned int detail );

    static std::vector<unsigned int> triangles_indices;

    static std::vector<unsigned int> triangle_fan_indices;

    static std::vector<unsigned int> position_texcoord_lens_distortion_indices (
        unsigned int detail );
};
}

#endif // ifndef GLPP_SHAPES_H
