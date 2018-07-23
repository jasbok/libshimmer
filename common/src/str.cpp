#include "str.h"

#include <sstream>

namespace common::str
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

std::string replace ( const std::string& src,
                      const std::string& match,
                      const std::string& repl )
{
    return std::regex_replace ( src, std::regex ( match ), repl );
}

bool contains ( const std::string& src, const std::string& match )
{
    return std::regex_search ( src, std::regex ( match ) );
}

std::string join ( const std::vector<std::string> strings,
                   const std::string              separator )
{
    std::stringstream ss;

    if ( !strings.empty() ) {
        for ( unsigned int i = 0; i < strings.size() - 1; i++ ) {
            ss << strings[i] << separator;
        }
        ss << strings.back();
    }

    return ss.str();
}

std::string upper ( const std::string& str ) {
    std::string upper;

    upper.resize ( str.length() );
    std::transform ( str.begin(), str.end(), upper.begin(), ::toupper );

    return upper;
}

std::string lower ( const std::string& str ) {
    std::string lower;

    lower.resize ( str.length() );
    std::transform ( str.begin(), str.end(), lower.begin(), ::tolower );

    return lower;
}
} // namespace common::str
