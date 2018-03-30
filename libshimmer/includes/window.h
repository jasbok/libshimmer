#ifndef SHIMMER_WINDOW_H
#define SHIMMER_WINDOW_H

#include "event_receiver.h"

namespace shimmer
{
/**
 * @brief Window system that stores the state of the window.
 */
class window
{
public:
    window( event_receiver& exchange );

    virtual ~window();

    /**
     * @brief coordinates Sets the coordinates of the window.
     * @param coordinates The new coordinates of the window.
     * @return this
     */
    window& coordinates ( const coords_2i& coordinates );

    /**
     * @brief coordinates Gets the current coordinates of the window.
     * @return The coordinates of the window.
     */
    coords_2i coordinates() const;

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
    event_receiver* _exchange;

    coords_2i _coordinates;

    dims_2u _dimensions;

    std::string _title;
};
}

#endif // ifndef SHIMMER_WINDOW_H
