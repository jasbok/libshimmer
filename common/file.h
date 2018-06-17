#ifndef COMMON_FILE_H
#define COMMON_FILE_H

#include <stdexcept>
#include <string>
#include <vector>

namespace common::file
{
struct read_exception : public std::runtime_error {
    read_exception( const std::string& path );

    virtual ~read_exception() = default;
};

struct not_found_exception : public std::runtime_error {
    not_found_exception( const std::string& path );

    virtual ~not_found_exception() = default;
};

/**
 * @brief read_all Read all the contents of a file into a string.
 * @param path The path of the file to read.
 * @return The contents of the file in a string. Throws an exception if the file
 * could not be read.
 */
std::string read_all ( const std::string& path );

/**
 * @brief read_lines Read all lines of a file into a vector.
 * @param path The path to the file.
 * @return A vector containing the lines of the file.
 */
std::vector<std::string> read_lines ( const std::string& path );

/**
 * @brief find Tries to find the file in the provided search paths.
 * @param path The relative path of the file.
 * @param search_paths The search paths to look for the file.
 * @return A list of existing files found in the search paths.
 */
std::vector<std::string> find ( const std::string&              path,
                                const std::vector<std::string>& search_paths );

/**
 * @brief find Tries to find the file in the provided search paths.
 * @param path The relative path of the file.
 * @param search_paths The search paths to look for the file.
 * @return The first file matching the path found in the search paths.
 * @throws If no file was found.
 */
std::string find_one ( const std::string&              path,
                       const std::vector<std::string>& search_paths );

/**
 * @brief find_and_throw Tries to find the file in the provided search paths,
 * throwing an exception if none could be found.
 * @param path The relative path of the file.
 * @param search_paths The search paths to look for the file.
 * @return A list of existing files found in the search paths.
 * @throws not_found_exception if none is found.
 */
std::vector<std::string> find_and_throw ( const std::string&              path,
                                          const std::vector<std::string>& search_paths );
}

#endif // ifndef COMMON_FILE_H
