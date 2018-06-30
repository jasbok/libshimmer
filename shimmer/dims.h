#ifndef SHIMMER_DIMS_H
#define SHIMMER_DIMS_H

#include "common/dims.h"

#include "external/json/json.hpp"

namespace shimmer
{
typedef common::dims_2<unsigned int> dims_2u;

typedef common::dims_2<float> dims_2f;

template<typename T>
std::string to_json ( const common::dims_2<T> dims ) {
    return dims.to_json();
}

template<typename T>
std::string to_json ( const common::dims_3<T> dims ) {
    return dims.to_json();
}

void to_json ( nlohmann::json& json,
               const dims_2f&  obj );

void from_json ( const nlohmann::json& json,
                 dims_2f&              obj );
}

#endif // ifndef SHIMMER_DIMS_H
