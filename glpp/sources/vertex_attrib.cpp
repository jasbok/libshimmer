#include "vertex_attrib.h"

#include <iostream>

using namespace glpp;

vertex_attrib::vertex_attrib( enum gl_type type,
                              GLuint    size )
    : _type ( type ),
      _size ( size ),
      _type_size ( glpp::size_of(type) ),
      _location ( 0 ),
      _normalised ( false ),
      _stride ( 0 ),
      _offset ( 0 ),
      _name ("no_name")
{}

vertex_attrib::vertex_attrib( enum gl_type type,
                              GLuint    size,
                              size_t    type_size )
    : _type ( type ),
      _size ( size ),
      _type_size ( type_size ),
      _location ( 0 ),
      _normalised ( false ),
      _stride ( 0 ),
      _offset ( 0 ),
      _name ("no_name")
{}


vertex_attrib& vertex_attrib::location ( GLint location ) {
    _location = location;

    return *this;
}

vertex_attrib& vertex_attrib::normalised ( bool normalised ) {
    _normalised = normalised;

    return *this;
}

vertex_attrib& vertex_attrib::stride ( GLuint stride )       {
    _stride = stride * _type_size;

    return *this;
}

vertex_attrib& vertex_attrib::offset ( GLuint offset ) {
    _offset = offset * _type_size;

    return *this;
}

vertex_attrib& vertex_attrib::name ( const std::string& name ){
    _name = name;

    return *this;
}


vertex_attrib& vertex_attrib::define_pointer() {
    if(_location == -1){
        std::cerr << _name << ": Attribute location not set." << std::endl;
        return *this;
    }

    glVertexAttribPointer ( _location,
                            _size,
                            static_cast<GLenum>(_type),
                            _normalised,
                            _stride,
                            reinterpret_cast<void*>(_offset) );

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
