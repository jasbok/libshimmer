#ifndef SHIMMER_EVENT_LOGGER_H
#define SHIMMER_EVENT_LOGGER_H

#include "event_receiver.h"

namespace shimmer
{
/**
 * @brief Logs all events received.
 */
class event_logger : public event_receiver
{
public:
    event_logger( const std::string& name = "event_logger" );

    virtual ~event_logger() = default;

    /**
     * @brief Send an event to this component.
     * @param event The event to send to the component.
     * @return True if the event was received, false otherwise.
     */
    virtual void send ( const event& event );

private:
    const std::string _name;
};
}

#endif // ifndef SHIMMER_EVENT_LOGGER_H
