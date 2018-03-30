#ifndef SHIMMER_ASPECT_RATIO_H
#define SHIMMER_ASPECT_RATIO_H

#include <string>

namespace shimmer
{
enum class aspect_ratio {
    original,
    stretch,
    zoom
};

std::string to_json ( const aspect_ratio ratio );
}
#endif // ifndef SHIMMER_ASPECT_RATIO_H
