#include "str.h"

namespace common
{
std::vector<std::string> split ( const std::string& str,
                                 const std::regex&  reg )
{
    std::vector<std::string> split;

    std::string str_reg = str;
    std::smatch match;

    while ( regex_search ( str_reg, match, reg ) ) {
        split.push_back ( match.prefix() );
        str_reg = match.suffix();
    }

    split.push_back ( str_reg );

    return split;
}

std::vector<std::string> split_ignore_empty ( const std::string& str,
                                              const std::regex&  reg )
{
    std::vector<std::string> split;

    std::string str_reg = str;
    std::smatch match;

    while ( regex_search ( str_reg, match, reg ) ) {
        if ( match.prefix().length() ) {
            split.push_back ( match.prefix() );
        }

        str_reg = match.suffix();
    }

    if ( !str_reg.empty() ) {
        split.push_back ( str_reg );
    }

    return split;
}
}
