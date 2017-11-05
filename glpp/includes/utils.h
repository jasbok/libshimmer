#ifndef GLPP_UTILS_H
#define GLPP_UTILS_H

#include "texture_2d.h"

#include <string>

namespace glpp
{
namespace utils
{
std::string read_all ( const std::string& path );
texture_2d  texture_2d_from ( const std::string& path );
}
}

#endif // ifndef GLPP_UTILS_H
