#include "aspect.h"

namespace shimmer
{
void to_json ( nlohmann::json& json, const aspect_ratio& obj )
{
    switch ( obj ) {
    case aspect_ratio::original:
        json = "original";
        break;

    case aspect_ratio::stretch:
        json = "stretch";
        break;

    case aspect_ratio::zoom:
        json = "zoom";
        break;
    }
}

void from_json ( const nlohmann::json& json, aspect_ratio& obj )
{
    std::string ar = json;

    if ( ar.compare ( "stretch" ) == 0 ) {
        obj = aspect_ratio::stretch;
    }
    else if ( ar.compare ( "zoom" ) == 0 ) {
        obj = aspect_ratio::zoom;
    }
    else {
        obj = aspect_ratio::original;
    }
}

#define TO_JSON( T ) \
case aspect_ratio::T: return std::string ( "\""# T "\"" )

std::string to_json ( const aspect_ratio ratio ) {
    switch ( ratio ) {
        TO_JSON ( original );
        TO_JSON ( stretch );
        TO_JSON ( zoom );
    }

    throw std::runtime_error (
              "The to_json() function has not been implemented for aspect_ratio." );
}
}
