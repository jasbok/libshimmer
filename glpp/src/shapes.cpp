#include "shapes.h"

namespace glpp
{
quad::quad()
    : _aspect ( { 1.0f, 1.0f } ),
      _flip_x ( false ),
      _flip_y ( false )
{}

quad& quad::aspect ( const common::dims_2f& aspect ) {
    _aspect = aspect;

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
    const float right  = _flip_x ? -_aspect.width : _aspect.width;
    const float left   = -right;
    const float top    = _flip_y ? -_aspect.height : _aspect.height;
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
    const float right  = _flip_x ? -_aspect.width : _aspect.width;
    const float left   = -right;
    const float top    = _flip_y ? -_aspect.height : _aspect.height;
    const float bottom = -top;

    return {
               // position   // texcoords
               right, top, 1.0f, 1.0f,   // TR
               left, top, 0.0f, 1.0f,    // TL
               left, bottom, 0.0f, 0.0f, // BL
               right, bottom, 1.0f, 0.0f // BR
    };
}

std::vector<unsigned int> quad::indices = {
    0, 1, 2,
    2, 3, 0
};
}
