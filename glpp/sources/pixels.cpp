#include "pixels.h"

using namespace glpp;
using namespace std;

pixels::pixels( unique_ptr<uint8_t>&& data,
                const dims_2u&        dims,
                enum format           format,
                enum type             type )
    : _data ( move ( data ) ),
      _dims ( dims ),
      _format ( format ),
      _type ( type )
{}

pixels::pixels( pixels&& move )
    : _data ( std::move ( move._data ) ),
      _dims ( std::move ( move._dims ) ),
      _format ( move._format ),
      _type ( move._type )
{}

pixels::~pixels() {}

pixels& pixels::operator=( pixels&& move ) {
    _data = std::move ( move._data );
    _dims = std::move ( move._dims );

    _format = move._format;
    _type   = move._type;

    return *this;
}

const uint8_t* pixels::data() const {
    return _data.get();
}

uint8_t* pixels::data() {
    return _data.get();
}

dims_2u pixels::dims() const {
    return _dims;
}

enum pixels::format pixels::format() const {
    return _format;
}

enum pixels::type pixels::type() const {
    return _type;
}

std::string pixels::to_json() const {
    return "{data:" +
           std::to_string ( reinterpret_cast<size_t>(_data.get()) ) +
           ",dims:" +
           _dims.to_json() + "";
}
