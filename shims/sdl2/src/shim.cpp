#include "shim.h"

#include "common/logger.h"

const auto& logger = common::logger::get ( "shimmer::sdl2::shim" );

class shim shim;

shim::shim()
    : config ( shimmer::config::create() ),
      events ( this ),
      input ( this ),
      video ( this ),
      window ( this )
{
#ifdef DEBUG
    logger.warn ( "This is a debug build." );
#endif // ifdef DEBUG
}

void shim::init ( Uint32 flags ) {
    logger.info ( "Initialising SDL2 shim..." );
    _flags = flags;
}

void shim::quit() {}

void shim::source_resolution ( const common::dims_2u& dims ) {
    events.source_resolution ( dims );
    input.source_resolution ( dims );
    video.source_resolution ( dims );
    window.source_resolution ( dims );
}

void shim::target_resolution ( const common::dims_2u& dims ) {
    events.target_resolution ( dims );
    input.target_resolution ( dims );
    video.target_resolution ( dims );
    window.target_resolution ( dims );
}
