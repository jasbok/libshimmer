#include "img.h"

namespace common::img
{
read_exception::read_exception( const std::string& path )
    : std::runtime_error ( "Could not read image: " + path )
{}

read_exception::~read_exception() {}

image read ( const std::string& path )
{
    int width, height, channels;

    uint8_t* data = stbi_load ( path.c_str(),
                                &width,
                                &height,
                                &channels,
                                0 );

    if ( data ) {
        return image { std::unique_ptr<uint8_t>( data ),
                       dims_2<unsigned int>( static_cast<unsigned int>( width ),
                                             static_cast<unsigned int>( height )
                                             ),
                       static_cast<unsigned short>( channels ) };
    }

    throw read_exception ( path );
}
}

//
//  Include source for stb_image.
//
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
