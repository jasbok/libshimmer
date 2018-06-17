#include "shim.h"

class shim shim;

shim::shim()
    : _lib(),
      events ( this ),
      input ( &_lib ),
      video ( &_lib ),
      window ( &_lib )
{}

shim::~shim()
{}

int shim::init ( Uint32 flags ) {
    _flags = flags;

    return sym::SDL_Init ( flags );
}

void shim::quit() {}
