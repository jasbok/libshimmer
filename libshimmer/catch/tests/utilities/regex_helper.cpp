#include "regex_helper.h"

#include "catch/catch.hpp"

using namespace std;
using namespace shimmer;

TEST_CASE ( "Perform a simple digit regex match.",
            "[regex_helper]" )
{
    auto numbers =
        "A few numbers include 5, 10, 20 and 100.\n"
        "100 is a multiple of 20 and 10. It is also\n"
        "a multiple of 5.";

    regex digit_regex ( "\\d+" );
    auto matches = regex_helper::find_all ( numbers, digit_regex);

    REQUIRE( matches.size() == 8);
    REQUIRE( matches[0].size() == 1);

    CHECK ( matches[0][0] ==  "5" );
    CHECK ( matches[1][0] ==  "10" );
    CHECK ( matches[2][0] ==  "20" );
    CHECK ( matches[3][0] ==  "100" );
    CHECK ( matches[4][0] ==  "100" );
    CHECK ( matches[5][0] ==  "20" );
    CHECK ( matches[6][0] ==  "10" );
    CHECK ( matches[7][0] ==  "5" );
}

TEST_CASE ( "Perform a float regex match.",
            "[regex_helper]" )
{
    auto floats =
        "A few floating point numbers include 5.0, 10.5, 20.3 and 100.101.\n"
        "These numbers can also be denoted with a suffix 'f', ex. 5.0f, \n"
        "10.5f, 20.3f or 100.101f.";

    regex float_regex ( "(\\d+)\\.(\\d+)f?" );
    auto matches = regex_helper::find_all ( floats, float_regex);

    REQUIRE( matches.size() == 8);
    REQUIRE( matches[0].size() == 3);

    CHECK ( matches[0][0] ==  "5.0" );
    CHECK ( matches[1][0] ==  "10.5" );
    CHECK ( matches[2][0] ==  "20.3" );
    CHECK ( matches[3][0] ==  "100.101" );
    CHECK ( matches[4][0] ==  "5.0f" );
    CHECK ( matches[5][0] ==  "10.5f" );
    CHECK ( matches[6][0] ==  "20.3f" );
    CHECK ( matches[7][0] ==  "100.101f" );

    CHECK ( matches[0][1] ==  "5" );
    CHECK ( matches[1][1] ==  "10" );
    CHECK ( matches[2][1] ==  "20" );
    CHECK ( matches[3][1] ==  "100" );
    CHECK ( matches[4][1] ==  "5" );
    CHECK ( matches[5][1] ==  "10" );
    CHECK ( matches[6][1] ==  "20" );
    CHECK ( matches[7][1] ==  "100" );

    CHECK ( matches[0][2] ==  "0" );
    CHECK ( matches[1][2] ==  "5" );
    CHECK ( matches[2][2] ==  "3" );
    CHECK ( matches[3][2] ==  "101" );
    CHECK ( matches[4][2] ==  "0" );
    CHECK ( matches[5][2] ==  "5" );
    CHECK ( matches[6][2] ==  "3" );
    CHECK ( matches[7][2] ==  "101" );
}

TEST_CASE ( "Perform a float regex match, changing the order of groups.",
            "[regex_helper]" )
{
    auto floats =
        "A few floating point numbers include 5.0, 10.5, 20.3 and 100.101.\n"
        "These numbers can also be denoted with a suffix 'f', ex. 5.0f, \n"
        "10.5f, 20.3f or 100.101f.";

    regex float_regex ( "(\\d+)\\.(\\d+)f?" );
    auto matches = regex_helper::find_all ( floats, float_regex, {2, 1});

    REQUIRE( matches.size() == 8);
    REQUIRE( matches[0].size() == 2);

    CHECK ( matches[0][1] ==  "5" );
    CHECK ( matches[1][1] ==  "10" );
    CHECK ( matches[2][1] ==  "20" );
    CHECK ( matches[3][1] ==  "100" );
    CHECK ( matches[4][1] ==  "5" );
    CHECK ( matches[5][1] ==  "10" );
    CHECK ( matches[6][1] ==  "20" );
    CHECK ( matches[7][1] ==  "100" );

    CHECK ( matches[0][0] ==  "0" );
    CHECK ( matches[1][0] ==  "5" );
    CHECK ( matches[2][0] ==  "3" );
    CHECK ( matches[3][0] ==  "101" );
    CHECK ( matches[4][0] ==  "0" );
    CHECK ( matches[5][0] ==  "5" );
    CHECK ( matches[6][0] ==  "3" );
    CHECK ( matches[7][0] ==  "101" );
}
