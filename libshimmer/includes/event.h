#ifndef SHIMMER_EVENT_H
#define SHIMMER_EVENT_H

#include "dims.h"
#include "json.h"

#include <iostream>

namespace shimmer
{
/**
 * @brief The base event used for communication between systems.
 */
class event
{
public:
    enum class type;

    event( enum type );

    virtual ~event();

    /**
     * @brief Get the events type.
     * @return The event's type.
     */
    type type() const;

    /**
     * @brief Checks if the event is of the given type.
     * @param The type to check against.
     * @return True if the event is of type; false otherwise.
     */
    bool is ( const enum event::type& type ) const;

    template<typename T>
    inline operator const T&() const {
        static_assert ( std::is_base_of<event, T>::value,
                        "Cannot cast type into an event." );

        return dynamic_cast<const T&>( *this );
    }

    std::unique_ptr<event> clone() const;

    virtual std::string    to_json() const = 0;

    friend std ::ostream&  operator<<( std::ostream&           out,
                                       const enum event::type& type );

    friend std ::ostream& operator<<( std::ostream& out,
                                      const event&  event );

private:
    enum type _type;
};

std::string to_json ( const enum event::type& type );

/**
 *  @brief Stores data associated with an event.
 */
template<enum event::type TYPE, typename T>
class event_data : public event
{
public:
    typedef T DATA;

    const static enum event::type type() {
        return TYPE;
    }

    event_data( const event_data<TYPE, DATA>& ) = default;

    event_data( event_data<TYPE, DATA>&& ) = default;

    virtual ~event_data() = default;

    event_data( const DATA& data )
        : event ( TYPE ), _data ( data  )
    {}

    event_data( DATA&& data )
        : event ( TYPE ), _data ( std::move ( data ) )
    {}

    /**
     * @brief data Gets the data associated with an event.
     * @return The data associated with an event.
     */
    DATA data() const {
        return _data;
    }

    virtual std::string to_json() const {
        return "{\"type\":" + shimmer::to_json ( TYPE ) + ",\"data\":" +
               shimmer::to_json ( _data ) + "}";
    }

    friend std ::ostream& operator<<( std::ostream& out,
                                      const event_data<TYPE, T>&  event ) {
        out << event.to_json();

        return out;
    }

    bool operator==( const event_data<TYPE, T>& op ) const {
        return _data == op._data;
    }

private:
    DATA _data;
};

bool match_on_type ( const enum event::type& type,
                     const event&            event );

enum class event::type {
    display_depth_change,
    display_resolution_change,
    window_dims_change,
    window_title_change
};

typedef event_data<event::type::display_depth_change,
                   unsigned int> display_depth_change;

typedef event_data<event::type::display_resolution_change,
                   dims_2u> display_resolution_change;

typedef event_data<event::type::window_dims_change,
                   dims_2u> window_dims_change;

typedef event_data<event::type::window_title_change,
                   std::string> window_title_change;
}

#endif // ifndef SHIMMER_EVENT_H
