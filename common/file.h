#ifndef COMMON_FILE_H
#define COMMON_FILE_H

#include <fstream>
#include <string>
#include <vector>

namespace common::file
{
struct read_exception : public std::runtime_error {
    read_exception( const std::string& path );

    virtual ~read_exception();
};

/**
 * @brief read_all Read all the contents of a file into a string.
 * @param path The path of the file to read.
 * @return The contents of the file in a string. Throws an exception if the file
 *could not be read.
 */
std::string              read_all ( const std::string& path );

std::vector<std::string> read_lines ( const std::string& path );
}

#endif // ifndef COMMON_FILE_H
