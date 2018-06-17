#ifndef SHIMMER_EVENT_EXCHANGE_H
#define SHIMMER_EVENT_EXCHANGE_H

#include "event.h"
#include "exchange.h"

namespace shimmer
{
typedef exchange<enum event::type, event, match_on_type> event_exchange;
}

#endif // ifndef SHIMMER_EVENT_EXCHANGE_H
