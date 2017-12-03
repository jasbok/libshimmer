#include "image_reader.h"

#include "stb/stb_image.h"

#include <iostream>

using namespace shimmer;
using namespace std;


image_reader::image_reader( const vector<string>& search_paths )
    : file_reader ( search_paths )
{}

glpp::pixels image_reader::image ( const string& path ) const
{
    int width, height, channels;

    for ( const auto& search_path : search_paths() ) {
        std::string file_path = search_path + "/" + path;
        uint8_t*    data      = stbi_load ( file_path.c_str(),
                                            &width,
                                            &height,
                                            &channels,
                                            0 );

        if ( data ) {
            try {
                auto format = channels == 3
                              ? glpp::pixels::format::rgb
                              : glpp::pixels::format::rgba;

                return glpp::pixels ( std::unique_ptr<uint8_t>( data ),
                                      { static_cast<GLuint>( width ),
                                        static_cast<GLuint>( height ) },
                                      format,
                                      glpp::pixels::type::gl_unsigned_byte );
            }
            catch ( exception ex ) {
                throw file_read_exception ( "Could not read image file ("
                                            + file_path + ": " + ex.what() );
            }
        }
    }

    throw file_read_exception ( "Could not find file in search path: " + path );
}

glpp::texture_2d image_reader::texture_2d (
    const string&                       path,
    enum glpp::texture::internal_format internal_format ) const
{
    class glpp::texture_2d texture ( internal_format );

    texture.bind();
    texture.image ( image ( path ) );
    texture.generate_mipmaps();

    return texture;
}
