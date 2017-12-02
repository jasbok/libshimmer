#ifndef SHIMMER_FILE_READER_H
#define SHIMMER_FILE_READER_H

#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace shimmer
{
struct file {
    std::string   path;
    std::ifstream stream;
};

class file_reader
{
public:
    file_reader( const std::vector<std::string>& search_paths );

    virtual ~file_reader() = default;

    file read ( const std::string&      path,
                std::ios_base::openmode mode = std::ios_base::in ) const;

    std::string              read_str ( const std::string& path ) const;

    std::vector<std::string> search_paths() const;

private:
    std::vector<std::string> _search_paths;
};

struct search_path_exception : public std::runtime_error {
    search_path_exception( const std::string& mesg )
        : std::runtime_error ( mesg ) {}
};

struct file_read_exception : public std::runtime_error {
    file_read_exception( const std::string& mesg )
        : std::runtime_error ( mesg ) {}
};
}

#endif // ifndef SHIMMER_FILE_READER_H
