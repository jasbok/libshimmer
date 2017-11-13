#include "bitmap.h"

using namespace glpp;
using namespace std;

bitmap::bitmap( const dims_2u& dims )
    : dims ( dims ),
      data ( dims.area() )
{}

bitmap::bitmap( bitmap&& move )
    : dims ( move.dims ),
      data ( std::move ( move.data ) )
{}

bitmap& bitmap::operator=( bitmap&& move )
{
    dims = move.dims;
    data = std::move ( move.data );

    return *this;
}
