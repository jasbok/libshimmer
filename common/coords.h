#ifndef COMMON_COORDS_H
#define COMMON_COORDS_H

#include <string>

namespace common
{
template<typename T>
struct coords_2 {
    T x, y;


    coords_2()
        : x ( 0 ), y ( 0 ) {}

    coords_2( T x, T y )
        : x ( x ), y ( y ) {}

    coords_2( coords_2&& move ) = default;

    coords_2( const coords_2& copy ) = default;

    virtual ~coords_2() = default;

    coords_2& operator=( coords_2&& move ) = default;

    coords_2& operator=( const coords_2& copy ) = default;


    bool operator==( const coords_2& comp ) const {
        return x == comp.x && y == comp.y;
    }

    bool operator!=( const coords_2& comp ) const {
        return x != comp.x || y != comp.y;
    }

    coords_2 operator+( const coords_2& op ) const {
        return { x + op.x, y + op.y };
    }

    coords_2 operator-( const coords_2& op ) const {
        return { x - op.x, y - op.y };
    }

    coords_2 operator*( const coords_2& op ) const {
        return { x* op.x, y* op.y };
    }

    coords_2 operator/( const coords_2& op ) const {
        return { x / op.x, y / op.y };
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

    coords_2& operator*=( float factor ) {
        x *= factor;
        y *= factor;

        return *this;
    }

    template<typename S>
    operator coords_2<S>( ) const {
        return coords_2<S>( static_cast<S>( x ),
                            static_cast<S>( y ) );
    }

    std::string to_json() const {
        return "{\"x\":" + std::to_string ( x )
               + ",\"y\":" + std::to_string ( y ) + "}";
    }
};

template<typename T>
std::ostream& operator<<( std::ostream& os, const coords_2<T>& value ) {
    os << value.to_json();

    return os;
}

template<typename T>
struct coords_3 {
    T x, y, z;


    coords_3()
        : x ( 0 ), y ( 0 ), z ( 0 ) {}

    coords_3( T x, T y, T z )
        : x ( x ), y ( y ), z ( z ) {}

    coords_3( coords_3&& move ) = default;

    coords_3( const coords_3& copy ) = default;

    virtual ~coords_3() = default;

    coords_3& operator=( coords_3&& move ) = default;

    coords_3& operator=( const coords_3& copy ) = default;


    bool operator==( const coords_3& comp ) const {
        return x == comp.x && y == comp.y && z == comp.z;
    }

    bool operator!=( const coords_3& comp ) const {
        return x != comp.x || y != comp.y || z != comp.z;
    }

    coords_3 operator+( const coords_3& op ) const {
        return { x + op.x, y + op.y, z + op.z };
    }

    coords_3 operator-( const coords_3& op ) const {
        return { x - op.x, y - op.y, z - op.z };
    }

    coords_3 operator*( const coords_3& op ) const {
        return { x* op.x, y* op.y, z* op.z };
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

    coords_3& operator*=( float factor ) {
        x *= factor;
        y *= factor;
        z *= factor;

        return *this;
    }

    template<typename S>
    operator coords_3<S>( ) const {
        return coords_3<S>( static_cast<S>( x ),
                            static_cast<S>( y ),
                            static_cast<S>( z ) );
    }

    std::string to_json() const {
        return "{\"x\":" + std::to_string ( x )
               + ",\"y\":" + std::to_string ( y )
               + ",\"z\":" + std::to_string ( z ) + "}";
    }
};

template<typename T>
std::ostream& operator<<( std::ostream& os, const coords_3<T>& value ) {
    os << value.to_json();

    return os;
}
}
#endif // ifndef COMMON_COORDS_H
