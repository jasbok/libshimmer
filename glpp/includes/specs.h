#ifndef GLPP_SPECS_H
#define GLPP_SPECS_H

#include <GL/glew.h>

#include <string>

namespace glpp
{
template<typename T>
struct coords_2d {
    T x, y;


    coords_2d() = default;

    coords_2d( T x, T y )
        : x ( x ), y ( y ) {}

    coords_2d( coords_2d&& move ) = default;

    coords_2d( const coords_2d& copy ) = default;

    virtual ~coords_2d() = default;

    coords_2d& operator=( coords_2d&& move ) = default;

    coords_2d& operator=( const coords_2d& copy ) = default;


    bool operator==( const coords_2d& comp ) {
        return x == comp.x && y == comp.y;
    }

    bool operator!=( const coords_2d& comp ) {
        return x != comp.x || y != comp.y;
    }

    std::string to_json() const {
        return "{x:" + std::to_string ( x )
               + ",y:" + std::to_string ( y ) + "}";
    }
};

template<typename T>
struct coords_3d {
    T x, y, z;


    coords_3d() = default;

    coords_3d( T x, T y, T z )
        : x ( x ), y ( y ), z ( z ) {}

    coords_3d( coords_3d&& move ) = default;

    coords_3d( const coords_3d& copy ) = default;

    virtual ~coords_3d() = default;

    coords_3d& operator=( coords_3d&& move ) = default;

    coords_3d& operator=( const coords_3d& copy ) = default;


    bool operator==( const coords_3d& comp ) {
        return x == comp.x && y == comp.y && z == comp.z;
    }

    bool operator!=( const coords_3d& comp ) {
        return x != comp.x || y != comp.y || z != comp.z;
    }

    std::string to_json() const {
        return "{x:" + std::to_string ( x )
               + ",y:" + std::to_string ( y )
               + ",z:" + std::to_string ( z ) + "}";
    }
};

template<typename T>
struct dims_2d {
    T width, height;


    dims_2d() = default;

    dims_2d( T x, T y )
        : width ( x ), height ( y ) {}

    dims_2d( dims_2d&& move ) = default;

    dims_2d( const dims_2d& copy ) = default;

    virtual ~dims_2d() = default;

    dims_2d& operator=( dims_2d&& move ) = default;

    dims_2d& operator=( const dims_2d& copy ) = default;


    bool operator==( const dims_2d& comp ) {
        return width == comp.width && height == comp.height;
    }

    bool operator!=( const dims_2d& comp ) {
        return width != comp.width || height != comp.height;
    }

    std::string to_json() const {
        return "{width:" + std::to_string ( width )
               + ",height:" + std::to_string ( height ) + "}";
    }
};

template<typename T>
struct dims_3d {
    T width, height, depth;


    dims_3d() = default;

    dims_3d( T x, T y, T z )
        : width ( x ), height ( y ), depth ( z ) {}

    dims_3d( dims_3d&& move ) = default;

    dims_3d( const dims_3d& copy ) = default;

    virtual ~dims_3d() = default;

    dims_3d& operator=( dims_3d&& move ) = default;

    dims_3d& operator=( const dims_3d& copy ) = default;


    bool operator==( const dims_3d& comp ) {
        return width == comp.width
               && height == comp.height
               && depth == comp.depth;
    }

    bool operator!=( const dims_3d& comp ) {
        return width != comp.width
               || height != comp.height
               || depth != comp.depth;
    }

    std::string to_json() const {
        return "{width:" + std::to_string ( width )
               + ",height:" + std::to_string ( height )
               + ",depth:" + std::to_string ( depth ) + "}";
    }
};

typedef coords_2d<GLint> coords_2i;
typedef dims_2d<GLuint>  dims_2u;
}

#endif // ifndef GLPP_SPECS_H
