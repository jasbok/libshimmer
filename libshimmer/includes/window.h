#ifndef SHIMMER_WINDOW_H
#define SHIMMER_WINDOW_H

#include "system.h"

namespace shimmer
{
/**
 * @brief Window system that stores the state of the window.
 */
class window : public system
{
public:
    window();

    virtual ~window();

    /**
     * @brief Send an event to the system.
     * @param event The event to send to the system.
     */
    virtual void send ( const class event& base_event );

    /**
     * @brief dimensions Sets the dimensions of the window.
     * @param dimensions The new dimensions of the window.
     * @return this
     */
    window& dimensions ( const dims_2u& dimensions );

    /**
     * @brief dimensions Gets the current dimensions of the window.
     * @return The dimensions of the window.
     */
    dims_2u dimensions() const;

    /**
     * @brief title Sets the title of the window.
     * @param title The new title of the window.
     * @return this
     */
    window& title ( const std::string& title );

    /**
     * @brief title Gets the current title of the window.
     * @return The title of the window.
     */
    std::string title() const;

private:
    dims_2u _dimensions;

    std::string _title;
};
}

#endif // ifndef SHIMMER_WINDOW_H
