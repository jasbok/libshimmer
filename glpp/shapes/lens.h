#ifndef GLPP_SHAPES_LENS_H
#define GLPP_SHAPES_LENS_H

#include "common/dims.h"

#include <vector>

namespace glpp::shapes
{
class lens
{
    common::dims_2f _dims;
    float _curve_factor;
    unsigned int _curve_detail;
    bool _flip_x;
    bool _flip_y;

public:
    lens();

    virtual ~lens() = default;

    lens&                     dims ( const common::dims_2f& dims );

    lens&                     curve_factor ( float factor );

    lens&                     curve_detail ( unsigned int detail );

    lens&                     flip_x();

    lens&                     flip_x ( bool flip_x );

    lens&                     flip_y();

    lens&                     flip_y ( bool flip_y );

    std::vector<float>        position_texcoord();

    std::vector<unsigned int> indices();
};
}

#endif // ifndef GLPP_SHAPES_H
