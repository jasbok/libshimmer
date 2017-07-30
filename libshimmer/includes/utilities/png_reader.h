#ifndef LIBSHIMMER_UTILITIES_PNG_READER_H
#define LIBSHIMMER_UTILITIES_PNG_READER_H

#include "image.h"

#include <memory>
#include <string>

namespace shimmer
{
class png_reader
{
public:
    std::shared_ptr<image> read ( const std::string& path,
                                  bool               fast = false );
};
}

#endif // ifndef LIBSHIMMER_UTILITIES_PNG_READER_H
