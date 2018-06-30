#include "json.h"

namespace shimmer
{
std::string to_json ( const unsigned int i ) {
    return std::to_string ( i );
}

std::string to_json ( const std::string& str ) {
    return "\"" + str + "\"";
}
}
