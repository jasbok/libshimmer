#include "image.h"

using namespace shimmer;
using namespace std;

image::image( unsigned int               width,
              unsigned int               height,
              unsigned int               channels,
              unsigned int               bit_depth,
              const shared_ptr<uint8_t>& data )
    : _width ( width ),
      _height ( height ),
      _channels ( channels ),
      _bit_depth ( bit_depth ),
      _step ( width * channels * bit_depth * 0.125 ),
      _size ( height * _step ),

      _data ( data != nullptr ? data
          : shared_ptr<uint8_t>( new uint8_t[_size],
                                 std::default_delete<uint8_t[]>() ) ),

      _rows ( height, nullptr )
{
    for ( unsigned int row = 0; row < height; row++ ) {
        _rows[row] = _data.get() + row * _step;
    }
}
