#ifndef LIBSHIMMER_RENDERER_COMMON_MEMORY_BLOCK_H
#define LIBSHIMMER_RENDERER_COMMON_MEMORY_BLOCK_H

#include <cstddef>

namespace shimmer
{
class memory_block
{
public:
    virtual ~memory_block() {}

    virtual void*       data() = 0;

    virtual std::size_t size() = 0;
};
}

#endif // ifndef LIBSHIMMER_RENDERER_COMMON_MEMORY_BLOCK_H
