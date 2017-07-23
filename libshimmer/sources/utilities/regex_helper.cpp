#include "regex_helper.h"

using namespace std;
using namespace shimmer;

vector<vector<string>> regex_helper::find_all (
                        const string& src,
                        const regex& regex,
                        const vector<unsigned int>& groups )
{
    vector<vector<string>> results;
    string target = src;
    smatch match;

    while ( regex_search ( target, match, regex ) ) {
        vector<string> group_matches;

        if ( groups.empty() ) {
            for (unsigned int group = 0; group < match.size(); group++) {
                group_matches.push_back ( match[group].str() );
            }
        } else {
            for ( unsigned int group : groups ) {
                if ( match.size() > group ) {
                    group_matches.push_back ( match[group].str() );
                } else {
                    group_matches.push_back ( string() );
                }
            }
        }

        target = match.suffix();
        results.push_back ( group_matches );
    }

    return results;
}
