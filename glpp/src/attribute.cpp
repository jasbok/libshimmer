#include "attribute.h"

using namespace glpp;
using namespace std;

attribute::attribute( GLint              location,
                      const std::string& name )
    : _location ( location ),
      _name ( name )
{}

attribute::attribute( attribute&& move )
    : _location ( move._location ),
      _name ( std::move ( move._name ) )
{
    move._location = -1;
}

attribute::~attribute() {}

attribute& attribute::operator=( attribute&& move ) {
    _location = move._location;
    _name     = std::move ( move._name );

    move._location = -1;

    return *this;
}

GLint attribute::location() const {
    return _location;
}

string attribute::name() const {
    return _name;
}
