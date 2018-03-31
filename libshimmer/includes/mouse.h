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
     * @brief transform Transforms the input coordinates.
     * @param coords Coords to transform.
     */
    coords_2i transform ( const coords_2i& coords );

    /**
     * @brief transform Transforms the input coordinates inplace.
     * @param x The x coordinate to transform.
     * @param y The y coordinate to transform.
     */
    template<typename T>
    void transform ( T& x,
                     T& y ) {
        x *= _transform.x;
        y *= _transform.y;
    }

    /**
     * @brief transform Transforms the relative input coordinates.
     * @param coords Relative coords to transform.
     */
    coords_2i transform_relative ( const coords_2i& coords );

    /**
     * @brief transform Transforms the input relative coordinates inplace.
     * @param x The relative x coordinate to transform.
     * @param y The relative y coordinate to transform.
     */
    template<typename T>
    void transform_relative ( T& x,
                              T& y ) {
        coords_2f trans = coords_2f ( x, y ) * _transform_relative;

        x = static_cast<T>( ceilf ( trans.x ) );
        y = static_cast<T>( ceilf ( trans.y ) );
    }

    /**
     * @brief display Sets the aspect ratio of the current display.
     * @param Aspect ratio of the current display.
     * @return this
     */
    mouse& aspect ( const dims_2f& aspect );

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

    coords_2f _relative;

    dims_2f _aspect;

    dims_2f _display;

    dims_2f _window;

    coords_2f _transform;

    coords_2f _transform_relative;

    /**
     * @brief _update_transform Updates the transform using the
     * current application and window dimensions.
     */
    void _update_transform();

    /**
     * @brief _aspect_ratio_event Receives an aspect ratio event.
     * @param event The event to receive.
     */
    void _aspect_ratio_event ( const aspect_ratio_change& event );

    /**
     * @brief _display_event Receives a display event.
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
