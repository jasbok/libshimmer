#include "file_reader.h"

using namespace shimmer;
using namespace std;

file_reader::file_reader( const std::vector<string>& search_paths )
    : _search_paths ( search_paths )
{
    if ( _search_paths.empty() ) throw search_path_exception (
                  "No search paths provided." );
}

file file_reader::read ( const string& path, ios_base::openmode mode ) const
{
    for ( const auto& search_path : _search_paths ) {
        string   file_path = search_path + "/" + path;
        ifstream fstream ( search_path + "/" + path );

        if ( fstream.is_open() ) {
            return { file_path, std::move ( fstream ) };
        }
    }

    throw file_read_exception ( "Could not find file in search paths: " +
                                path );
}

string file_reader::read_str ( const string& path ) const
{
    auto file = read ( path );

    try {
        return string ( istreambuf_iterator<char>( file.stream ), {} );
    }
    catch ( exception ex ) {
        throw file_read_exception ( "Could not read file (" + file.path + "):"
                                    + string ( ex.what() ) );
    }
}

std::vector<string> file_reader::search_paths() const
{
    return _search_paths;
}
