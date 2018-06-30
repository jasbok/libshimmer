#ifndef SHIMMER_VIDEO_H
#define SHIMMER_VIDEO_H

#include "configuration.h"

#include "common/dims.h"

namespace shimmer::video
{
/**
 * @brief aspect_transform Calculates the aspect transform from the given
 * display and window dimensions based on the provided config.
 * @param display The video display dimensions.
 * @param window The window dimensions.
 * @param config The config to use when calculating the aspect transform.
 * @return The calculated aspect transform.
 */
common::dims_2f aspect_transform ( const common::dims_2u& display,
                                   const common::dims_2u& window,
                                   const shimmer::config& config );
}

#endif // ifndef SHIMMER_VIDEO_H
