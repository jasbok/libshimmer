#ifndef LIBSHIMMER_UTITLITIES_FILE_READER_H
#define LIBSHIMMER_UTITLITIES_FILE_READER_H

#include <string>
#include <vector>

namespace shimmer
{
class file_reader {
public:
    static std::string read(const std::string& path);
    static std::vector<std::string> read_lines(const std::string& path);
};
}

#endif
