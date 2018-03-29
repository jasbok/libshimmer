#include "event_logger.h"

#include "plog/Log.h"

namespace shimmer
{
event_logger::event_logger( const std::string& name )
    : _name ( name )
{}

void event_logger::send ( const event& event ) {
    LOGD << _name << " => " << event;
}
}
