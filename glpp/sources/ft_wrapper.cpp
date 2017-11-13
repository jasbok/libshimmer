#include "ft_wrapper.h"

#include <iostream>

using namespace glpp;
using namespace std;

ft_wrapper::ft_wrapper()
    : _ft()
{
    auto ft_err = FT_Init_FreeType ( &_ft );

    if ( ft_err != FT_Err_Ok ) {
        throw freetype_init_exception();
    }
}

ft_wrapper::ft_wrapper( ft_wrapper&& move )
    : _ft ( move._ft )
{
    move._ft = nullptr;
}

ft_wrapper::~ft_wrapper()
{
    FT_Done_FreeType ( _ft );
}

ft_wrapper& ft_wrapper::operator=( ft_wrapper&& move )
{
    _ft      = move._ft;
    move._ft = nullptr;

    return *this;
}

FT_Library ft_wrapper::handle() const
{
    return _ft;
}

// *INDENT-OFF*
void ft_wrapper::print_error(FT_Error ft_err, const string &label)
{
    #undef __FTERRORS_H__
    #define FT_ERRORDEF( e, v, s )  case e: cerr << s << ": " << label << endl; break;
    #define FT_ERROR_START_LIST     switch (ft_err) {
    #define FT_ERROR_END_LIST       default: cerr << label << "Unknown FT_Error: " << endl;}
    #include FT_ERRORS_H
}
// *INDENT-ON*
