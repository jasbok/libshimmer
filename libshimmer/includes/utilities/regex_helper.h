#ifndef LIBSHIMMER_UTITLITIES_REGEX_HELPER_H
#define LIBSHIMMER_UTITLITIES_REGEX_HELPER_H

#include <regex>
#include <string>
#include <vector>

namespace shimmer
{
class regex_helper
{
public:
    static std::vector<std::vector<std::string>> find_all (
                const std::string& src,
                const std::regex& regex,
                const std::vector<unsigned int>& groups = {} );
};
}

#endif
