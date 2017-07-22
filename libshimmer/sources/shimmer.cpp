#include "shimmer.h"

#include <iostream>

namespace shimmer
{
shimmer::shimmer()
{
    std::cout << "Shimmer: initialising...\n";
    std::cout << "Shimmer: initialised.\n";
}

shimmer::~shimmer()
{
    std::cout << "Shimmer: cleaning resources...\n";
    std::cout << "Shimmer: cleaned resources.\n";
}
}
