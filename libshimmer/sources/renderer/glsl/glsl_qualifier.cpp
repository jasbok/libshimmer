#include "glsl_qualifier.h"

#include "spdlog/spdlog.h"

#include <memory>

using namespace shimmer;
using namespace std;

static std::shared_ptr<spdlog::logger> LOGGER
    = spdlog::stdout_color_mt ( "glsl_qualifier" );

string glsl::str_from ( glsl::qualifier qualifier )
{
    switch ( qualifier ) {
    case glsl::qualifier::ATTRIBUTE:
        return "attribute";
    case glsl::qualifier::UNIFORM:
        return "uniform";
    case glsl::qualifier::VARYING:
        return "varying";
    default:
        return "unknown";
    }
}

glsl::qualifier glsl::qualifier_from ( const string& str )
{
    if ( str.compare ( "uniform" ) == 0 ) {
        return glsl::qualifier::UNIFORM;
    } else if ( str.compare ( "attribute" ) == 0 ) {
        return glsl::qualifier::ATTRIBUTE;
    } else if ( str.compare ( "varying" ) == 0 ) {
        return glsl::qualifier::VARYING;
    }

    LOGGER->warn ( "Unknown glsl_qualifier: {}", str );
    return glsl::qualifier::UNKNOWN;
}
