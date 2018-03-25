#ifndef SHIMMER_EVENT_LOGGER_H
#define SHIMMER_EVENT_LOGGER_H

#include "receiver.h"

#include <iostream>

namespace shimmer
{
/**
 * @brief Logs all events received to the configured logger.
 */
template<typename T>
class event_logger : public receiver<T>
{
public:
    virtual ~event_logger() = default;

    /**
     * @brief Send an event to this component.
     * @param event The event to send to the component.
     * @return True if the event was received, false otherwise.
     */
    virtual void send ( const T& event ) {
        std::cout << event << std::endl;
    }
};
}

#endif // ifndef SHIMMER_EVENT_LOGGER_H
