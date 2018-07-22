#ifndef SHIMMER_INPUT_H
#define SHIMMER_INPUT_H

#include "common/coords.h"
#include "common/dims.h"

#include <cmath>

namespace shimmer::input
{
struct transform {
    common::coords_2f translate;
    common::coords_2f scale;
};

/**
 * @brief constrain Constrains the input to a box with the bottom left corner
 * at (0, 0) and the top right corner at (width - 1, height - 1).
 * @param x The relative x coordinate to transform.
 * @param y The relative y coordinate to transform.
 * @param dims The dimensions of the box to which to constrain the input.
 */
template<typename T>
void constrain ( T&                     x,
                 T&                     y,
                 const common::dims_2u& dims ) {
    x = x < 0 ? 0
        : x >= static_cast<T>( dims.width )
        ? static_cast<T>( dims.width ) - 1
        : x;

    y = y < 0 ? 0
        : y >= static_cast<T>( dims.height )
        ? static_cast<T>( dims.height ) - 1
        : y;
}

/**
 * @brief transform Transforms the coordinates using the given absolute
 * transform.
 * @param x The relative x coordinate to transform.
 * @param y The relative y coordinate to transform.
 * @param transform The transform to apply to the coordinates.
 */
template<typename T>
void transform ( T&               x,
                 T&               y,
                 const transform& transform ) {
    x -= transform.translate.x;
    y -= transform.translate.y;
    x *= transform.scale.x;
    y *= transform.scale.y;
}

/**
 * @brief transform Transforms the coordinates using the given relative
 * transform.
 * @param x The relative x coordinate to transform.
 * @param y The relative y coordinate to transform.
 * @param transform The transform to apply to the coordinates.
 */
template<typename T>
void transform_relative ( T&                      x,
                          T&                      y,
                          const struct transform& transform ) {
    x = static_cast<T>( std::ceil ( x * transform.scale.x ) );
    y = static_cast<T>( std::ceil ( y * transform.scale.y ) );
}

/**
 * @brief absolute_transform Calculates the absolute coordinates transform for
 * the given display, window and aspect dimensions.
 * @param source The source dimensions.
 * @param target The target dimensions.
 * @param aspect The aspect dimensions.
 * @return The coordinate transform.
 */
struct transform absolute_transform ( const common::dims_2f& source,
                                      const common::dims_2f& target,
                                      const common::dims_2f& aspect );

/**
 * @brief relative_transform Calculates the relative coordinates transform for
 * the given display and window dimensions.
 * @param source The source dimensions.
 * @param target The target dimensions.
 * @return The coordinate transform.
 */
struct transform relative_transform ( const common::dims_2f& source,
                                      const common::dims_2f& target );
} // namespace shimmer::input

#endif // ifndef SHIMMER_INPUT_H
