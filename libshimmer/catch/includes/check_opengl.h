#ifndef LIBSHIMMER_CATCH_CHECK_OPENGL_H
#define LIBSHIMMER_CATCH_CHECK_OPENGL_H

#include "catch/catch.hpp"

#include <GL/glew.h>

#include <string>

#define CHECK_GL_NO_ERROR() check_gl_no_error ( __FILE__, __LINE__ )

static void check_gl_no_error ( const std::string& file, int line ) {
    auto err  = glGetError();
    bool fail = false;

    while ( err != GL_NO_ERROR ) {
        fail = true;

        switch ( err ) {
        case GL_INVALID_ENUM:
            WARN ( "GL Error: GL_INVALID_ENUM." );
            break;

        case GL_INVALID_VALUE:
            WARN ( "GL Error: GL_INVALID_VALUE." );
            break;

        case GL_INVALID_OPERATION:
            WARN ( "GL Error: GL_INVALID_OPERATION." );
            break;

        case GL_INVALID_FRAMEBUFFER_OPERATION:
            WARN ( "GL Error: GL_INVALID_FRAMEBUFFER_OPERATION." );
            break;

        case GL_OUT_OF_MEMORY:
            WARN ( "GL Error: GL_OUT_OF_MEMORY." );
            break;

        case GL_STACK_UNDERFLOW:
            WARN ( "GL Error: GL_STACK_UNDERFLOW." );
            break;

        case GL_STACK_OVERFLOW:
            WARN ( "GL Error: GL_STACK_OVERFLOW." );
            break;

        default:
            WARN ( "GL Error: Unknown error." );
            break;
        }

        err = glGetError();
    }

    if ( fail ) {
        FAIL ( "There were OpenGL erorrs:\n" << file << ":" << line );
    }
}

#endif // ifndef LIBSHIMMER_CATCH_CHECK_OPENGL_H
