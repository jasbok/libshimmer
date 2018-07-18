#include "lens.h"

#include "common/coords.h"
#include "common/ellipse.h"
#include "common/rectangle.h"
#include "common/series.h"

#include <cmath>

namespace glpp::shapes
{
lens::lens()
    : _dims ( { 1.0f, 1.0f } ),
      _curve_factor ( 0.0f ),
      _curve_detail ( 8 ),
      _flip_x ( false ),
      _flip_y ( false )
{}

lens& lens::dims ( const common::dims_2f& dims ) {
    _dims = dims;

    return *this;
}

lens& lens::curve_factor ( float factor )
{
    _curve_factor = factor;

    return *this;
}

lens& lens::curve_detail ( unsigned int detail )
{
    _curve_detail = detail;

    return *this;
}

lens& lens::flip_x() {
    _flip_x = !_flip_x;

    return *this;
}

lens& lens::flip_x ( bool flip_x ) {
    _flip_x = flip_x;

    return *this;
}

lens& lens::flip_y() {
    _flip_y = !_flip_y;

    return *this;
}

lens& lens::flip_y ( bool flip_y ) {
    _flip_y = flip_y;

    return *this;
}

std::vector<float> lens::position_texcoord()
{
    unsigned int segments = _curve_detail * 8;
    double sradians       = 2 * M_PI / static_cast<double>( segments );

    auto radians = common::series::sequential<float>(
        0.0f,
        static_cast<float>( 2 * M_PI ),
        static_cast<float>( sradians ) );

    auto ellipcoords = common::ellipse::parametric ( _dims.width,
                                                     _dims.height,
                                                     radians );

    auto rectcoords = common::rectangle::parametric ( _dims.width,
                                                      _dims.height,
                                                      radians );

    auto position = common::series::blend ( rectcoords,
                                            ellipcoords,
                                            _curve_factor );

    auto rect_texcoords = common::rectangle::parametric ( 1.0,
                                                          1.0,
                                                          radians );

    auto texcoords = common::series::transform ( rect_texcoords, 0.5f, 0.5f );

    std::vector<float> values;

    values.reserve ( ( segments + 2 ) * 4 );

    // Center
    values.push_back ( 0.0f );
    values.push_back ( 0.0f );
    values.push_back ( 0.5f );
    values.push_back ( 0.5f );

    float sx = _flip_x ? -1.0f : 1.0f;
    float sy = _flip_y ? -1.0f : 1.0f;

    for ( unsigned int i = 0; i < segments; i++ ) {
        values.push_back ( sx * position[i].x );
        values.push_back ( sy * position[i].y );
        values.push_back ( texcoords[i].x );
        values.push_back ( texcoords[i].y );
    }

    // Repeat first segment vertex to complete lens.
    values.push_back ( sx * position[0].x );
    values.push_back ( sy * position[0].y );
    values.push_back ( texcoords[0].x );
    values.push_back ( texcoords[0].y );

    return values;
}

std::vector<unsigned int> lens::indices()
{
    unsigned int segments = _curve_detail * 8;
    std::vector<unsigned int> indices;

    indices.reserve ( segments + 2 );

    for ( unsigned int i = 0; i < segments + 2; i++ ) {
        indices.push_back ( i );
    }

    return indices;
}
} // namespace glpp::shapes
