#include "file_reader.h"
#include "spdlog.h"
#include <fstream>
#include <iostream>

using namespace std;
using namespace shimmer;

static std::shared_ptr<spdlog::logger> LOGGER
    = spdlog::stdout_color_mt( "file_reader" );

string file_reader::read ( const string& path )
{
    string content;
    ifstream ifs ( path );

    if ( ifs.is_open() ) {
        content = string ( ( std::istreambuf_iterator<char> ( ifs ) ),
                           std::istreambuf_iterator<char>() );
        ifs.close();
    } else {
        LOGGER->error ( "Unable to open file: {}",  path );
    }

    return content;
}

vector<string> file_reader::read_lines ( const string& path )
{
    vector<string> content;
    ifstream ifs ( path );
    string line;

    if ( ifs.is_open() ) {
        while ( getline ( ifs, line ) ) {
            content.push_back ( line );
        }
        ifs.close();
    } else {
        LOGGER->error ( "Unable to open file: {}",  path );
    }

    return content;
}

