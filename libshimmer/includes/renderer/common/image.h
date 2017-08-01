#ifndef LIBSHIMMER_RENDERER_COMMON_IMAGE_H
#define LIBSHIMMER_RENDERER_COMMON_IMAGE_H

#include "accessor_macros.h"
#include "image_header.h"

#include <memory>
#include <vector>

#include <cstdint>

namespace shimmer
{
class image : public image_header
{
public:
    image( unsigned int                    width,
           unsigned int                    height,
           unsigned int                    channels,
           unsigned int                    bit_depth,
           const std::shared_ptr<uint8_t>& data );

    image( const image_header&             header,
           const std::shared_ptr<uint8_t>& data );

    virtual ~image() {}

private:
    GETTER ( std::shared_ptr<uint8_t>, data );
    GETTER ( std::vector<uint8_t*>,    rows );
};
}

#endif // ifndef LIBSHIMMER_RENDERER_COMMON_IMAGE_H
