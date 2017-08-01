#include "png_reader.h"

#include "spdlog/spdlog.h"

#include <tuple>

using namespace shimmer;
using namespace std;

#define HEADER_SIZE 8

static shared_ptr<spdlog::logger> LOGGER
    = spdlog::stdout_color_mt ( "png_reader" );

png_reader::png_reader( const string& path )
    : _path ( path ),
      _is_valid ( false ),
      _eof ( false )
{
    _open();
    _setup_data_structures();
    _set_jmp_and_io();
    _read_header();
}

png_reader::~png_reader() {
    if ( _file ) {
        fclose ( _file );
    }

    png_destroy_read_struct ( &_png_ptr, &_info_ptr, nullptr );
}

void png_reader::_open() {
    _file = fopen ( _path.c_str(), "rb" );

    if ( _file )
    {
        unsigned char header[HEADER_SIZE];
        fread ( header, 1, HEADER_SIZE, _file );
        _is_valid = !png_sig_cmp ( header, 0, HEADER_SIZE );

        if ( !_is_valid )
        {
            LOGGER->error ( "File is not a valid png: {}", _path );
        }
    }
    else {
        LOGGER->error ( "Unable to open png file: {}", _path );
    }
}

void png_reader::_setup_data_structures() {
    _png_ptr = png_create_read_struct (
        PNG_LIBPNG_VER_STRING,
        nullptr,
        nullptr,
        nullptr );

    if ( _png_ptr ) {
        _info_ptr = png_create_info_struct ( _png_ptr );

        if ( !_info_ptr ) {
            LOGGER->error ( "Unable to create info struct." );
        }
    }
    else {
        LOGGER->error ( "Unable to create png struct." );
    }
}

void png_reader::_set_jmp_and_io() {
    if ( setjmp ( png_jmpbuf ( _png_ptr ) ) )
    {
        LOGGER->error ( "An error occurred while loading png: {}", _path );
        _is_valid = false;
    }
    else {
        png_init_io ( _png_ptr, _file );
        png_set_sig_bytes ( _png_ptr, HEADER_SIZE );
    }
}

void png_reader::_read_header() {
    if ( _is_valid ) {
        png_read_info ( _png_ptr, _info_ptr );

        _header = make_shared<image_header>(
            png_get_image_width ( _png_ptr, _info_ptr ),
            png_get_image_height ( _png_ptr, _info_ptr ),
            png_get_channels ( _png_ptr, _info_ptr ),
            png_get_bit_depth ( _png_ptr, _info_ptr ) );
    }
}

bool png_reader::read_data ( image* img ) {
    bool success = false;

    if ( _is_valid ) {
        if ( !_eof ) {
            png_read_image ( _png_ptr, img->rows().data() );
            _eof    = true;
            success = true;
        }
        else {
            LOGGER->error ( "The PNG data has already been read: {}", _path );
        }
    }
    else {
        LOGGER->error ( "The PNG is invalid and cannot be read: {}", _path );
    }

    return success;
}

bool png_reader::read_data ( uint8_t* data ) {
    bool success = false;

    if ( _is_valid ) {
        if ( !_eof ) {
            vector<uint8_t*> rows;

            for ( unsigned int r = 0; r < _header->height(); r++ ) {
                rows.push_back ( data + r * _header->step() );
            }

            png_read_image ( _png_ptr, rows.data() );
            _eof    = true;
            success = true;
        }
        else {
            LOGGER->error ( "The PNG data has already been read: {}", _path );
        }
    }
    else {
        LOGGER->error ( "The PNG is invalid and cannot be read: {}", _path );
    }

    return success;
}

shared_ptr<image> png_reader::read ( const string& path )
{
    shared_ptr<image> img = nullptr;
    png_reader reader ( path );

    if ( reader.is_valid() ) {
        auto header = reader.header();
        img = make_shared<image>( *header, nullptr );
        reader.read_data ( img.get() );
    }

    return img;
}
