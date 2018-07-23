#include "shim.h"

const common::logger shim::logger =
    common::logger::get ( "shimmer::sdl::shim" );

class shim shim;

shim::shim()
    : config ( shimmer::config::create() ),
      events ( this ),
      input ( this ),
      video ( this ),
      window ( this )
{
#ifdef DEBUG
    logger.info ( "This is a debug build." );
#endif // ifdef DEBUG
}

shim::~shim()
{}

int shim::init ( Uint32 flags ) {
    _flags = flags;

    return sym::SDL_Init ( flags );
}

void shim::quit() {}

void shim::source_resolution ( const common::dims_2u& dims ) {
    input.source_resolution ( dims );
    video.source_resolution ( dims );
}

void shim::target_resolution ( const common::dims_2u& dims ) {
    input.target_resolution ( dims );
    video.target_resolution ( dims );
}
