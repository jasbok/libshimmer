#ifndef COMMON_STRING_H
#define COMMON_STRING_H

#include <regex>
#include <string>
#include <vector>

namespace common
{
/**
 * @brief split Splits a string using the given regex.
 * @param str The string to split.
 * @param reg The regex to use to split the string.
 * @return A list of split segments.
 */
std::vector<std::string> split ( const std::string& str,
                                 const std::regex&  reg );

/**
 * @brief split Splits a string using the given regex, ignoring empty segments.
 * @param str The string to split.
 * @param reg The regex to use to split the string.
 * @return A list of split segments, with all empty segments filtered out.
 */
std::vector<std::string> split_ignore_empty ( const std::string& str,
                                              const std::regex&  reg );
}

#endif // ifndef COMMON_STRING_H
