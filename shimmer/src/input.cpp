#include "input.h"

namespace shimmer::input
{
struct transform absolute_transform ( const common::dims_2f& source,
                                      const common::dims_2f& target,
                                      const common::dims_2f& aspect ) {
    auto offset = target * ( common::dims_2f ( 1.0f, 1.0f ) - aspect ) * 0.5f;
    auto scale  = source / target / aspect;

    return {
               {
                   offset.width,
                   offset.height
               },
               {
                   scale.width,
                   scale.height
               }
    };
}

struct transform relative_transform ( const common::dims_2f& source,
                                      const common::dims_2f& target ) {
    auto scale = source / target;

    return {
               { 0, 0 },
               { scale.width, scale.height }
    };
}
} // namespace shimmer::input
