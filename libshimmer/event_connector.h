#ifndef SHIMMER_EVENT_CONNECTOR_H
#define SHIMMER_EVENT_CONNECTOR_H

#include "connector.h"
#include "event.h"

namespace shimmer {
typedef connector<enum event::type, event> event_connector;
}

#endif
