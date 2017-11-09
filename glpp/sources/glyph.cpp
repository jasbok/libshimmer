#include "glyph.h"

using namespace glpp;
using namespace std;

glyph_metadata::glyph_metadata( wchar_t          unicode,
                                const dims_2u&   dims,
                                const coords_2i& bearing,
                                const coords_2i& advance )
    : _unicode ( unicode ),
      _dims ( dims ),
      _bearing ( bearing ),
      _advance ( advance ),
      _has_vertical ( false ),
      _vertical_bearing()
{}

glyph_metadata::glyph_metadata( wchar_t          unicode,
                                const dims_2u&   dims,
                                const coords_2i& bearing,
                                const coords_2i& advance,
                                const coords_2i& vertical_bearing )
    : _unicode ( unicode ),
      _dims ( dims ),
      _bearing ( bearing ),
      _advance ( advance ),
      _has_vertical ( true ),
      _vertical_bearing ( vertical_bearing )
{}

unsigned int glyph_metadata::unicode() const
{
    return _unicode;
}

dims_2u glyph_metadata::dims() const
{
    return _dims;
}

coords_2i glyph_metadata::bearing() const
{
    return _bearing;
}

coords_2i glyph_metadata::advance() const
{
    return _advance;
}

bool glyph_metadata::has_vertical() const
{
    return _has_vertical;
}

coords_2i glyph_metadata::vertical_bearing() const
{
    return _vertical_bearing;
}

glyph::glyph( const glyph_metadata& meta )
    : _meta ( meta ),
      _data ( meta.dims().area() )
{}

glyph::glyph( const glyph_metadata&  meta,
              std::vector<uint8_t>&& data )
    : _meta ( meta ),
      _data ( std::move ( data ) )
{}

glyph::glyph( glyph&& move )
    : _meta ( std::move ( move._meta ) ),
      _data ( std::move ( move._data ) )
{}

glyph::~glyph() {}

glyph& glyph::operator=( glyph&& move )
{
    _meta = std::move ( move._meta );
    _data = std::move ( move._data );

    return *this;
}

glyph_metadata glyph::meta() const
{
    return _meta;
}

vector<uint8_t>& glyph::data()
{
    return _data;
}
