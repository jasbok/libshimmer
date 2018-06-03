#ifndef SHIMMER_GENERATOR_OUTPUT_H
#define SHIMMER_GENERATOR_OUTPUT_H

#include "header.h"
#include "source.h"

#include <fstream>

namespace apigen
{
class output
{
    typedef std::experimental::filesystem::path path;

public:
    output( const std::string& source,
            const std::string& header_dest,
            const std::string& source_dest );

    virtual ~output() = default;

    template<typename T>
    output& operator<<( const T& out ) {
        _header_stream << out;
        _source_stream << out;

        return *this;
    }

private:
    path _source;

    path _header_dest;

    path _source_dest;

    std::ofstream _header_ofs;

    std::ofstream _source_ofs;

    header _header_stream;

    source _source_stream;
};
}

#endif // ifndef SHIMMER_GENERATOR_OUTPUT_H
