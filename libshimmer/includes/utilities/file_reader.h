#ifndef LIBSHIMMER_UTITLITIES_FILE_READER_H
#define LIBSHIMMER_UTITLITIES_FILE_READER_H

#include <string>
#include <vector>

namespace shimmer::file_reader
{
std::string read ( const std::string& path );
std::vector<std::string> read_lines ( const std::string& path );
}

#endif
