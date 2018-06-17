#ifndef COMMON_IMG_H
#define COMMON_IMG_H

#include "dims.h"

#include "external/stb/stb_image.h"

#include <memory>
#include <string>
#include <vector>

namespace common::img
{
class image
{
public:
    /**
     * @brief image Create a new image with the given data, dimensions and
     * channels.
     * @param data The image data.
     * @param dims The dimensions of the image.
     * @param channels The number of channels.
     */
    image( std::unique_ptr<uint8_t>&& data,
           const dims_2u&             dims,
           unsigned int               channels );

    /**
     * @brief image Initialise an empty image with the given dimensions and
     * channels.
     * @param dims The dimensions of the new image.
     * @param channels The number of channels in the new image.
     */
    image( const dims_2u& dims,
           unsigned int   channels );

    image( const image& img ) = delete;

    image( image&& img ) = default;

    virtual ~image() = default;

    image&       operator=( const image& img ) = delete;

    image&       operator=( image&& img ) = default;

    uint8_t*     data() const;

    dims_2u      dims() const;

    unsigned int channels() const;

private:
    std::unique_ptr<uint8_t> _data;

    dims_2u _dims;

    unsigned int _channels;
};

/**
 * @brief flip_vertically_on_read Sets whether to flip subsequently read images
 * around the y-axis.
 * @param flip_y Whether the loaded image should be flipped around the y-axis
 * axis.
 */
void flip_vertically_on_read ( bool flip_y );

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
