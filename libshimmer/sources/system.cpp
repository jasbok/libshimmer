#include "system.h"

#include "logger.h"

namespace shimmer
{
system::system( const std::string& id )
    : _id ( id ),
      _parent ( nullptr ),
      _components()
{}

system::~system() {}

std::string system::id() const {
    return _id;
}

bool system::has_component ( const std::string& id ) {
    return std::find ( _components.begin(),
                       _components.end(),
                       id ) != _components.end();
}

system* system::find_component ( const std::string& id ) {
    auto component =
        std::find ( _components.begin(), _components.end(), id );

    if ( component == _components.end() ) throw std::exception();

    return *component;
}

system& system::add_component ( system* component ) {
    if ( component ) {
        component->_parent = this;
        _components.push_back ( component );
    }
    else {
        LOGW << "Tried to add a null component to '" << _id << "'";
    }

    return *this;
}

bool operator==( const system* const system, const std::string& id ) {
    return system->id().compare ( id ) == 0;
}

const system& system::broadcast ( const event& event ) const {
    send_parent ( event );
    send_components ( event );

    return *this;
}

const system& system::send_parent ( const event& event ) const {
    if ( _parent ) _parent->send ( event );

    return *this;
}

const system& system::send_components ( const event& event ) const {
    for ( auto& component : _components ) component->send ( event );

    return *this;
}
}
