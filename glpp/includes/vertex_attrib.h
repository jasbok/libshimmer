#ifndef GLPP_VERTEX_ATTRIB_H
#define GLPP_VERTEX_ATTRIB_H

#include "enums.h"

#include <GL/glew.h>

#include <string>
#include <vector>

namespace glpp
{
struct attrib {
    std::string name;
    GLuint      size;
    GLint       location = -1;
};

template<typename T, size_t T_SIZE = sizeof( T ),
         GLenum T_ENUM = to_glenum<T>( )>
class vertex_attrib
{
public:
    vertex_attrib( const std::string& name,
                   GLuint             size,
                   GLuint             stride,
                   GLuint             offset,
                   bool               normalised,
                   GLint              location = -1 )
        : _name ( name ),
          _size ( size ),
          _stride ( stride * T_SIZE ),
          _offset ( offset * T_SIZE ),
          _normalised ( normalised ),
          _location ( location )
    {}

    vertex_attrib( vertex_attrib&& move ) = default;

    vertex_attrib( const vertex_attrib& copy ) = default;

    virtual ~vertex_attrib() = default;

    vertex_attrib& operator=( vertex_attrib&& move ) = default;

    vertex_attrib& operator=( const vertex_attrib& copy ) = default;


    std::string name() {
        return _name;
    }

    GLint size() {
        return _size;
    }

    GLint location() {
        return _location;
    }

    vertex_attrib& location ( GLint location ) {
        _location = location;

        return *this;
    }

    vertex_attrib& define_pointer() {
        if ( _location == -1 ) {
            std::cerr << _name << ": Attribute location not set." << std::endl;

            return *this;
        }

        glVertexAttribPointer ( _location,
                                _size,
                                T_ENUM,
                                _normalised,
                                _stride,
                                reinterpret_cast<void*>( _offset ) );

        return *this;
    }

    vertex_attrib& enable_array() {
        glEnableVertexAttribArray ( _location );

        return *this;
    }

    vertex_attrib& disable_array() {
        glDisableVertexAttribArray ( _location );

        return *this;
    }

private:
    std::string _name;

    GLuint _size;

    GLuint _stride;

    GLuint _offset;

    bool _normalised;

    GLint _location;
};

template<typename T>
class vertex_attrib_builder
{
public:
    explicit vertex_attrib_builder( const attrib& attrib )
        : _name ( attrib.name ),
          _size ( attrib.size ),
          _location ( attrib.location ),
          _normalised ( false )
    {}

    vertex_attrib_builder& stride ( GLuint stride )       {
        _stride = stride;

        return *this;
    }

    vertex_attrib_builder& offset ( GLuint offset ) {
        _offset = offset;

        return *this;
    }

    vertex_attrib_builder& normalised ( bool normalised ) {
        _normalised = normalised;

        return *this;
    }

    vertex_attrib<T> build() {
        return vertex_attrib<T>( _name,
                                 _size,
                                 _stride,
                                 _offset,
                                 _normalised,
                                 _location );
    }

    static std::vector<vertex_attrib<T>> sequential (
        const std::vector<attrib>& attribs,
        bool                       normalised = false ) {
        std::vector<vertex_attrib<T>> vertex_attibs;

        unsigned int stride = _get_stride ( attribs );
        unsigned int offset = 0;

        for ( const auto& attrib : attribs ) {
            vertex_attibs.push_back ( vertex_attrib_builder ( attrib )
                                          .stride ( stride )
                                          .offset ( offset )
                                          .normalised ( normalised )
                                          .build() );

            offset += attrib.size;
        }

        return vertex_attibs;
    }

private:
    std::string _name;

    GLuint _size;

    GLint _location;

    GLuint _stride;

    GLuint _offset;

    bool _normalised;

    static unsigned int _get_stride (
        const std::vector<attrib>& attribs ) {
        unsigned int stride = 0;

        for ( const auto& a : attribs ) {
            stride += a.size;
        }

        return stride;
    }
};
}

#endif // ifndef GLPP_VERTEX_ATTRIB_H
