#ifndef COMMON_RECTANGLE_H
#define COMMON_RECTANGLE_H

#include "coords.h"
#include <vector>

namespace common::rectangle
{
/**
 * @brief parametric Get the cartesian point a the intersection of the
 * rectangle(w, h) and the line f(x) = x sin(t).
 * @param w The width of the rectangle.
 * @param h The height of the rectangle.
 * @param t The parameter in radians [0, 2 PI]
 * @return The insection of the rectangle and line.
 */
coords_2f parametric ( float w,
                       float h,
                       float t );

/**
 * @brief parametric Get the cartesian points a the intersection of the
 * rectangle(w, h) and the line f(x) = x sin(t) for the different values of t.
 * @param w The width of the rectangle.
 * @param h The height of the rectangle.
 * @param params The parameters in radians [0, 2 PI]
 * @return The insection of the rectangle and line for the values of t.
 */
std::vector<coords_2f> parametric ( float              w,
                                    float              h,
                                    std::vector<float> params );
}

#endif // ifndef COMMON_RECTANGLE_H
