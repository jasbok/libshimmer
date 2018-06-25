#ifndef COMMON_STRING_H
#define COMMON_STRING_H

#include <regex>
#include <string>
#include <vector>

namespace common::str
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

/**
 * @brief replace Replaces the first instance of the specified match string
 * found in the source string with the replacement string.
 * @param src The source string to manipulate.
 * @param match The string to match against the source string.
 * @param repl The replacement string.
 * @return A new instance of the string with the first match replaced with
 * the replacement string.
 */
std::string replace ( const std::string& src,
                      const std::string& match,
                      const std::string& repl );

/**
 * @brief contains Checks if the source string contains an instance of the match
 * string.
 * @param src The source string to match against.
 * @param match The string to find within the source string.
 * @return True if atleast one instance of the match string was found in the
 * source, false otherwise.
 */
bool contains ( const std::string& src,
                const std::string& match );

/**
 * @brief join Joins a list of strings into one string using the specified
 * separator string.
 * @param strings The list of strings to join.
 * @param separator The separator to add between the strings.
 * @return The new composite string.
 */
std::string join ( const std::vector<std::string> strings,
                   const std::string              separator );

/**
 * @brief upper Converts the string to uppercase.
 * @param str The string to convert.
 * @return The new uppercase string.
 */
std::string upper ( const std::string& str );

/**
 * @brief lower Converts the string to lowercase.
 * @param str The string to convert.
 * @return The new lowercase string.
 */
std::string lower ( const std::string& str );
}

#endif // ifndef COMMON_STRING_H
