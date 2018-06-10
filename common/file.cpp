#include "file.h"

namespace common::file
{
read_exception::read_exception( const std::string& path )
    : std::runtime_error ( "Could not read file: " + path )
{}

read_exception::~read_exception() {}

std::string read_all ( const std::string& path )
{
    std::ifstream fstream ( path );

    if ( fstream.is_open() ) {
        return std::string ( std::istreambuf_iterator<char>( fstream ), {} );
    }

    throw read_exception ( path );
}

std::vector<std::string> read_lines ( const std::string& path ) {
    std::ifstream fstream ( path );

    if ( fstream.is_open() ) {
        std::vector<std::string> lines;
        std::string line;

        while ( std::getline ( fstream, line ) ) lines.push_back ( line );

        return lines;
    }

    throw read_exception ( path );
}
}
