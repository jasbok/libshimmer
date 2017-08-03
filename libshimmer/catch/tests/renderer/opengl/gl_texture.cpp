#include "check_image.h"
#include "check_opengl.h"
#include "gl_texture.h"
#include "png_reader.h"

#include "catch/catch.hpp"

using namespace shimmer;
using namespace std;

#include <cstring>

TEST_CASE ( "Read an image from disk and copy the data to an OpenGL texture "
            "(RGB).",
            "[gl_texture]" )
{
    CHECK_GL_NO_ERROR();
    auto image_in = png_reader::read ( "data/images/8x9x8_rgb_b.png" );

    gl_texture tex ( image_in->width(), image_in->height() );
    CHECK_GL_NO_ERROR();

    tex.upload ( GL_RGB, GL_UNSIGNED_BYTE, image_in->data().get() );
    CHECK_GL_NO_ERROR();

    auto image_out = std::make_shared<image>(
        image_in->width(),
        image_in->height(),
        image_in->channels(),
        image_in->bit_depth(),
        nullptr );

    tex.download ( GL_RGB, GL_UNSIGNED_BYTE, image_out->data().get() );
    CHECK_GL_NO_ERROR();

    CHECK_EQUAL ( *image_in, *image_out );
}

TEST_CASE ( "Read an image from disk and copy the data to an OpenGL texture "
            "(RGBA).",
            "[gl_texture]" )
{
    CHECK_GL_NO_ERROR();
    auto image_in = png_reader::read ( "data/images/8x9x8_rgba_b.png" );

    gl_texture tex ( image_in->width(), image_in->height() );
    CHECK_GL_NO_ERROR();

    tex.upload ( GL_RGBA, GL_UNSIGNED_BYTE, image_in->data().get() );
    CHECK_GL_NO_ERROR();

    auto image_out = std::make_shared<image>(
        image_in->width(),
        image_in->height(),
        image_in->channels(),
        image_in->bit_depth(),
        nullptr );

    tex.download ( GL_RGBA, GL_UNSIGNED_BYTE, image_out->data().get() );
    CHECK_GL_NO_ERROR();

    CHECK_EQUAL ( *image_in, *image_out );
}

TEST_CASE ( "Read an image from disk into a pixel buffer and copy the data to "
            "an OpenGL texture (RGB).",
            "[gl_texture]" )
{
    CHECK_GL_NO_ERROR();
    std::string image_path = "data/images/8x9x8_rgb_b.png";
    png_reader  reader ( image_path );
    auto header = reader.header();

    auto pixel_buffer = std::make_shared<gl_pixel_buffer>(
        GL_PIXEL_UNPACK_BUFFER,
        header->size(),
        GL_STATIC_DRAW,
        GL_WRITE_ONLY,
        GL_RGB,
        GL_UNSIGNED_BYTE );
    CHECK_GL_NO_ERROR();

    reader.read_data ( ( uint8_t* )pixel_buffer->map() );
    CHECK_GL_NO_ERROR();

    auto image_in = png_reader::read ( image_path );
    CHECK_EQUAL ( image_in->data().get(),
                  pixel_buffer->data(),
                  image_in->size() );

    pixel_buffer->unmap();
    CHECK_GL_NO_ERROR();

    gl_texture tex ( header->width(),
        header->height(),
        GL_RGB,
        GL_UNSIGNED_BYTE );
    CHECK_GL_NO_ERROR();

    auto image_out = std::make_shared<image>( *header, nullptr );

    tex.download ( GL_RGB, GL_UNSIGNED_BYTE, image_out->data().get() );
    CHECK_GL_NO_ERROR();

    CHECK_EQUAL ( *image_in, *image_out );
}

TEST_CASE ( "Read an image from disk into a pixel buffer and copy the data to "
            "an OpenGL texture (RGBA).",
            "[gl_texture]" )
{
    CHECK_GL_NO_ERROR();

    std::string image_path = "data/images/8x9x8_rgba_b.png";
    png_reader  reader ( image_path );
    auto header = reader.header();

    auto pixel_buffer = std::make_shared<gl_pixel_buffer>(
        GL_PIXEL_UNPACK_BUFFER,
        header->size(),
        GL_STATIC_DRAW,
        GL_WRITE_ONLY,
        GL_RGBA,
        GL_UNSIGNED_BYTE );
    CHECK_GL_NO_ERROR();

    reader.read_data ( ( uint8_t* )pixel_buffer->map() );
    CHECK_GL_NO_ERROR();

    auto image_in = png_reader::read ( image_path );

    CHECK_EQUAL ( image_in->data().get(),
                  pixel_buffer->data(),
                  image_in->size() );

    pixel_buffer->unmap();
    CHECK_GL_NO_ERROR();

    gl_texture tex ( header->width(),
        header->height(),
        GL_RGBA,
        GL_UNSIGNED_BYTE );
    CHECK_GL_NO_ERROR();

    auto image_out = std::make_shared<image>( *header, nullptr );

    tex.download ( GL_RGBA, GL_UNSIGNED_BYTE, image_out->data().get() );
    CHECK_GL_NO_ERROR();

    CHECK_EQUAL ( *image_in, *image_out );
}
