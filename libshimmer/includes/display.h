#ifndef SHIMMER_DISPLAY_H
#define SHIMMER_DISPLAY_H

#include "system.h"

namespace shimmer
{
/**
 * @brief Stores metric data of the application's display.
 */
class display : public system
{
public:
    display();

    virtual ~display();

    /**
     * @brief Send an event to the system.
     * @param event The event to send to the system.
     */
    virtual void send ( const class event& event );

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
    dims_2u _resolution;

    unsigned int _depth;
};
}

#endif // ifndef SHIMMER_DISPLAY_H
