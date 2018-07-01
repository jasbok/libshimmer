#include "shim.h"

class shim shim;

shim::shim()
    : config ( shimmer::config::create() ),
      events ( this ),
      input ( this ),
      video ( this ),
      window ( this )
{}

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
