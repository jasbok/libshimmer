#include "output.h"

#include <exception>

namespace apigen
{
output::output( const std::string& source,
                const std::string& header_dest,
                const std::string& source_dest )
    : _source ( source ),
      _header_dest ( header_dest ),
      _source_dest ( source_dest ),
      _header_ofs ( _header_dest ),
      _source_ofs ( _source_dest ),
      _header_stream ( source, _header_ofs ),
      _source_stream ( _header_dest, _source_ofs )
{
    if ( !_header_ofs.is_open() ) {
        std::string mesg = "Could not create header: ";
        mesg += std::string ( _header_dest.c_str() );

        throw std::runtime_error ( mesg );
    }

    if ( !_header_ofs.is_open() ) {
        std::string mesg = "Could not create source: ";
        mesg += std::string ( _source_dest.c_str() );

        throw std::runtime_error ( mesg );
    }
}
}
