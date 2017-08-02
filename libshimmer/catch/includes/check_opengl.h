#ifndef LIBSHIMMER_CATCH_CHECK_OPENGL_H
#define LIBSHIMMER_CATCH_CHECK_OPENGL_H

#include "catch/catch.hpp"

#include <GL/glew.h>

#include <string>

#define CHECK_GL_NO_ERROR() check_gl_no_error ( __FILE__, __LINE__ )

static void check_gl_no_error ( const std::string& file, int line ) {
    auto err = glGetError();

    if ( err != GL_NO_ERROR ) {
        if ( err == GL_INVALID_ENUM ) {
            FAIL ( "GL Error: GL_INVALID_ENUM (" << file << ":" << line <<
                   ")" );
        }
        else if ( err == GL_INVALID_VALUE ) {
            FAIL (
                "GL Error: GL_INVALID_VALUE (" << file << ":" << line <<
                    ")" );
        }
        else if ( err == GL_INVALID_OPERATION ) {
            FAIL (
                "GL Error: GL_INVALID_OPERATION (" << file << ":" << line <<
                    ")" );
        }
        else if ( err == GL_INVALID_FRAMEBUFFER_OPERATION ) {
            FAIL (
                "GL Error: GL_INVALID_FRAMEBUFFER_OPERATION (" << file << ":" << line <<
                    ")" );
        }
        else if ( err == GL_OUT_OF_MEMORY ) {
            FAIL (
                "GL Error: GL_OUT_OF_MEMORY (" << file << ":" << line <<
                    ")" );
        }
        else if ( err == GL_INVALID_OPERATION ) {
            FAIL (
                "GL Error: GL_INVALID_OPERATION (" << file << ":" << line <<
                    ")" );
        }
    }
}

#endif // ifndef LIBSHIMMER_CATCH_CHECK_OPENGL_H
