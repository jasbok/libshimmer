#ifndef SHIMMER_ASPECT_H
#define SHIMMER_ASPECT_H

#include "event_connector.h"
#include "event_receiver.h"

namespace shimmer
{
/**
 * @brief Manages the aspect ratio transform of the output surface.
 */
class aspect : public event_receiver
{
public:
    aspect( event_connector& connector );

    virtual ~aspect();

    /**
     * @brief Send an event to this component.
     * @param event The event to send to the component.
     * @return True if the event was received, false otherwise.
     */
    virtual void send ( const event& event );

    /**
     * @brief transform Gets the current aspect transform.
     * @return The current aspect transform.
     */
    dims_2f transform() const;

private:
    event_connector* _connector;

    dims_2f _display;

    dims_2f _window;

    aspect_ratio _aspect_ratio;

    dims_2f _transform;

    /**
     * @brief _aspect_event Receives a window event.
     * @param event The event to receive.
     */
    void _aspect_event ( const aspect_ratio_config& event );

    /**
     * @brief _display_event Receives an display event.
     * @param event The event to receive.
     */
    void _display_event ( const display_resolution_change& event );

    /**
     * @brief _window_event Receives a window event.
     * @param event The event to receive.
     */
    void _window_event ( const window_dims_change& event );

    /**
     * @brief _calculate_transform Calculates the current transform.
     */
    void _calculate_transform();
};
}

#endif // ifndef SHIMMER_ASPECT_H
