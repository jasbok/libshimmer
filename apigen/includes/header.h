#ifndef SHIMMER_GENERATOR_HEADER_H
#define SHIMMER_GENERATOR_HEADER_H

#include "function.h"

#include <fstream>

#include <experimental/filesystem>

namespace apigen
{
class header
{
    typedef std::experimental::filesystem::path path;

public:
    header( const std::string& source,
            std::ostream&      destination );

    virtual ~header();

    header& write ( const function& function );

    header& operator<<( const function& function );

private:
    path _source;
    std::ostream& _destination;

    void _open_include_guard_and_includes();

    void _close_include_guard();
};
}


#endif // ifndef SHIMMER_GENERATOR_HEADER_H
