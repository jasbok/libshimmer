#include "png_reader.h"

#include "spdlog/spdlog.h"

#include <png.h>

using namespace shimmer;
using namespace std;

#define HEADER_SIZE 8

static std::shared_ptr<spdlog::logger> LOGGER
    = spdlog::stdout_color_mt ( "png_reader" );

std::shared_ptr<image> png_reader::read ( const std::string& path,
                                          bool               fast ) {
    std::shared_ptr<image> png = nullptr;

    FILE* fp = fopen ( path.c_str(), "rb" );
    unsigned char header[HEADER_SIZE];

    if ( !fp )
    {
        LOGGER->error ( "Unable to open png file: {}", path );

        return nullptr;
    }

    fread ( header, 1, HEADER_SIZE, fp );
    auto is_png = !png_sig_cmp ( header, 0, HEADER_SIZE );

    if ( !is_png )
    {
        LOGGER->error ( "File is not a valid png: {}", path );

        return nullptr;
    }

    auto png_ptr = png_create_read_struct ( PNG_LIBPNG_VER_STRING,
                                            nullptr,
                                            nullptr,
                                            nullptr );

    if ( !png_ptr ) {
        LOGGER->error ( "Unable to create png struct: {}", path );

        return nullptr;
    }

    auto info_ptr = png_create_info_struct ( png_ptr );

    if ( !info_ptr )
    {
        LOGGER->error ( "Unable to create info struct: {}", path );

        png_destroy_read_struct ( &png_ptr,
                                  nullptr,
                                  nullptr );

        return nullptr;
    }

    if ( setjmp ( png_jmpbuf ( png_ptr ) ) )
    {
        LOGGER->error ( "An error occurred while loading png: {}", path );
        png_destroy_read_struct ( &png_ptr, &info_ptr, nullptr );
        fclose ( fp );

        return nullptr;
    }

    png_set_sig_bytes ( png_ptr, HEADER_SIZE );
    png_init_io ( png_ptr, fp );

    if ( fast ) {
        png_read_info ( png_ptr, info_ptr );

        png = std::make_shared<image>(
            png_get_image_width ( png_ptr, info_ptr ),
            png_get_image_height ( png_ptr, info_ptr ),
            png_get_channels ( png_ptr, info_ptr ),
            png_get_bit_depth ( png_ptr, info_ptr ),
            nullptr );

        png_read_image ( png_ptr, png->rows().data() );
        //png_read_end ( png_ptr, nullptr );
    }
    else {
        png_read_png ( png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL );
        auto src_rows = png_get_rows ( png_ptr, info_ptr );

        png = std::make_shared<image>(
            png_get_image_width ( png_ptr, info_ptr ),
            png_get_image_height ( png_ptr, info_ptr ),
            png_get_channels ( png_ptr, info_ptr ),
            png_get_bit_depth ( png_ptr, info_ptr ),
            nullptr );

        const auto dest_rows = png->rows();

        for ( unsigned int row = 0; row < png->height(); row++ ) {
            std::memcpy ( dest_rows[row], src_rows[row], png->step() );
        }
    }

    png_destroy_read_struct ( &png_ptr, &info_ptr, nullptr );
    fclose ( fp );

    return png;
}
