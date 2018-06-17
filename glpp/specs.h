#ifndef GLPP_SPECS_H
#define GLPP_SPECS_H

#include "common/coords.h"
#include "common/dims.h"

#include <GL/glew.h>

#include <string>

namespace glpp
{
typedef common::coords_2<GLint> coords_2i;

typedef common::coords_2<GLuint> coords_2u;

typedef common::coords_2<GLfloat> coords_2f;

typedef common::dims_2<GLuint> dims_2u;

typedef common::dims_2<GLfloat> dims_2f;

typedef common::dims_2<GLsizei> dims_2s;

typedef common::dims_3<GLuint> dims_3u;

typedef common::dims_3<GLfloat> dims_3f;

typedef common::dims_3<GLsizei> dims_3s;

template<typename C, typename D>
struct viewport {
    C coords;
    D dims;

    viewport() = default;

    viewport( const C& coords, const D& dims )
        : coords ( coords ), dims ( dims ) {}

    viewport( viewport&& move ) = default;

    viewport( const viewport& copy ) = default;

    virtual ~viewport() = default;

    viewport& operator=( viewport&& move ) = default;

    viewport& operator=( const viewport& copy ) = default;
};

typedef viewport<coords_2i, dims_2s> viewport_int;

template<typename T>
struct range {
    T start, end;

    range() = delete;

    range( T start, T end )
        : start ( start ), end ( end ) {}

    range( range&& move ) = default;

    range( const range& copy ) = default;

    virtual ~range() = default;

    range& operator=( range&& move ) = default;

    range& operator=( const range& copy ) = default;


    bool operator==( const range& comp ) const {
        return start == comp.start && end == comp.end;
    }

    bool operator!=( const range& comp ) const {
        return start != comp.start || end != comp.end;
    }

    std::string to_json() const {
        return "{start:" + std::to_string ( start )
               + ",end:" + std::to_string ( end ) + "}";
    }
};

typedef range<unsigned int> range_uint;

namespace unicodes
{
static range_uint control_character { 0x00000, 0x00020 };
static range_uint basic_latin { 0x00020, 0x00080 };
static range_uint latin_1_supplement { 0x00080, 0x00100 };
static range_uint latin_extended_a { 0x00100, 0x00180 };
static range_uint latin_extended_b { 0x00180, 0x00250 };
static range_uint greek_and_coptic { 0x00370, 0x00400 };
}
}

#endif // ifndef GLPP_SPECS_H
