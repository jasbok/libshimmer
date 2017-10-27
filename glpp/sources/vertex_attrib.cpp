#include "vertex_attrib.h"

using namespace glpp;

vertex_attrib::vertex_attrib( enum type type,
                              GLuint    size )
    : _type ( type ),
      _size ( size ),
      _type_size ( 0 ),
      _location ( 0 ),
      _normalised ( false ),
      _stride ( 0 ),
      _offset ( 0 )
{
    switch ( type ) {
    case type::gl_byte:
        _type_size = sizeof(GLbyte);
        break;

    case type::gl_fixed:
        _type_size = sizeof(GLfixed);
        break;

    case type::gl_float:
        _type_size = sizeof(GLfloat);
        break;

    case type::gl_short:
        _type_size = sizeof(GLshort);
        break;

    case type::gl_unsigned_byte:
        _type_size = sizeof(GLubyte);
        break;

    case type::gl_unsigned_short:
        _type_size = sizeof(GLushort);
        break;
    }
}

vertex_attrib::vertex_attrib( enum type type,
                              GLuint    size,
                              size_t    type_size )
    : _type ( type ),
      _size ( size ),
      _type_size ( type_size ),
      _location ( 0 ),
      _normalised ( false ),
      _stride ( 0 ),
      _offset ( 0 )
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

vertex_attrib& vertex_attrib::define_pointer() {
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
