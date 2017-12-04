#include "serialisers.h"

using json = nlohmann::json;

namespace shimmer
{
void to_json ( json& json, const limiter& obj )
{
    json["limit"]   = obj.limit();
    json["samples"] = obj.samples();
}

void from_json ( const nlohmann::json& json, limiter& obj )
{
    obj.limit ( json.at ( "limit" ) );
    obj.samples ( json.at ( "samples" ) );
}
}
