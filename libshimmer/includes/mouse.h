#ifndef SHIMMER_MOUSE_H
#define SHIMMER_MOUSE_H

#include "event_connector.h"
#include "event_receiver.h"

namespace shimmer
{
/**
 * @brief Mouse system to transform mouse coordinates.
 */
class mouse : public event_receiver
{
public:
    mouse();

    mouse( event_connector& connector );

    virtual ~mouse();

    /**
     * @brief send Send an event to the mouse system.
     * @param event The event.
     */
    virtual void send ( const class event& event );

    /**
     * @brief transform Transforms the input coordinates inplace.
     * @param coords Coords to transform.
     */
    coords_2i transform ( const coords_2i& coords );

    /**
     * @brief display Sets the display resolution.
     * @param Dimensions of the application.
     * @return this
     */
    mouse& display ( const dims_2u& display );

    /**
     * @brief window Sets the window dimensions.
     * @param Dimensions of the window.
     * @return this
     */
    mouse& window ( const dims_2u& window );

private:
    event_connector* _connector;

    coords_2f _coords;

    dims_2f _display;

    dims_2f _window;

    coords_2f _transform;

    /**
     * @brief _update_transform Updates the transform using the
     * current application and window dimensions.
     */
    void _update_transform();

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
};
}

#endif // ifndef SHIMMER_MOUSE_H
