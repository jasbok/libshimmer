#define CATCH_CONFIG_RUNNER

#include "catch/catch.hpp"

#include "plog/Appenders/ConsoleAppender.h"
#include "plog/Log.h"

int main ( int argc, char* argv[] )
{
    static plog::ConsoleAppender<plog::TxtFormatter> consoleAppender;

    plog::init ( plog::debug, &consoleAppender );

    int result = Catch::Session().run ( argc, argv );

    return result < 0xff ? result : 0xff;
}
