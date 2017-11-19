#define CATCH_CONFIG_RUNNER

#include "catch/catch.hpp"

#include <GL/glew.h>

// Include gl.h after glew.h
#include <GL/freeglut.h>

int main ( int argc, char* argv[] )
{
    //    glutInit ( &argc, argv );
    //    glutInitContextVersion ( 3, 3 );
    //    glutCreateWindow ( "Libshimmer: Catch Unit Test" );

    //    auto err = glewInit();

    //    if ( err != GLEW_OK ) {
    //        fprintf ( stderr, "GLEW Error: %s\n", glewGetErrorString ( err )
    // );
    //        fprintf ( stderr, "OpenGL tests will probably fail.\n" );
    //    }

    //    for ( int a = 0; a < argc; a++ ) {
    //        if ( std::string ( argv[a] ).compare ( "--enable-logging" ) == 0 )
    // {
    //            // Enable logging
    //        }
    //    }

    //    int result = Catch::Session().run ( argc, argv );

    //    return result < 0xff ? result : 0xff;
}
