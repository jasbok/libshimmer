#include "font_spec.h"

using namespace glpp;
using namespace std;

font_spec::font_spec( const string&           id,
                      const string&           path,
                      unsigned int            size,
                      std::vector<range_uint> unicodes )
    : _id ( id ),
      _path ( path ),
      _size ( size ),
      _unicodes ( unicodes )
{}

font_spec& font_spec::path ( const string& path )
{
    _path = path;

    return *this;
}

string font_spec::path() const
{
    return _path;
}

font_spec& font_spec::id ( const string& id )
{
    _id = id;

    return *this;
}

string font_spec::id() const
{
    return _id;
}

font_spec& font_spec::size ( unsigned int size )
{
    _size = size;

    return *this;
}

unsigned int font_spec::size() const
{
    return _size;
}

font_spec& font_spec::unicodes ( const unicode_ranges& unicodes )
{
    _unicodes = unicodes;

    return *this;
}

font_spec::unicode_ranges font_spec::unicodes() const
{
    return _unicodes;
}
