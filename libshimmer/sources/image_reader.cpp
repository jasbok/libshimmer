#include "image_reader.h"

#include "common/img.h"

#include <iostream>

using namespace shimmer;
using namespace std;


image_reader::image_reader( const vector<string>& search_paths )
    : file_reader ( search_paths )
{}

common::img::image image_reader::image ( const string& path ) const
{
    for ( const auto& search_path : search_paths() ) {
        try {
            std::string file_path = search_path + "/" + path;

            return common::img::read ( file_path );
        }
        catch ( exception ex ) {}
    }

    throw file_read_exception ( "Could not find file in search path: " + path );
}

glpp::texture_2d image_reader::texture_2d (
    const string&                          path,
    enum glpp::texture_2d::internal_format internal_format ) const
{
    class glpp::texture_2d texture;

    texture.bind();
    texture.image ( internal_format, image ( path ) );
    texture.generate_mipmaps();

    return texture;
}
