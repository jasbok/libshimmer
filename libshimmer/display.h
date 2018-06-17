#ifndef SHIMMER_DISPLAY_H
#define SHIMMER_DISPLAY_H

#include "dims.h"
#include "event_receiver.h"

namespace shimmer
{
/**
 * @brief Stores metric data of the application's display.
 */
class display
{
public:
    display( event_receiver& exchange );

    virtual ~display();

    /**
     * @brief Sets the current resolution of the application's display.
     * @param resolution The new resolution.
     * @return this
     */
    display& resolution ( const dims_2u resolution );

    /**
     * @brief resolution Get the current resolution of the application's
     * display.
     * @return The current display resolution.
     */
    dims_2u resolution() const;

    /**
     * @brief Sets the current depth of the application's display.
     * @param resolution The new depth.
     * @return this
     */
    display& depth ( unsigned int depth );

    /**
     * @brief resolution Get the current depth of the application's display.
     * @return The current display depth.
     */
    unsigned int depth() const;

private:
    event_receiver* _exchange;

    dims_2u _resolution;

    unsigned int _depth;
};
}

#endif // ifndef SHIMMER_DISPLAY_H
