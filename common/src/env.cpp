#include "env.h"

#include "str.h"

extern char** environ;

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

std::unordered_map<std::string, std::string> evars() {
    static std::regex keyval_sep ( "=" );

    std::unordered_map<std::string, std::string> map;

    for ( auto env = environ; *env != nullptr; env++ ) {
        auto split = common::str::split ( *env, keyval_sep );

        if ( split.size() == 2 ) {
            map.insert ( { split[0], split[1] } );
        }
    }

    return map;
}

std::unordered_map<std::string, std::string>
find_all ( const std::regex& reg ) {
    std::unordered_map<std::string, std::string> results;

    for ( auto& pair : env::evars() ) {
        if ( std::regex_match ( pair.first, reg ) ) {
            results.insert ( pair );
        }
    }

    return results;
}

std::string evar_upper_snake ( const std::vector<std::string>& path )
{
    return evar ( str::upper ( str::join ( path, "_" ) ) );
}

evar_not_found_exception::evar_not_found_exception( const std::string& evar )
    : runtime_error (
          "Could not find the following environment variable: " + evar )
{}
}
