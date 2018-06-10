#include "vertex_attrib.h"

namespace glpp
{
vertex_attrib::vertex_attrib( const std::string& name,
                              GLuint             size,
                              GLuint             stride,
                              GLuint             offset,
                              GLenum             type,
                              bool               normalised,
                              GLint              location )
    : _name ( name ),
      _size ( size ),
      _stride ( stride ),
      _offset ( offset ),
      _type ( type ),
      _normalised ( normalised ),
      _location ( location )
{}

std::string vertex_attrib::name() {
    return _name;
}

GLuint vertex_attrib::size() {
    return _size;
}

GLint vertex_attrib::location() {
    return _location;
}

vertex_attrib& vertex_attrib::location ( GLint location ) {
    _location = location;

    return *this;
}

vertex_attrib& vertex_attrib::define_pointer() {
    if ( _location == -1 ) {
        std::cerr << _name << ": Attribute location not set." << std::endl;

        return *this;
    }

    glVertexAttribPointer ( _location,
                            _size,
                            _type,
                            _normalised,
                            _stride,
                            reinterpret_cast<void*>( _offset ) );

    return *this;
}

vertex_attrib& vertex_attrib::enable_array() {
    glEnableVertexAttribArray ( _location );

    return *this;
}

vertex_attrib& vertex_attrib::disable_array() {
    glDisableVertexAttribArray ( _location );

    return *this;
}
}
