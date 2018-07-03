#include "input.h"

namespace shimmer::input
{
common::dims_2f absolute_transform ( const common::dims_2f& source,
                                     const common::dims_2f& target,
                                     const common::dims_2f& aspect ) {
    return source / target * aspect;
}

common::dims_2f relative_transform ( const common::dims_2f& source,
                                     const common::dims_2f& target ) {
    return source / target;
}
}
