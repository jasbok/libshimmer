#include "ft_wrapper.h"
#include "ft_wrapper_impl.h"

#include <iostream>

using namespace glpp;
using namespace std;

ft_wrapper::ft_wrapper()
    : _impl ( std::make_unique<impl>() )
{}

ft_wrapper::~ft_wrapper() = default;

void ft_wrapper::load_face ( const string&      path,
                             const unsigned int size,
                             const unsigned int dpi )
{
    _impl->load_face ( path, size, dpi );
}

glyph ft_wrapper::get_glyph ( wchar_t unicode ) const
{
    return _impl->get_glyph ( unicode );
}
