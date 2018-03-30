#include "catch.hpp"

#include "common/str.h"

static const char* TAGS = "[string]";

TEST_CASE ( "Split strings using a regex.", TAGS ) {
    using namespace std;

    string str_a = "/a/b/c/d/e";
    string str_b = "a/b/c/d/e";
    string str_c = "a/b/c/d/e/";
    string str_d = "a/b/c//d/e";

    regex regex_a ( "/" );
    regex regex_b ( ":" );

    auto split_a = common::split ( str_a, regex_a );
    auto split_b = common::split ( str_b, regex_a );
    auto split_c = common::split ( str_c, regex_a );
    auto split_d = common::split ( str_d, regex_a );
    auto split_e = common::split ( str_a, regex_b );

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
    using namespace std;

    string str_a = "/a/b/c/d/e";
    string str_b = "a/b/c/d/e";
    string str_c = "a/b/c/d/e/";
    string str_d = "a/b/c//d/e";

    regex regex_a ( "/" );
    regex regex_b ( ":" );

    auto split_a = common::split_ignore_empty ( str_a, regex_a );
    auto split_b = common::split_ignore_empty ( str_b, regex_a );
    auto split_c = common::split_ignore_empty ( str_c, regex_a );
    auto split_d = common::split_ignore_empty ( str_d, regex_a );
    auto split_e = common::split_ignore_empty ( str_a, regex_b );

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
