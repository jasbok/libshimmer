#include "shapes.h"

#include "common/coords.h"
#include "common/ellipse.h"
#include "common/rectangle.h"
#include "common/series.h"

#include <cmath>

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

float fx ( float y, float m ) {
    return m * y;
}

float fy ( float x, float m ) {
    return x / m;
}

float gx2 ( float m, float a1, float a2 ) {
    return a2 * a2 / (  m * m + 1.0f / ( a1 * a1 ) );
}

float gy2 ( float m, float a1, float a2 ) {
    return a2 * a2 * ( 1 - a2 * a2 / ( m * m * a1 * a1 + 1 ) );
}

std::vector<float> quad::position_texcoord_lens_distortion ( unsigned int detail )
{
    unsigned int segments = detail * 8;
    double sradians       = 2 * M_PI / static_cast<double>( segments );

    float ax = _flip_x ? -_aspect.width : _aspect.width;
    float ay = _flip_y ? -_aspect.height : _aspect.height;

    auto radians = common::series::sequential<float>(
        0.0f,
        static_cast<float>( 2 * M_PI ),
        static_cast<float>( sradians ) );

    auto ellipcoords =
        common::ellipse::parametric ( ax * 0.8, ay * 0.8, radians );
    auto rectcoords = common::rectangle::parametric ( ax, ay, radians );
    auto position   = common::series::blend ( ellipcoords, rectcoords, 0.85f );

    auto texcoords = common::series::blend ( ellipcoords, rectcoords, 0.75f );

    texcoords = common::series::transform ( texcoords, 0.5f, 0.5f );

    std::vector<float> values;

    values.reserve ( ( segments + 2 ) * 4 );

    // Center
    values.push_back ( 0.0f );
    values.push_back ( 0.0f );
    values.push_back ( 0.5f );
    values.push_back ( 0.5f );

    for ( unsigned int i = 0; i < segments; i++ ) {
        values.push_back ( position[i].x );
        values.push_back ( position[i].y );
        values.push_back ( texcoords[i].x );
        values.push_back ( texcoords[i].y );
    }

    // Repeat first segment vertex to complete lens.
    values.push_back ( position[0].x );
    values.push_back ( position[0].y );
    values.push_back ( texcoords[0].x );
    values.push_back ( texcoords[0].y );

    return values;
}

std::vector<unsigned int> quad::triangles_indices = {
    0, 1, 2,
    2, 3, 0
};

std::vector<unsigned int> quad::triangle_fan_indices = {
    0, 1, 2, 3
};

std::vector<unsigned int> quad::position_texcoord_lens_distortion_indices (
    unsigned int detail )
{
    unsigned int segments = detail * 8;
    std::vector<unsigned int> indices;

    indices.reserve ( segments + 2 );

    for ( unsigned int i = 0; i < segments + 2; i++ ) {
        indices.push_back ( i );
    }

    return indices;
}
}
