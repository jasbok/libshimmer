#include "check_image.h"
#include "check_opengl.h"
#include "gl_texture.h"
#include "png_reader.h"

#include "catch/catch.hpp"

using namespace shimmer;
using namespace std;

#include <cstring>

TEST_CASE ( "Read an image from disk and copy the data to an OpenGL texture.",
            "[gl_texture]" )
{
    CHECK_GL_NO_ERROR();
    auto image_in = png_reader::read ( "data/images/8x9x8_rgb.png" );

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
