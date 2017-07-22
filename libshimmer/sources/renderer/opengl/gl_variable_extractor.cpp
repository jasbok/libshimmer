#include "gl_variable_extractor.h"
#include "regex_helper.h"

using namespace std;
using namespace shimmer;

vector<glsl_variable> gl_variable_extractor::extract ( const string& source )
{
    vector<glsl_variable> results;

    string src = regex_replace ( source, regex ( "\\#.*" ), "" );

    // 0:qualifier 1:type 2:size 3:name
    regex regex (
        "\\s*(\\w+)\\s+(\\w+)\\s*(\\[(\\d+)\\])?\\s+([\\w]+).*?;" );

    for ( auto var : regex_helper::find_all ( src, regex, {1, 2, 4, 5} ) ) {
        auto variable = glsl_variable (
                            glsl_variable::qualifier_from ( var[0] ),
                            glsl_variable::type_from ( var[1] ),
                            var[2].empty() ? 1 : std::stoi ( var[2] ),
                            var[3] );

        results.push_back ( variable );
    }

    return results;
}

