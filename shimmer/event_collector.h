#ifndef SHIMMER_EVENT_COLLECTOR_H
#define SHIMMER_EVENT_COLLECTOR_H

#include "event.h"
#include "receiver.h"

#include <memory>
#include <vector>

namespace shimmer
{
/**
 * @brief Stores a list of events.
 */
class event_collector : public receiver<event>
{
public:
    virtual ~event_collector() = default;

    /**
     * @brief Send an event to the system.
     * @param event The event to send to the system.
     */
    virtual void send ( const event& event );

    /**
     * @brief Get list of captured events.
     * @return List of captured events.
     */
    const std::vector<std::unique_ptr<event>>& events() const;

private:
    std::vector<std::unique_ptr<event>> _events;
};
}

#endif // ifndef SHIMMER_EVENT_COLLECTOR_H
