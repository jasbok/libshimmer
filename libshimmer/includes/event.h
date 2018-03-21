#ifndef SHIMMER_EVENT_H
#define SHIMMER_EVENT_H

#include "common.h"

namespace shimmer
{
/**
 * @brief The base event used for communication between systems.
 */
class event
{
public:
    enum type {
        APPLICATION_DIMS_CHANGE,
        CONFIG_CHANGE,
        KEY_PRESSED,
        MOUSE_COORDS_CHANGE,
        WINDOW_DIMS_CHANGE,
    };

    event( enum type );

    virtual ~event();

    /**
     * @brief type
     * @return The event's type.
     */
    type type() const;

    template<typename T>
    inline operator const T&() const {
        static_assert ( std::is_base_of<event, T>::value,
                        "Cannot cast type into an event." );

        return dynamic_cast<const T&>( *this );
    }

private:
    enum type _type;
};

/**
 *  @brief Stores data associated with an event.
 */
template<enum event::type TYPE, typename T>
class event_data : public event
{
public:
    event_data( const T& data )
        : event ( TYPE ), _data ( data  )
    {}

    event_data( T&& data )
        : event ( TYPE ), _data ( std::move ( data ) )
    {}

    /**
     * @brief data
     * @return The data associated with an event.
     */
    T data() const {
        return _data;
    }

private:
    T _data;
};

typedef event_data<event::type::APPLICATION_DIMS_CHANGE,
                   dims_2u> application_dims_change;

typedef event_data<event::type::WINDOW_DIMS_CHANGE,
                   dims_2u> window_dims_change;
}

#endif // ifndef SHIMMER_EVENT_H
