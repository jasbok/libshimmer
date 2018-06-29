#include "video.h"

namespace shimmer::video
{
common::dims_2f aspect_transform ( const common::dims_2u& display,
                                   const common::dims_2u& window,
                                   const shimmer::config& config )
{
    auto aspect = config.video.aspect;

    if ( aspect == config::video::aspect::stretch ) {
        return { 1.0f, 1.0f };
    }

    float ar_factor = display.wh_ratio() / window.wh_ratio();

    if ( aspect == config::video::aspect::original ) {
        return { ar_factor > 1.0f ?  1.0f : ar_factor,
                 ar_factor > 1.0f ? 1.0f / ar_factor : 1.0f };
    }

    if ( aspect == config::video::aspect::zoom ) {
        return { ar_factor < 1.0f ?  1.0f : ar_factor,
                 ar_factor < 1.0f ? 1.0f / ar_factor : 1.0f };
    }

    common::dims_2f custom = config.video.custom_aspect;

    ar_factor = custom.wh_ratio() / window.wh_ratio();

    return { ar_factor > 1.0f ?  1.0f : ar_factor,
             ar_factor > 1.0f ? 1.0f / ar_factor : 1.0f };

    // return custom / std::max ( custom.width, custom.height );
}
}
