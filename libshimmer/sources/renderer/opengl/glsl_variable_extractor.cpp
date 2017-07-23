#include "glsl_variable_extractor.h"
#include "regex_helper.h"

using namespace std;
using namespace shimmer;

// 0:qualifier 1:type 2:size 3:name
static const regex VARIABLE_REGEX (
    "\\s*(\\w+)\\s+(\\w+)\\s*(\\[(\\d+)\\])?\\s+([\\w]+).*?;" );

static const regex PREPROCESSOR_REGEX ( "\\#.*" );

vector<glsl_variable> glsl_variable_extractor::extract ( const string& source )
{
    vector<glsl_variable> results;
    string src = regex_replace ( source, PREPROCESSOR_REGEX, "" );

    for ( auto var : regex_helper::find_all (
                src, VARIABLE_REGEX, {1, 2, 4, 5} ) ) {
        auto variable = glsl_variable (
                            glsl_variable::qualifier_from ( var[0] ),
                            glsl_variable::type_from ( var[1] ),
                            var[2].empty() ? 1 : std::stoi ( var[2] ),
                            var[3] );

        results.push_back ( variable );
    }

    return results;
}
