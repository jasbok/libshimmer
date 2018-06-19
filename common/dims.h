#ifndef COMMON_DIMS_H
#define COMMON_DIMS_H

#include <string>

namespace common
{
template<typename T>
struct dims_2 {
    T width, height;


    dims_2()
        : width ( 0 ), height ( 0 ) {}

    dims_2( T width, T height )
        : width ( width ), height ( height ) {}

    dims_2( dims_2&& move ) = default;

    dims_2( const dims_2& copy ) = default;

    virtual ~dims_2() = default;

    dims_2& operator=( dims_2&& move ) = default;

    dims_2& operator=( const dims_2& copy ) = default;


    bool operator==( const dims_2& comp ) const {
        return width == comp.width && height == comp.height;
    }

    bool operator!=( const dims_2& comp ) const {
        return width != comp.width || height != comp.height;
    }

    dims_2 operator+( const dims_2& op ) const {
        return { width + op.width, height + op.height };
    }

    dims_2 operator-( const dims_2& op ) const {
        return { width - op.width, height - op.height };
    }

    dims_2 operator*( const dims_2& op ) const {
        return { width* op.width, height* op.height };
    }

    dims_2 operator/( const dims_2& op ) const {
        return { width / op.width, height / op.height };
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

    dims_2& operator*=( float factor ) {
        width  *= factor;
        height *= factor;

        return *this;
    }

    template<typename S>
    operator dims_2<S>( ) const {
        return dims_2<S>( static_cast<S>( width ),
                          static_cast<S>( height ) );
    }

    T area() const {
        return width * height;
    }

    float wh_ratio() const {
        return width / static_cast<float>( height );
    }

    float hw_ratio() const {
        return height / static_cast<float>( width );
    }

    std::string to_json() const {
        return "{\"width\":" + std::to_string ( width )
               + ",\"height\":" + std::to_string ( height ) + "}";
    }
};

template<typename T>
std::ostream& operator<<( std::ostream& os, const dims_2<T>& value ) {
    os << value.to_json();

    return os;
}

template<typename T>
struct dims_3 {
    T width, height, depth;


    dims_3()
        : width ( 0 ), height ( 0 ), depth ( 0 ) {}

    dims_3( T width, T height, T depth )
        : width ( width ), height ( height ), depth ( depth ) {}

    dims_3( dims_3&& move ) = default;

    dims_3( const dims_3& copy ) = default;

    virtual ~dims_3() = default;

    dims_3& operator=( dims_3&& move ) = default;

    dims_3& operator=( const dims_3& copy ) = default;


    bool operator==( const dims_3& comp ) const {
        return width == comp.width
               && height == comp.height
               && depth == comp.depth;
    }

    bool operator!=( const dims_3& comp ) const {
        return width != comp.width
               || height != comp.height
               || depth != comp.depth;
    }

    dims_3 operator+( const dims_3& op ) const {
        return { width + op.width, height + op.height, depth + op.depth };
    }

    dims_3 operator-( const dims_3& op ) const {
        return { width - op.width, height - op.height, depth - op.depth };
    }

    dims_3 operator*( const dims_3& op ) const {
        return { width* op.width, height* op.height, depth* op.depth };
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

    dims_3& operator*=( float factor ) {
        width  *= factor;
        height *= factor;
        depth  *= factor;

        return *this;
    }

    template<typename S>
    operator dims_3<S>( ) const {
        return dims_3<S>( static_cast<S>( width ),
                          static_cast<S>( height ),
                          static_cast<S>( depth ) );
    }

    T volume() const {
        return width * height * depth;
    }

    std::string to_json() const {
        return "{\"width\":" + std::to_string ( width )
               + ",\"height\":" + std::to_string ( height )
               + ",\"depth\":" + std::to_string ( depth ) + "}";
    }
};

template<typename T>
std::ostream& operator<<( std::ostream& os, const dims_3<T>& value ) {
    os << value.to_json();

    return os;
}

typedef dims_2<unsigned int> dims_2u;
typedef dims_3<unsigned int> dims_3u;

typedef dims_2<float> dims_2f;
typedef dims_3<float> dims_3f;
}
#endif // ifndef COMMON_DIMS_H
