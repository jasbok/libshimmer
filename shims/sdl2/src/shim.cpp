#include "shim.h"

class shim shim;

shim::shim()
    : config ( shimmer::config::create() ),
      events ( this ),
      input ( this ),
      video ( this ),
      window ( this )
{}

void shim::init ( Uint32 flags ) {
    printf ( "[DEBUG] Initialising SDL2 shim...\n" );
    _flags = flags;
}

void shim::quit() {}

void shim::source_resolution ( const common::dims_2u& dims ) {
    events.source_resolution ( dims );
    video.source_resolution ( dims );
}

void shim::target_resolution ( const common::dims_2u& dims ) {
    events.target_resolution ( dims );
    video.target_resolution ( dims );
}
