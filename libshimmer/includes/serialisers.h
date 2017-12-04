#ifndef SHIMMER_SERIALISERS_H
#define SHIMMER_SERIALISERS_H

#include "limiter.h"

#include "json/json.hpp"

namespace shimmer
{
void to_json ( nlohmann::json& json,
               const limiter&  obj );

void from_json ( const nlohmann::json& json,
                 limiter&              obj );
}

#endif // ifndef SHIMMER_SERIALISERS_H
