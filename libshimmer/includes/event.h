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
        DISPLAY_DEPTH_CHANGE,
        DISPLAY_RESOLUTION_CHANGE,
        CONFIG_CHANGE,
        KEY_PRESSED,
        MOUSE_COORDS_CHANGE,
        WINDOW_DIMS_CHANGE,
        WINDOW_TITLE_CHANGE
    };

    event( enum type );

    virtual ~event();

    /**
     * @brief Get the events type.
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
    const static enum event::type type = TYPE;

    event_data( const event_data<TYPE, T>& ) = default;

    event_data( event_data<TYPE, T>&& ) = default;

    virtual ~event_data() = default;

    event_data( const T& data )
        : event ( TYPE ), _data ( data  )
    {}

    event_data( T&& data )
        : event ( TYPE ), _data ( std::move ( data ) )
    {}

    /**
     * @brief data Gets the data associated with an event.
     * @return The data associated with an event.
     */
    T data() const {
        return _data;
    }

private:
    T _data;
};

typedef event_data<event::type::DISPLAY_DEPTH_CHANGE,
                   unsigned int> display_depth_change;

typedef event_data<event::type::DISPLAY_RESOLUTION_CHANGE,
                   dims_2u> display_resolution_change;

typedef event_data<event::type::WINDOW_DIMS_CHANGE,
                   dims_2u> window_dims_change;

typedef event_data<event::type::WINDOW_TITLE_CHANGE,
                   std::string> window_title_change;
}

#endif // ifndef SHIMMER_EVENT_H
