#ifndef SHIMMER_INPUT_H
#define SHIMMER_INPUT_H

#include "common/coords.h"
#include "common/dims.h"

namespace shimmer::input
{
/**
 * @brief transform Transforms the coordinates using the given absolute
 * transform.
 * @param x The relative x coordinate to transform.
 * @param y The relative y coordinate to transform.
 * @param transform The transform to apply to the coordinates.
 */
template<typename T>
void transform ( T&                     x,
                 T&                     y,
                 const common::dims_2f& transform ) {
    x *= transform.width;
    y *= transform.height;
}

/**
 * @brief transform Transforms the coordinates using the given relative
 * transform.
 * @param x The relative x coordinate to transform.
 * @param y The relative y coordinate to transform.
 * @param transform The transform to apply to the coordinates.
 */
template<typename T>
void transform_relative ( T&                     x,
                          T&                     y,
                          const common::dims_2f& transform ) {
    x = static_cast<T>( ceilf ( x * transform.width ) );
    y = static_cast<T>( ceilf ( y * transform.height ) );
}

/**
 * @brief absolute_transform Calculates the absolute coordinates transform for
 * the given display, window and aspect dimensions.
 * @param source The source dimensions.
 * @param target The target dimensions.
 * @param aspect The aspect dimensions.
 * @return The coordinate transform.
 */
common::dims_2f absolute_transform ( const common::dims_2f& source,
                                     const common::dims_2f& target,
                                     const common::dims_2f& aspect );

/**
 * @brief relative_transform Calculates the relative coordinates transform for
 * the given display and window dimensions.
 * @param source The source dimensions.
 * @param target The target dimensions.
 * @return The coordinate transform.
 */
common::dims_2f relative_transform ( const common::dims_2f& source,
                                     const common::dims_2f& target );
}

#endif // ifndef SHIMMER_INPUT_H
