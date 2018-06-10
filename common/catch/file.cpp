#include "catch.hpp"

#include "common/file.h"

static const char* TAGS = "[file]";

TEST_CASE ( "Read the contents of various files into strings.", TAGS ) {
    using namespace common::file;
    using namespace std;

    string contents_a = read_all ( "./data/file_a.txt" );
    string contents_b = read_all ( "./data/file_b.txt" );
    string contents_c = read_all ( "./data/file_c" );
    string contents_m = read_all ( "./data/file_multiline.txt" );

    // *INDENT-OFF*
    string expected_multiline_contents =
R"(This is a multiline file.
This is another line.
  This line has two starting spaces.

The previous line is empty.

This is the last line.
)";
 // *INDENT-ON*

    CHECK ( contents_a == "This is text file a. \n" );
    CHECK ( contents_b == "This is text file b. \n" );
    CHECK ( contents_c == "This is file c. \n" );
    CHECK ( contents_m == expected_multiline_contents );

    CHECK_THROWS_AS ( read_all ( "does_not_exist.txt" ), read_exception );

    CHECK_THROWS_WITH ( read_all ( "does_not_exist.txt" ),
                        Catch::Matchers::Contains ( "does_not_exist.txt" ) );
}

TEST_CASE ( "Read the lines of various files into vectors.", TAGS ) {
    using namespace common::file;
    using namespace std;

    typedef vector<string> lines;

    lines contents_a = read_lines ( "./data/file_a.txt" );
    lines contents_b = read_lines ( "./data/file_b.txt" );
    lines contents_c = read_lines ( "./data/file_c" );
    lines contents_m = read_lines ( "./data/file_multiline.txt" );

    lines expected_multiline_contents = {
        "This is a multiline file.",
        "This is another line.",
        "  This line has two starting spaces.",
        "",
        "The previous line is empty.",
        "",
        "This is the last line."
    };

    CHECK ( contents_a == lines{ "This is text file a. " } );
    CHECK ( contents_b == lines{ "This is text file b. " } );
    CHECK ( contents_c == lines{ "This is file c. " } );
    CHECK ( contents_m == expected_multiline_contents );

    CHECK_THROWS_AS ( read_all ( "does_not_exist.txt" ), read_exception );

    CHECK_THROWS_WITH ( read_all ( "does_not_exist.txt" ),
                        Catch::Matchers::Contains ( "does_not_exist.txt" ) );
}
