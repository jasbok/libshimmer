#include "event.h"

#include <exception>

namespace shimmer
{
event::event( enum event::type type ) : _type ( type ) {}

enum event::type event::type() const {
    return _type;
}

bool event::is ( const enum event::type& type ) const {
    return _type == type;
}

#define MAKE_UNIQUE( T ) \
case event::type::T:     \
    return std::make_unique<T>( static_cast<const T&>( *this ) )

std::unique_ptr<event> event::clone() const {
    switch ( _type ) {
        MAKE_UNIQUE ( aspect_ratio_change );
        MAKE_UNIQUE ( aspect_ratio_config );
        MAKE_UNIQUE ( display_depth_change );
        MAKE_UNIQUE ( display_resolution_change );
        MAKE_UNIQUE ( window_coords_change );
        MAKE_UNIQUE ( window_dims_change );
        MAKE_UNIQUE ( window_title_change );
    }

    throw std::runtime_error ( "The clone() function has not been implemented for "
                               + shimmer::to_json (
                                   _type ) );
}

std::ostream& operator<<( std::ostream&           out,
                          const enum event::type& type ) {
    out << to_json ( type );

    return out;
}

std::ostream& operator<<( std::ostream& out, const event& event ) {
    out << event.to_json();

    return out;
}

#define TO_JSON( T ) \
case event::type::T: return std::string ( "\""# T "\"" )

std::string to_json ( const enum event::type& type )
{
    switch ( type ) {
        TO_JSON ( aspect_ratio_change );
        TO_JSON ( aspect_ratio_config );
        TO_JSON ( display_depth_change );
        TO_JSON ( display_resolution_change );
        TO_JSON ( window_coords_change );
        TO_JSON ( window_dims_change );
        TO_JSON ( window_title_change );
    }

    throw std::runtime_error (
              "The to_json() function has not been implemented for event::type." );
}

bool match_on_type ( const enum event::type& type,
                     const event&            event ) {
    return type == event.type();
}
}
