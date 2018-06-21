#include "shim.h"

class shim shim;

shim::shim()
    : events ( this ),
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
