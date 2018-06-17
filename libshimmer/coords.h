#ifndef SHIMMER_COORDS_H
#define SHIMMER_COORDS_H

#include "common/coords.h"

namespace shimmer
{
typedef common::coords_2<int> coords_2i;

typedef common::coords_2<float> coords_2f;

typedef common::coords_2<unsigned int> coords_2u;

template<typename T>
std::string to_json ( const common::coords_2<T> coords ) {
    return coords.to_json();
}

template<typename T>
std::string to_json ( const common::coords_3<T> coords ) {
    return coords.to_json();
}
}

#endif // ifndef SHIMMER_COORDS_H
