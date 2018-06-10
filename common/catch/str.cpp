#include "catch.hpp"

#include "common/str.h"

static const char* TAGS = "[string]";

TEST_CASE ( "Split strings using a regex.", TAGS ) {
    using namespace common::str;
    using namespace std;

    string str_a = "/a/b/c/d/e";
    string str_b = "a/b/c/d/e";
    string str_c = "a/b/c/d/e/";
    string str_d = "a/b/c//d/e";

    regex regex_a ( "/" );
    regex regex_b ( ":" );

    auto split_a = split ( str_a, regex_a );
    auto split_b = split ( str_b, regex_a );
    auto split_c = split ( str_c, regex_a );
    auto split_d = split ( str_d, regex_a );
    auto split_e = split ( str_a, regex_b );

    REQUIRE ( split_a.size() == 6 );
    CHECK ( split_a == vector<string>{ "", "a", "b", "c", "d", "e" } );

    REQUIRE ( split_b.size() == 5 );
    CHECK ( split_b == vector<string>{ "a", "b", "c", "d", "e" } );

    REQUIRE ( split_c.size() == 6 );
    CHECK ( split_c == vector<string>{ "a", "b", "c", "d", "e", "" } );

    REQUIRE ( split_d.size() == 6 );
    CHECK ( split_d == vector<string>{ "a", "b", "c", "", "d", "e" } );

    REQUIRE ( split_e.size() == 1 );
    CHECK ( split_e == vector<string>{ "/a/b/c/d/e" } );
}

TEST_CASE ( "Split strings using a regex, filtering out empty segments.",
            TAGS ) {
    using namespace common::str;
    using namespace std;

    string str_a = "/a/b/c/d/e";
    string str_b = "a/b/c/d/e";
    string str_c = "a/b/c/d/e/";
    string str_d = "a/b/c//d/e";

    regex regex_a ( "/" );
    regex regex_b ( ":" );

    auto split_a = split_ignore_empty ( str_a, regex_a );
    auto split_b = split_ignore_empty ( str_b, regex_a );
    auto split_c = split_ignore_empty ( str_c, regex_a );
    auto split_d = split_ignore_empty ( str_d, regex_a );
    auto split_e = split_ignore_empty ( str_a, regex_b );

    REQUIRE ( split_a.size() == 5 );
    CHECK ( split_a == vector<string>{ "a", "b", "c", "d", "e" } );

    REQUIRE ( split_b.size() == 5 );
    CHECK ( split_b == vector<string>{ "a", "b", "c", "d", "e" } );

    REQUIRE ( split_c.size() == 5 );
    CHECK ( split_c == vector<string>{ "a", "b", "c", "d", "e" } );

    REQUIRE ( split_d.size() == 5 );
    CHECK ( split_d == vector<string>{ "a", "b", "c", "d", "e" } );

    REQUIRE ( split_e.size() == 1 );
    CHECK ( split_e == vector<string>{ "/a/b/c/d/e" } );
}

TEST_CASE (
    "Join a list of strings into a composite string using the specified separator",
    TAGS ) {
    using namespace common::str;
    using namespace std;

    const vector<string> vec_none;
    const vector<string> vec_one   = { "a" };
    const vector<string> vec_two   = { "a", "b" };
    const vector<string> vec_three = { "a", "b", "c" };

    const string sep_empty;
    const string sep_char = ",";
    const string sep_str  = " and ";

    CHECK ( join ( vec_none, sep_empty ) == "" );
    CHECK ( join ( vec_none, sep_char ) == "" );
    CHECK ( join ( vec_none, sep_str ) == "" );

    CHECK ( join ( vec_one, sep_empty ) == "a" );
    CHECK ( join ( vec_one, sep_char ) == "a" );
    CHECK ( join ( vec_one, sep_str ) == "a" );

    CHECK ( join ( vec_two, sep_empty ) == "ab" );
    CHECK ( join ( vec_two, sep_char ) == "a,b" );
    CHECK ( join ( vec_two, sep_str ) == "a and b" );

    CHECK ( join ( vec_three, sep_empty ) == "abc" );
    CHECK ( join ( vec_three, sep_char ) == "a,b,c" );
    CHECK ( join ( vec_three, sep_str ) == "a and b and c" );
}
