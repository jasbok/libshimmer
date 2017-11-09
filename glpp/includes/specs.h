#ifndef GLPP_SPECS_H
#define GLPP_SPECS_H

#include <GL/glew.h>

#include <string>

namespace glpp
{
template<typename T>
struct coords_2 {
    T x, y;


    coords_2() = default;

    coords_2( T x, T y )
        : x ( x ), y ( y ) {}

    coords_2( coords_2&& move ) = default;

    coords_2( const coords_2& copy ) = default;

    virtual ~coords_2() = default;

    coords_2& operator=( coords_2&& move ) = default;

    coords_2& operator=( const coords_2& copy ) = default;


    bool operator==( const coords_2& comp ) {
        return x == comp.x && y == comp.y;
    }

    bool operator!=( const coords_2& comp ) {
        return x != comp.x || y != comp.y;
    }

    coords_2 operator+( const coords_2& op ) {
        return { x + op.x, y + op.y };
    }

    coords_2 operator-( const coords_2& op ) {
        return { x - op.x, y - op.y };
    }

    coords_2& operator+=( const coords_2& op ) {
        x += op.x;
        y += op.y;

        return *this;
    }

    coords_2& operator-=( const coords_2& op ) {
        x -= op.x;
        y -= op.y;

        return *this;
    }

    std::string to_json() const {
        return "{x:" + std::to_string ( x )
               + ",y:" + std::to_string ( y ) + "}";
    }
};

template<typename T>
struct coords_3 {
    T x, y, z;


    coords_3() = default;

    coords_3( T x, T y, T z )
        : x ( x ), y ( y ), z ( z ) {}

    coords_3( coords_3&& move ) = default;

    coords_3( const coords_3& copy ) = default;

    virtual ~coords_3() = default;

    coords_3& operator=( coords_3&& move ) = default;

    coords_3& operator=( const coords_3& copy ) = default;


    bool operator==( const coords_3& comp ) {
        return x == comp.x && y == comp.y && z == comp.z;
    }

    bool operator!=( const coords_3& comp ) {
        return x != comp.x || y != comp.y || z != comp.z;
    }

    coords_3 operator+( const coords_3& op ) {
        return { x + op.x, y + op.y, z + op.z };
    }

    coords_3 operator-( const coords_3& op ) {
        return { x - op.x, y - op.y, z + op.z };
    }

    coords_3& operator+=( const coords_3& op ) {
        x += op.x;
        y += op.y;
        z += op.z;

        return *this;
    }

    coords_3& operator-=( const coords_3& op ) {
        x -= op.x;
        y -= op.y;
        z -= op.z;

        return *this;
    }

    std::string to_json() const {
        return "{x:" + std::to_string ( x )
               + ",y:" + std::to_string ( y )
               + ",z:" + std::to_string ( z ) + "}";
    }
};

template<typename T>
struct dims_2 {
    T width, height;


    dims_2() = default;

    dims_2( T x, T y )
        : width ( x ), height ( y ) {}

    dims_2( dims_2&& move ) = default;

    dims_2( const dims_2& copy ) = default;

    virtual ~dims_2() = default;

    dims_2& operator=( dims_2&& move ) = default;

    dims_2& operator=( const dims_2& copy ) = default;


    bool operator==( const dims_2& comp ) {
        return width == comp.width && height == comp.height;
    }

    bool operator!=( const dims_2& comp ) {
        return width != comp.width || height != comp.height;
    }

    dims_2 operator+( const dims_2& op ) {
        return { width + op.width, height + op.height };
    }

    dims_2 operator-( const dims_2& op ) {
        return { width - op.width, height - op.height };
    }

    dims_2& operator+=( const dims_2& op ) {
        width  += op.width;
        height += op.height;

        return *this;
    }

    dims_2& operator-=( const dims_2& op ) {
        width  -= op.width;
        height -= op.height;

        return *this;
    }

    T area() const {
        return width * height;
    }

    std::string to_json() const {
        return "{width:" + std::to_string ( width )
               + ",height:" + std::to_string ( height ) + "}";
    }
};

template<typename T>
struct dims_3 {
    T width, height, depth;


    dims_3() = default;

    dims_3( T x, T y, T z )
        : width ( x ), height ( y ), depth ( z ) {}

    dims_3( dims_3&& move ) = default;

    dims_3( const dims_3& copy ) = default;

    virtual ~dims_3() = default;

    dims_3& operator=( dims_3&& move ) = default;

    dims_3& operator=( const dims_3& copy ) = default;


    bool operator==( const dims_3& comp ) {
        return width == comp.width
               && height == comp.height
               && depth == comp.depth;
    }

    bool operator!=( const dims_3& comp ) {
        return width != comp.width
               || height != comp.height
               || depth != comp.depth;
    }

    dims_3 operator+( const dims_3& op ) {
        return { width + op.width, height + op.height, depth + op.depth };
    }

    dims_3 operator-( const dims_3& op ) {
        return { width - op.width, height - op.height, depth - op.depth };
    }

    dims_3& operator+=( const dims_3& op ) {
        width  += op.width;
        height += op.height;
        depth  += op.depth;

        return *this;
    }

    dims_3& operator-=( const dims_3& op ) {
        width  -= op.width;
        height -= op.height;
        depth  -= op.depth;

        return *this;
    }

    T volume() const {
        return width * height * depth;
    }

    std::string to_json() const {
        return "{width:" + std::to_string ( width )
               + ",height:" + std::to_string ( height )
               + ",depth:" + std::to_string ( depth ) + "}";
    }
};

typedef coords_2<GLint>  coords_2i;
typedef coords_2<GLuint> coords_2u;
typedef dims_2<GLuint>   dims_2u;
typedef dims_2<GLfloat>  dims_2f;
}

#endif // ifndef GLPP_SPECS_H
