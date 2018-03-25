#ifndef SHIMMER_EVENT_COLLECTOR_H
#define SHIMMER_EVENT_COLLECTOR_H

#include "event.h"
#include "receiver.h"

#include <memory>
#include <vector>

namespace shimmer
{
/**
 * @brief Event Logger system to log and capture events of type T.
 */
template<typename T>
class event_collector : public receiver<T>
{
public:
    typedef std::unique_ptr<T> EVENT;

    virtual ~event_collector() = default;

    /**
     * @brief Send an event to the system.
     * @param event The event to send to the system.
     */
    virtual void send ( const T& event ) {
        _events.push_back ( event.clone() );
    }

    /**
     * @brief Get list of captured events.
     * @return List of captured events.
     */
    const std::vector<EVENT>& events() const {
        return _events;
    }

private:
    std::vector<EVENT> _events;
};
}

#endif // ifndef SHIMMER_EVENT_LOGGER_H
