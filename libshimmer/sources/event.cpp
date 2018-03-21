#include "event.h"

using namespace shimmer;

event::event( enum event::type type ) : _type ( type ) {}

event::~event() {}

enum event::type event::type() const {
    return _type;
}
