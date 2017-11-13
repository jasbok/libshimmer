#ifndef GLPP_FONT_SPEC_H
#define GLPP_FONT_SPEC_H

#include "specs.h"

#include <vector>

namespace glpp{
class font_spec
{
public:
    typedef std::vector<range_uint> unicode_ranges;

    font_spec() = delete;

    font_spec( const std::string&      id,
               const std::string&      path,
               unsigned int            size,
               std::vector<range_uint> unicodes );

    font_spec( font_spec&& move ) = default;

    font_spec( const font_spec& copy ) = default;

    virtual ~font_spec() = default;

    font_spec& operator=( font_spec&& move ) = default;

    font_spec& operator=( const font_spec& copy ) = default;


    font_spec&     id ( const std::string& id );

    std::string    id() const;

    font_spec&     path ( const std::string& path );

    std::string    path() const;

    font_spec&     size ( unsigned int size );

    unsigned int   size() const;

    font_spec&     unicodes ( const unicode_ranges& unicodes );

    unicode_ranges unicodes() const;

private:
    std::string _id;

    std::string _path;

    unsigned int _size;

    std::vector<range_uint> _unicodes;
};
}

#endif
