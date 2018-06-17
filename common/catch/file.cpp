#include "external/catch/catch.hpp"

#include "common/file.h"

static const char* TAGS = "[file]";

TEST_CASE ( "Read the contents of various files into strings.", TAGS ) {
    using namespace common::file;
    using namespace std;

    string contents_a = read_all ( "./data/text/file_a.txt" );
    string contents_b = read_all ( "./data/text/file_b.txt" );
    string contents_c = read_all ( "./data/text/file_c" );
    string contents_m = read_all ( "./data/text/file_multiline.txt" );

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

    lines contents_a = read_lines ( "./data/text/file_a.txt" );
    lines contents_b = read_lines ( "./data/text/file_b.txt" );
    lines contents_c = read_lines ( "./data/text/file_c" );
    lines contents_m = read_lines ( "./data/text/file_multiline.txt" );

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

TEST_CASE ( "Find the first file matching path in given search paths.", TAGS ) {
    using namespace common::file;
    using namespace std;

    vector<string> search_paths = { "data", "data/text", "data/image" };

    CHECK ( find ( "test.png", search_paths ) == "data/image/test.png" );

    CHECK ( find ( "test.jpg", search_paths ) == "data/image/test.jpg" );

    CHECK ( find ( "file_a.txt", search_paths ) == "data/text/file_a.txt" );

    CHECK ( find ( "file_b.txt", search_paths ) == "data/text/file_b.txt" );

    CHECK ( find ( "file_c", search_paths ) == "data/text/file_c" );

    CHECK ( find ( "file_multiline.txt", search_paths )
            == "data/text/file_multiline.txt" );

    CHECK ( find ( "search_test_a", search_paths ) == "data/search_test_a" );

    CHECK ( find ( "search_test_b", search_paths ) == "data/search_test_b" );

    CHECK ( find ( "search_test_c",
                   search_paths ) == "data/text/search_test_c" );

    CHECK_THROWS_AS ( find ( "does_not_exist.txt", search_paths ),
                      not_found_exception );

    CHECK_THROWS_WITH ( find ( "does_not_exist.txt", search_paths ),
                        Catch::Matchers::Contains ( "does_not_exist.txt" ) );

    CHECK_THROWS_WITH ( find ( "does_not_exist.txt", search_paths ),
                        Catch::Matchers::Contains ( "data" ) );

    CHECK_THROWS_WITH ( find ( "does_not_exist.txt", search_paths ),
                        Catch::Matchers::Contains ( "data/text" ) );

    CHECK_THROWS_WITH ( find ( "does_not_exist.txt", search_paths ),
                        Catch::Matchers::Contains ( "data/image" ) );
}

TEST_CASE ( "Find all files matching path in given search paths.", TAGS ) {
    using namespace common::file;
    using namespace std;

    vector<string> search_paths = { "data", "data/text", "data/image" };

    CHECK ( find_all ( "test.png", search_paths )
            == vector<string>{ "data/image/test.png" } );

    CHECK ( find_all ( "test.jpg", search_paths )
            == vector<string>{ "data/image/test.jpg" } );

    CHECK ( find_all ( "file_a.txt", search_paths )
            == vector<string>{ "data/text/file_a.txt" } );

    CHECK ( find_all ( "file_b.txt", search_paths )
            == vector<string>{ "data/text/file_b.txt" } );

    CHECK ( find_all ( "file_c", search_paths )
            == vector<string>{ "data/text/file_c" } );

    CHECK ( find_all ( "file_multiline.txt", search_paths )
            == vector<string>{ "data/text/file_multiline.txt" } );

    CHECK ( find_all ( "search_test_a", search_paths )
            == vector<string>{ "data/search_test_a",
                               "data/text/search_test_a" } );

    CHECK ( find_all ( "search_test_b", search_paths )
            == vector<string>{ "data/search_test_b" } );

    CHECK ( find_all ( "search_test_c", search_paths )
            == vector<string>{ "data/text/search_test_c" } );

    CHECK ( find_all ( "does_not_exist.txt", search_paths )
            == vector<string>{} );
}
