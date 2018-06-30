#ifndef COMMON_BUFFER_H
#define COMMON_BUFFER_H

#include <stddef.h>

namespace common
{
template<typename T>
struct buffer {
    T*     data;
    size_t size;
};
}

#endif // ifndef COMMON_BUFFER_H
