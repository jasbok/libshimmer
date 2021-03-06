/*
 *  This file is generated from config_variables.h.in, do not modify directly.
 */
#ifndef SHIMMER_CONFIG_VARIABLES_H
#define SHIMMER_CONFIG_VARIABLES_H

#include "common/str.h"

#include <regex>

namespace shimmer::system {
    const std::string install_prefix = "/usr/local";

    const std::string install_shimmer = install_prefix + "/shimmer";

    const std::string install_shaders = install_shimmer + "/shaders";

    const std::vector < std::string > config_dirs
        = common::str::split ( install_shimmer + ":$HOME/.config:/usr/share/shimmer",
                               std::regex ( ":" ) );

    const std::vector < std::string > data_dirs
        = common::str::split ( install_shimmer + ":$HOME/.local/share:/usr/share/shimmer",
                               std::regex ( ":" ) );

    const std::vector < std::string > font_dirs
        = common::str::split ( install_shimmer + ":/usr/share/shimmer/fonts",
                               std::regex ( ":" ) );

    const std::vector < std::string > image_dirs
        = common::str::split ( install_shimmer + ":/usr/share/shimmer/images",
                               std::regex ( ":" ) );

    const std::vector < std::string > shader_dirs
        = common::str::split ( install_shimmer + ":" + install_shaders
                               + ":/usr/share/shimmer/shaders",
                               std::regex ( ":" ) );
}

#define SHIMMER_INSTALL_PREFIX ""

#define SHIMMER_INSTALL_DATA ""

#define SHIMMER_INSTALL_FONTS ""

#define SHIMMER_INSTALL_IMAGES ""

#define SHIMMER_INSTALL_SHADERS ""

#endif /* ifndef SHIMMER_CONFIG_VARIABLES_H */
