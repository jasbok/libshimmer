#include "glsl_qualifier.h"

#include "spdlog/spdlog.h"

#include <memory>

using namespace shimmer;
using namespace std;

static shared_ptr<spdlog::logger> LOGGER
    = spdlog::stdout_color_mt ( "glsl_qualifier" );

const std::unordered_map<std::string, glsl::qualifier>
string_qualifier_map = {
    { "attribute", glsl::qualifier::ATTRIBUTE  },
    { "in",        glsl::qualifier::INPUT      },
    { "out",       glsl::qualifier::OUTPUT     },
    { "uniform",   glsl::qualifier::UNIFORM    },
    { "unknown",   glsl::qualifier::UNKNOWN    },
    { "varying",   glsl::qualifier::VARYING    }
};

string glsl::str_from ( glsl::qualifier qualifier )
{
    string str = "unknown";

    switch ( qualifier ) {
    case glsl::qualifier::ATTRIBUTE:
        str = "attribute";
        break;

    case glsl::qualifier::INPUT:
        str = "in";
        break;

    case glsl::qualifier::OUTPUT:
        str = "out";
        break;

    case glsl::qualifier::UNIFORM:
        str = "uniform";
        break;

    case glsl::qualifier::UNKNOWN:
        str = "unknown";
        break;

    case glsl::qualifier::VARYING:
        str = "varying";
        break;
    }

    return str;
}

glsl::qualifier glsl::qualifier_from ( const string& str )
{
    glsl::qualifier qualifier = glsl::qualifier::UNKNOWN;
    auto entry                = string_qualifier_map.find ( str );

    if ( entry != string_qualifier_map.end() ) {
        qualifier = entry->second;
    }
    else {
        LOGGER->warn ( "Unknown glsl_qualifier: {}", str );
    }

    return qualifier;
}
