#include "env.h"

namespace common::env
{
std::string evar ( const std::string& evar, const std::string& defaultt ) {
    auto val = getenv ( evar.c_str() );

    return val ?  std::string ( val ) : defaultt;
}

std::string evar ( const std::string& evar ) {
    auto val = getenv ( evar.c_str() );

    if ( val ) return std::string ( val );

    throw evar_not_found_exception ( evar );
}

evar_not_found_exception::evar_not_found_exception( const std::string& evar )
    : runtime_error (
          "Could not find the following environment variable: " + evar )
{}
}
