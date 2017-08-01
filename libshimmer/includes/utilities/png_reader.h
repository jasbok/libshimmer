#ifndef LIBSHIMMER_UTILITIES_PNG_READER_H
#define LIBSHIMMER_UTILITIES_PNG_READER_H

#include "accessor_macros.h"
#include "image.h"

#include <png.h>

#include <cstdint>
#include <memory>
#include <string>

namespace shimmer
{
class png_reader
{
public:
    explicit png_reader( const std::string& path );

    virtual ~png_reader();

    bool                          read_data ( image* img );

    bool                          read_data ( uint8_t* data );

    static std::shared_ptr<image> read ( const std::string& path );

private:
    void                          _open();

    void                          _setup_data_structures();

    void                          _set_jmp_and_io();

    void                          _read_header();

    GETTER ( std::string,                   path );

    GETTER ( bool,                          is_valid );

    GETTER ( std::shared_ptr<image_header>, header );

    FILE* _file;

    png_structp _png_ptr;

    png_infop _info_ptr;

    bool _eof;
};
}

#endif // ifndef LIBSHIMMER_UTILITIES_PNG_READER_H