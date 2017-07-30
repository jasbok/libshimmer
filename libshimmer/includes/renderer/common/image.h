#ifndef LIBSHIMMER_RENDERER_COMMON_IMAGE_H
#define LIBSHIMMER_RENDERER_COMMON_IMAGE_H

#include "accessor_macros.h"

#include <memory>
#include <vector>

#include <cstdint>

namespace shimmer
{
class image
{
public:
    image( unsigned int                    width,
           unsigned int                    height,
           unsigned int                    channels,
           unsigned int                    bit_depth,
           const std::shared_ptr<uint8_t>& data );

    virtual ~image() {}

private:
    GETTER ( unsigned int,             width );
    GETTER ( unsigned int,             height );
    GETTER ( unsigned int,             channels );
    GETTER ( unsigned int,             bit_depth );
    GETTER ( unsigned int,             step );
    GETTER ( unsigned int,             size );
    GETTER ( std::shared_ptr<uint8_t>, data );
    GETTER ( std::vector<uint8_t*>,    rows );
};
}

#endif // ifndef LIBSHIMMER_RENDERER_COMMON_IMAGE_H
