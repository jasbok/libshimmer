#include "quad.h"

#include "common/coords.h"
#include "common/ellipse.h"
#include "common/rectangle.h"
#include "common/series.h"

#include <cmath>

namespace glpp::shapes
{
quad::quad()
    : _dims ( { 1.0f, 1.0f } ),
      _flip_x ( false ),
      _flip_y ( false )
{}

quad& quad::dims ( const common::dims_2f& dims ) {
    _dims = dims;

    return *this;
}

quad& quad::flip_x() {
    _flip_x = !_flip_x;

    return *this;
}

quad& quad::flip_x ( bool flip_x ) {
    _flip_x = flip_x;

    return *this;
}

quad& quad::flip_y() {
    _flip_y = !_flip_y;

    return *this;
}

quad& quad::flip_y ( bool flip_y ) {
    _flip_y = flip_y;

    return *this;
}

std::vector<float> quad::position() {
    const float right  = _flip_x ? -_dims.width : _dims.width;
    const float left   = -right;
    const float top    = _flip_y ? -_dims.height : _dims.height;
    const float bottom = -top;

    return {
               // position
               right, top,   // TR
               left, top,    // TL
               left, bottom, // BL
               right, bottom // BR
    };
}

std::vector<float> quad::position_texcoord() {
    const float right  = _flip_x ? -_dims.width : _dims.width;
    const float left   = -right;
    const float top    = _flip_y ? -_dims.height : _dims.height;
    const float bottom = -top;

    return {
               // position   // texcoords
               right, top, 1.0f, 1.0f,   // TR
               left, top, 0.0f, 1.0f,    // TL
               left, bottom, 0.0f, 0.0f, // BL
               right, bottom, 1.0f, 0.0f // BR
    };
}

std::vector<unsigned int> quad::triangles_indices = {
    0, 1, 2,
    2, 3, 0
};

std::vector<unsigned int> quad::triangle_fan_indices = {
    0, 1, 2, 3
};
} // namespace glpp::shapes
