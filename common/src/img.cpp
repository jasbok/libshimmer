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
        return image ( std::unique_ptr<uint8_t>( data ),
                       dims_2<unsigned int>( static_cast<unsigned int>( width ),
                                             static_cast<unsigned int>( height )
                                             ),
                       static_cast<unsigned short>( channels ) );
    }

    throw read_exception ( path );
}

void flip_vertically_on_read ( bool flip_y )
{
    stbi_set_flip_vertically_on_load ( flip_y );
}

image::image( std::unique_ptr<uint8_t>&& data,
              const dims_2u&             dims,
              unsigned int               channels )
    : _data ( std::move ( data ) ),
      _dims ( dims ),
      _channels ( channels )
{}

image::image( const dims_2u& dims, unsigned int channels )
    : _data ( new uint8_t[dims.area() * channels] ),
      _dims ( dims ),
      _channels ( channels )
{}

uint8_t* image::data() const {
    return _data.get();
}

dims_2u image::dims() const {
    return _dims;
}

unsigned int image::channels() const {
    return _channels;
}
}

//
//  Include source for stb_image.
//
#define STB_IMAGE_IMPLEMENTATION
#include "external/stb/stb_image.h"
