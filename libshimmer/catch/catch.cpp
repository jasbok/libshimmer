#define CATCH_CONFIG_RUNNER

#include "catch/catch.hpp"
#include "spdlog/spdlog.h"

#include <GL/glew.h>
#include <GL/glut.h>

int main ( int argc, char* argv[] )
{
    glutInit ( &argc, argv );
    glutCreateWindow ( "libshimmer catch window" );

    auto err = glewInit();
    if ( GLEW_OK != err ) {
        fprintf ( stderr, "GLEW Error: %s\n", glewGetErrorString ( err ) );
        fprintf ( stderr, "OpenGL tests will probably fail.\n");
    }

    spdlog::set_level ( spdlog::level::warn );

    int result = Catch::Session().run ( argc, argv );
    return ( result < 0xff ? result : 0xff );
}
