#ifndef LIBSHIMMER_RENDERER_COMMON_TEXTURE_H
#define LIBSHIMMER_RENDERER_COMMON_TEXTURE_H

#include "accessor_macros.h"

namespace shimmer
{
class texture
{
public:
    texture (
        unsigned int width,
        unsigned int height);

    virtual ~texture() {}

private:
    GETTER ( texture, unsigned int, width );

    GETTER ( texture, unsigned int, height );
};
}

#endif
