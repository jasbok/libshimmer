#include "rectangle.h"

#include <cmath>

namespace common::rectangle
{
coords_2f parametric ( float w,
                       float h,
                       float t ) {
    static float pi = static_cast<float>( M_PI );

    float d45  = 0.25f * pi;
    float d135 = 0.75f * pi;
    float d225 = 1.25f * pi;
    float d315 = 1.75f * pi;
    float d360 = 2 * pi;

    float m = std::tan ( t );

    t = t > d360 ? std::fmod ( t, d360 ) : t;

    if ( ( d315 < t ) || ( t <= d45 ) ) return { w, m* h };
    else if ( ( d45 < t ) && ( t <= d135 ) ) return { w / m, h };
    else if ( ( d135 <= t ) && ( t <= d225 ) ) return { -w, m* -h };

    return { -w / m, -h };
}

std::vector<coords_2f> parametric ( float              w,
                                    float              h,
                                    std::vector<float> params ) {
    static float pi = static_cast<float>( M_PI );

    std::vector<coords_2f> coords;

    coords.reserve ( params.size() );

    float d45  = 0.25f * pi;
    float d135 = 0.75f * pi;
    float d225 = 1.25f * pi;
    float d315 = 1.75f * pi;
    float d360 = 2 * pi;

    for ( auto t : params ) {
        float m = std::tan ( t );
        t = t > d360 ? std::fmod ( t, d360 ) : t;

        if ( ( d315 < t ) || ( t <= d45 ) ) {
            coords.push_back ( { w, m * h } );
        }
        else if ( ( d45 < t ) && ( t <= d135 ) ) {
            coords.push_back ( { w / m, h } );
        }
        else if ( ( d135 <= t ) && ( t <= d225 ) ) {
            coords.push_back ( { -w, m * -h } );
        }
        else {
            coords.push_back ( { -w / m, -h } );
        }
    }

    return coords;
}
} // namespace common::rectangle
