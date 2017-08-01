#ifndef LIBSHIMMER_RENDERER_COMMON_IMAGE_HEADER_H
#define LIBSHIMMER_RENDERER_COMMON_IMAGE_HEADER_H

#include "accessor_macros.h"

namespace shimmer
{
class image_header
{
public:
    image_header( unsigned int width,
                  unsigned int height,
                  unsigned int channels,
                  unsigned int bit_depth );

    virtual ~image_header() {}

private:
    GETTER ( unsigned int, width );
    GETTER ( unsigned int, height );
    GETTER ( unsigned int, channels );
    GETTER ( unsigned int, bit_depth );
    GETTER ( unsigned int, step );
    GETTER ( unsigned int, size );
};
}

#endif // ifndef LIBSHIMMER_RENDERER_COMMON_IMAGE_HEADER_H
