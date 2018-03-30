#include "aspect.h"

namespace shimmer
{
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
