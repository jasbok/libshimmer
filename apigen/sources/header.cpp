#include "header.h"

#include "common/str.h"

#include "fmt/format.h"
#include "fmt/ostream.h"

namespace apigen
{
header::header( const std::string& source, std::ostream& destination )
    : _source ( source ),
      _destination ( destination )
{
    _open_include_guard_and_includes();
}

header::~header() {
    _close_include_guard();
}

header& header::write ( const struct function_decl& function ) {
    const static char* templ =
        R"(
namespace sym{{
    typedef {0} ( *{1}_handle )( {2} );
    static auto {1} = [] () {{
        auto dlsym_ptr = dlsym ( RTLD_NEXT, "{1}" );
        if ( !dlsym_ptr ) {{
            printf ( "Unable to find function: %s\n", "{1}" );
        }}
        return ( {1}_handle )( dlsym_ptr );
    }} ();
}}

{0} {1} ( {2} );
)";

    std::vector<std::string> parameters;

    for ( const auto& parm : function.parameters ) {
        parameters.push_back ( parm.type_name );
    }

    _destination << fmt::format ( templ,
                                  function.ret.type,
                                  function.name,
                                  common::join ( parameters, ", " ) );

    return *this;
}

header& header::operator<<( const struct function_decl& function ) {
    return write ( function );
}

void header::_open_include_guard_and_includes() {
    const char* templ =
        R"(#ifndef APIGEN_{0}_H
#define APIGEN_{0}_H

#include {1}

#include <dlfcn.h>
)";

    _destination << fmt::format ( templ,
                                  _source.stem().c_str(),
                                  _source.filename() );
}

void header::_close_include_guard() {
    _destination << "#endif\n";
}
}
