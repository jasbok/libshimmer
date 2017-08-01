#include "image_header.h"

using namespace shimmer;

image_header::image_header( unsigned int width,
                            unsigned int height,
                            unsigned int channels,
                            unsigned int bit_depth )
    : _width ( width ),
      _height ( height ),
      _channels ( channels ),
      _bit_depth ( bit_depth ),
      _step ( width * channels * bit_depth * 0.125 ),
      _size ( height * _step )
{}
