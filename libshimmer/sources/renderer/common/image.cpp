#include "image.h"

using namespace shimmer;
using namespace std;

image::image( unsigned int               width,
              unsigned int               height,
              unsigned int               channels,
              unsigned int               bit_depth,
              const shared_ptr<uint8_t>& data )
    : image_header (
          width,
          height,
          channels,
          bit_depth ),

      _data ( data != nullptr ? data
          : shared_ptr<uint8_t>( new uint8_t[size()],
                                 std::default_delete<uint8_t[]>() ) ),

      _rows ( height, nullptr )
{
    for ( unsigned int row = 0; row < height; row++ ) {
        _rows[row] = _data.get() + row * step();
    }
}

image::image( const image_header& header, const shared_ptr<uint8_t>& data )
    : image_header ( header ),
      _data ( data != nullptr ? data
          : shared_ptr<uint8_t>( new uint8_t[size()],
                                 std::default_delete<uint8_t[]>() ) ),

      _rows ( height(), nullptr )
{
    for ( unsigned int row = 0; row < height(); row++ ) {
        _rows[row] = _data.get() + row * step();
    }
}
