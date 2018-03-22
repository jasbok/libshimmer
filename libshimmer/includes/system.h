#ifndef SHIMMER_SYSTEM_H
#define SHIMMER_SYSTEM_H

#include "event.h"

#include <algorithm>
#include <exception>
#include <memory>
#include <vector>

namespace shimmer
{
class system
{
public:
    /**
     * @brief Constructs a system with the given id.
     * @param id The id of this system.
     */
    system( const std::string& id );

    virtual ~system();

    /**
     * @brief Get the id of this system.
     * @return The id of this system.
     */
    std::string id() const;

    /**
     * @brief Send an event to the system.
     * @param event The event to send to the system.
     */
    virtual void send ( const class event& event ) = 0;

    /**
     * @brief Checks if the system has a child component matching the given id.
     * @param id The id of the child component to find.
     * @return True if the child component was found; false otherwise.
     */
    bool has_component ( const std::string& id );

    /**
     * @brief Finds the child component with the specified id. Throws an
     * exception if the component was not found.
     * @param id The id of the child component to find.
     * @return A reference to the child component; exception is thrown
     * otherwise.
     */
    system* find_component ( const std::string& id );

    /**
     * @brief Adds a child component to the system.
     * @param component The child component to add to the system.
     * @return this
     */
    system& add_component ( system* component );


    friend bool operator==( const shimmer::system* const system,
                            const std::string&           id );

protected:
    const system& broadcast ( const class event& event ) const;

    const system& send_parent ( const class event& event ) const;

    const system& send_components ( const class event& event ) const;

private:
    std::string _id;

    system* _parent;

    std::vector<system*> _components;
};
}

#endif // ifndef SHIMMER_SYSTEM_H
