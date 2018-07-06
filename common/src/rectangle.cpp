#include "rectangle.h"

#include <cmath>

namespace common::rectangle
{
coords_2f parametric ( float w,
                       float h,
                       float t ) {
    static float pi = static_cast<float>( M_PI );

    if ( t > 2 * pi ) {
        t = std::fmod ( t, 2 * pi );
    }

    float sigma = std::atan ( h / w );
    float m     = std::tan ( t );

    if ( ( -sigma <= t ) && ( t <= sigma ) ) {
        return { w, m };
    }
    else if ( ( sigma - pi <= t )  && ( t <= pi + sigma ) ) {
        return { -w, m };
    }
    else if ( ( 0.5f * pi - sigma < t )  && ( t <= 0.5f * pi + sigma ) ) {
        return { 1.0f / m, h };
    }
    else {
        return { 1.0f / m, -h };
    }
}

std::vector<coords_2f> parametric ( float              w,
                                    float              h,
                                    std::vector<float> params ) {
    static float pi = static_cast<float>( M_PI );

    std::vector<coords_2f> coords;

    coords.reserve ( params.size() );

    float sigma = std::atan ( h / w );

    for ( auto t : params ) {
        if ( t > 2 * pi ) {
            t = std::fmod ( t, 2 * pi );
        }

        float m = std::tan ( t );

        if ( ( 2 * pi - sigma < t ) || ( t <= sigma ) ) {
            coords.push_back ( { w, m } );
        }
        else if ( ( pi - sigma <= t )  && ( t <= pi + sigma ) ) {
            coords.push_back ( { -w, -m } );
        }
        else if ( ( 0.5f * pi - sigma < t )  && ( t <= 0.5f * pi + sigma ) ) {
            coords.push_back ( { 1.0f / m, h } );
        }
        else {
            coords.push_back ( { -1.0f / m, -h } );
        }
    }

    return coords;
}
}
