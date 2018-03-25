#include "event.h"

namespace shimmer
{
event::event( enum event::type type ) : _type ( type ) {}

event::~event() {}

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
        MAKE_UNIQUE ( display_depth_change );
        MAKE_UNIQUE ( display_resolution_change );
        MAKE_UNIQUE ( window_dims_change );
        MAKE_UNIQUE ( window_title_change );
    }
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

std::string to_json ( const enum event::type& type )
{
    using namespace std;

    switch ( type ) {
    case event::type::display_depth_change: return string (
            "\"display_depth_change\"" );

    case event::type::display_resolution_change: return string (
            "\"display_resolution_change\"" );

    case event::type::window_dims_change: return string (
            "\"window_dims_change\"" );

    case event::type::window_title_change: return string (
            "\"window_title_change\"" );
    }
}

bool match_on_type ( const enum event::type& type,
                     const event&            event ) {
    return type == event.type();
}
}
