#ifndef GLPP_FT_WRAPPER_H
#define GLPP_FT_WRAPPER_H

#include <ft2build.h>
#include FT_FREETYPE_H

#include <exception>
#include <string>

namespace glpp
{
class ft_wrapper
{
public:
    ft_wrapper();

    ft_wrapper( const ft_wrapper& copy ) = delete;

    ft_wrapper( ft_wrapper&& move );

    ~ft_wrapper();

    ft_wrapper& operator=( const ft_wrapper& copy ) = delete;

    ft_wrapper& operator=( ft_wrapper&& move );


    FT_Library handle() const;


    static void print_error ( FT_Error           ft_err,
                              const std::string& label );

private:
    FT_Library _ft;
};

struct freetype_init_exception : public std::exception {
    const char* what() const throw( ) {
        return "Could not initialise FreeType.";
    }
};
}

#endif // ifndef GLPP_FT_WRAPPER_H
