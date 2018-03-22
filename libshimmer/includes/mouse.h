#ifndef SHIMMER_MOUSE_H
#define SHIMMER_MOUSE_H

#include "common.h"
#include "system.h"

namespace shimmer
{
/**
 * @brief Mouse system to transform mouse coordinates.
 */
class mouse : public system
{
public:
    mouse();

    virtual ~mouse();

    /**
     * @brief Send an event to the mouse system.
     * @param event The event.
     */
    virtual void send ( const class event& event );

    /**
     * @brief Transforms the input coordinates inplace.
     * @param coords Coords to transform.
     */
    coords_2i transform ( const coords_2i& coords );

    /**
     * @brief Sets the application dimensions.
     * @param Dimensions of the application.
     * @return this
     */
    mouse& application ( const dims_2u& application );

    /**
     * @brief Sets the window dimensions.
     * @param Dimensions of the window.
     * @return this
     */
    mouse& window ( const dims_2u& window );

private:
    coords_2f _coords;

    dims_2f _application;

    dims_2f _window;

    coords_2f _transform;

    /**
     * @brief Updates the transform using the
     * current application and window dimensions.
     */
    void _update_transform();

    /**
     * @brief Receives an application event.
     * @param event The event to receive.
     */
    void _application_event ( const application_dims_change& event );

    /**
     * @brief Receives a window event.
     * @param event The event to receive.
     */
    void _window_event ( const window_dims_change& event );
};
}

#endif // ifndef SHIMMER_MOUSE_H
