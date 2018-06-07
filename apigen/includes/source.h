#ifndef SHIMMER_GENERATOR_SOURCE_H
#define SHIMMER_GENERATOR_SOURCE_H

#include "decl.h"

#include <string>

#include <experimental/filesystem>

namespace apigen
{
class source
{
    typedef std::experimental::filesystem::path path;

public:
    source( const std::string& header,
            std::ostream&      destination );

    virtual ~source();

    source& write ( const struct function_decl& function );

    source& operator<<( const struct function_decl& function );

private:
    path _header;
    std::ostream& _destination;

    void _include_header();
};
}


#endif // ifndef SHIMMER_GENERATOR_SOURCE_H
