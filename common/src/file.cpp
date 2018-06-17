#include "file.h"

#include <filesystem>
#include <fstream>

namespace common::file
{
read_exception::read_exception( const std::string& path )
    : std::runtime_error ( "Could not read file: " + path )
{}

not_found_exception::not_found_exception( const std::string& path )
    : runtime_error ( "File not found: " + path )
{}

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

std::vector<std::string> find ( const std::string&              path,
                                const std::vector<std::string>& search_paths )
{
    std::vector<std::string> results;

    for ( const auto& search_path : search_paths ) {
        std::string result = search_path + "/" + path;

        // GCC linking of stdc++fs not working at the moment.
        //        if ( std::filesystem::exists ( result ) ) {
        //            results.push_back ( result );
        //        }

        std::fstream file ( result );

        if ( file.is_open() ) {
            results.push_back ( result );
        }
    }

    return results;
}

std::vector<std::string> find_and_throw ( const std::string&              path,
                                          const std::vector<std::string>& search_paths )
{
    auto result = find ( path, search_paths );

    if ( !result.empty() ) return result;

    throw not_found_exception ( path );
}

std::string find_one ( const std::string&              path,
                       const std::vector<std::string>& search_paths )
{
    for ( const auto& search_path : search_paths ) {
        std::string result = search_path + "/" + path;

        // GCC linking of stdc++fs not working at the moment.
        //        if ( std::filesystem::exists ( result ) ) {
        //            results.push_back ( result );
        //        }

        std::fstream file ( result );

        if ( file.is_open() ) {
            return result;
        }
    }

    throw not_found_exception ( path );
}
}
