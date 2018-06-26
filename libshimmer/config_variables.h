#ifndef SHIMMER_CONFIG_VARIABLES_H
#define SHIMMER_CONFIG_VARIABLES_H

#include "common/str.h"

#include <regex>

namespace shimmer::system
{
const std::string install_prefix;

const std::vector<std::string> config_dirs;

const std::vector<std::string> data_dirs;

const std::vector<std::string> font_dirs;

const std::vector<std::string> image_dirs;

const std::vector<std::string> shader_dirs;
}

#define SHIMMER_INSTALL_PREFIX "/usr/local"

#define SHIMMER_INSTALL_DATA "/usr/local/share"

#define SHIMMER_INSTALL_FONTS "/usr/local/share/fonts"

#define SHIMMER_INSTALL_IMAGES "/usr/local/share/images"

#define SHIMMER_INSTALL_SHADERS "/usr/local/share/shaders"

#endif /* ifndef SHIMMER_CONFIG_VARIABLES_H */
