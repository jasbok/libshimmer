#include "event_collector.h"

namespace shimmer
{
void event_collector::send ( const event& event ) {
    _events.push_back ( event.clone() );
}

const std::vector<std::unique_ptr<event>>& event_collector::events() const {
    return _events;
}
}
