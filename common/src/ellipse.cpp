#include "ellipse.h"

#include <cmath>

namespace common::ellipse
{
coords_2f parametric ( float a, float b, float t ) {
    return { a* std::cos ( t ), b* std::sin ( t ) };
}

std::vector<coords_2f> parametric ( float              a,
                                    float              b,
                                    std::vector<float> params ) {
    std::vector<coords_2f> coords;

    coords.reserve ( params.size() );

    for ( const auto& t : params ) {
        coords.push_back ( { a* std::cos ( t ), b * std::sin ( t ) } );
    }

    return coords;
}
}
