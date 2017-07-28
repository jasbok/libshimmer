#ifndef LIBSHIMMER_UTITLITIES_REGEX_HELPER_H
#define LIBSHIMMER_UTITLITIES_REGEX_HELPER_H

#include <regex>
#include <string>
#include <vector>

namespace shimmer::regex_helper
{
using namespace std;
vector<vector<string>> find_all ( const string&               src,
                                  const regex&                regex,
                                  const vector<unsigned int>& groups = {} );
}

#endif // ifndef LIBSHIMMER_UTITLITIES_REGEX_HELPER_H
