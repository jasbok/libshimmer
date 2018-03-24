#ifndef SHIMMER_EVENT_LOGGER_H
#define SHIMMER_EVENT_LOGGER_H

#include "system.h"

#include <memory>

namespace shimmer
{
/**
 * @brief Event Logger system to log and capture events of type T.
 */

template<typename T>
class event_logger : public system
{
public:
    event_logger()
        : system ( "event_logger" ),
          _logging_enabled ( false ),
          _capturing_enabled ( true )
    {}

    event_logger( const std::string& name )
        : system ( name ),
          _logging_enabled ( false ),
          _capturing_enabled ( true )
    {}

    virtual ~event_logger() {}

    /**
     * @brief Send an event to the system.
     * @param event The event to send to the system.
     */
    virtual void send ( const class event& event ) {
        if ( event.type() == T::type ) {
            if ( _capturing_enabled ) _events.push_back ( event );
        }
    }

    /**
     * @brief Enable logging of events.
     * @param enable True to enable logs, false otherwise.
     * @return this
     */
    event_logger& logging ( bool enable ) {
        _logging_enabled = enable;

        return *this;
    }

    /**
     * @brief Check whether logging is enabled.
     * @return True if logs are enabled, false otherwise.
     */
    bool logging() const {
        return _logging_enabled;
    }

    /**
     * @brief Enable capturing of events.
     * @param enable True to enable captures, false otherwise.
     * @return this
     */
    event_logger& capturing ( bool enable ) {
        _capturing_enabled = enable;

        return *this;
    }

    /**
     * @brief Check whether capturing is enabled.
     * @return True if captures are enabled, false otherwise.
     */
    bool capturing() const {
        return _capturing_enabled;
    }

    /**
     * @brief Get list of captured events.
     * @return List of captured events.
     */
    const std::vector<T>& events() const {
        return _events;
    }

private:
    bool _logging_enabled;

    bool _capturing_enabled;

    std::vector<T> _events;

    enum event::type _type;
};
}

#endif // ifndef SHIMMER_EVENT_LOGGER_H
