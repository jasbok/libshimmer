#ifndef SHIMMER_IMAGE_READER_H
#define SHIMMER_IMAGE_READER_H

#include "file_reader.h"

#include "common/img.h"
#include "glpp/texture_2d.h"

namespace shimmer
{
class image_reader : file_reader
{
public:
    image_reader( const std::vector<std::string>& search_paths );

    virtual ~image_reader() = default;

    common::img::image     image ( const std::string& path ) const;

    class glpp::texture_2d texture_2d (
            const std::string&                     path,
            enum glpp::texture_2d::internal_format internal_format =
                glpp::texture_2d::internal_format::rgb ) const;
};
}

#endif // ifndef SHIMMER_IMAGE_READER_H
