#ifndef COMMON_IMG_H
#define COMMON_IMG_H

#include "dims.h"

#include "stb/stb_image.h"

#include <memory>
#include <string>
#include <vector>

namespace common::img
{
struct image {
    std::unique_ptr<uint8_t> data;
    dims_2<unsigned int>     dims;
    unsigned short           channels;
};

/**
 * @brief read Reads the image file located at the given path into an image data
 * structure.
 * @param path The path to the image to be loaded.
 * @return A data structure containing the image data.
 * @throws read_excception if the image could not be read from the given path.
 */
image read ( const std::string& path );

struct read_exception : public std::runtime_error {
    read_exception( const std::string& path );

    virtual ~read_exception();
};
}

#endif // ifndef COMMON_IMG_H
