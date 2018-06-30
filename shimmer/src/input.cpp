#include "input.h"

namespace shimmer::input
{
common::dims_2f absolute_transform ( const common::dims_2f& display,
                                     const common::dims_2f& window,
                                     const common::dims_2f& aspect ) {
    return display / window * aspect;
}

common::dims_2f relative_transform ( const common::dims_2f& display,
                                     const common::dims_2f& window ) {
    return display / window;
}
}
