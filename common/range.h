#ifndef COMMON_RANGE_H
#define COMMON_RANGE_H

#include <string>

namespace common {
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
}

#endif
