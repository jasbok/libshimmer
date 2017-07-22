#include "catch.hpp"
#include "file_reader.h"

using namespace std;
using namespace shimmer;

TEST_CASE ( "Load complete file contents into a string." )
{
    string file_path = "data/file_reader/simple.txt";

    string expected_contents =
        "Simple.txt File\n"
        "\n"
        "A test file used to test the file_reader class.\n"
        "The file is copied from the source to the binary\n"
        "directory using the CMake configure_file command.\n"
        "\n"
        "End of file, followed by an empty line:\n";

    auto actual_contents = file_reader::read ( file_path );
    CHECK ( expected_contents ==  actual_contents );
}

TEST_CASE ( "Load file contents line for line into a vector." )
{
   string file_path = "data/file_reader/simple.txt";

    vector<string> expected_contents = {
        "Simple.txt File",
        "",
        "A test file used to test the file_reader class.",
        "The file is copied from the source to the binary",
        "directory using the CMake configure_file command.",
        "",
        "End of file, followed by an empty line:"
    };

    auto actual_contents = file_reader::read_lines ( file_path );

    REQUIRE ( expected_contents.size() ==  actual_contents.size() );

    for ( unsigned int i = 0; i < actual_contents.size(); i++ ) {
        CHECK ( expected_contents[i] ==  actual_contents[i] );
    }
}
