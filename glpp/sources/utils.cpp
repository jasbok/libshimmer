#include "utils.h"

#include "pixels.h"

#include "stb/stb_image.h"

#include <fstream>
#include <iostream>
#include <iterator>

using namespace glpp;
using namespace std;

string utils::read_all ( const string& path ) {
    ifstream fstream ( path );

    return string ( std::istreambuf_iterator<char>( fstream ), {} );
}

texture_2d utils::texture_2d_from ( const std::string& path ) {
    int width, height, channels;
    uint8_t* data = stbi_load ( path.c_str(), &width, &height, &channels, 0 );

    if ( !data ) {
        std::cerr << "Could not load image..." << std::endl;

        return glpp::texture_2d ( glpp::texture_2d::internal_format::rgb );
    }

    auto format = channels == 3
                  ? glpp::pixels::format::rgb
                  : glpp::pixels::format::rgba;

    glpp::texture_2d texture ( glpp::texture_2d::internal_format::rgb );

    texture.bind();

    texture.image ( glpp::pixels ( std::unique_ptr<uint8_t>( data ),
                                   { static_cast<GLuint>(width),
                                     static_cast<GLuint>(height) },
                                   format,
                                   glpp::pixels::type::gl_unsigned_byte ) );
    texture.generate_mipmaps();

    return texture;
}
