#ifndef COMMON_ELLIPSE_H
#define COMMON_ELLIPSE_H

#include "coords.h"

#include <vector>

namespace common::ellipse
{
/**
 * @brief Gets a cartesian point on an ellipse using the parametric equation:
 * [ x, y ] = [ a cos(t), b sin(t) ]
 * @param a Radius along the x axis.
 * @param b Radius along the y axis.
 * @param t The parameter in radians [ 0, 2xPI ]
 * @return The cartesian coordinates at the given parameter.
 */
coords_2f parametric ( float a,
                       float b,
                       float t );

/**
 * @brief Gets cartesian points on an ellipse using the parametric equation:
 * [ x, y ] = [ a cos(t), b sin(t) ]
 * @param a Radius along the x axis.
 * @param b Radius along the y axis.
 * @param params The parameters in radians [ 0, 2xPI ]
 * @return The a vector of cartesian coordinates corresponding to the given
 * parameters.
 */
std::vector<coords_2f> parametric ( float              a,
                                    float              b,
                                    std::vector<float> params );
}

#endif // ifndef COMMON_ELLIPSE_H
