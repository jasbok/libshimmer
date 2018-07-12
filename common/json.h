#ifndef COMMON_JSON_H
#define COMMON_JSON_H

#include "external/json/json.hpp"

namespace common::json
{
/**
 * @brief as_string Gets the value of the json primitive as a string.
 * @param json The json primitive to convert to a string.
 * @return The value of the primitive as a string.
 * @throws std::exception if the obj is not a primitive.
 */
std::string as_string ( const nlohmann::json& json );

/**
 * @brief as_string Gets the value of the field at the given path as a string.
 * @param json The json object to get the value from.
 * @param path A vector representing the path to the field.
 * @return The value of the field as a string.
 * @throws field_absent_exception if the field does not exist.
 */
std::string as_string ( const nlohmann::json&           json,
                        const std::vector<std::string>& path );

///**
// * @brief as_string_vector Gets a vector of strings from the object field.
// * @param obj The json object.
// * @param path The path to the field.
// * @return A vector of strings.
// * @throws field_absent_exception if the field does not exist.
// * @throws could_not_parse_exception if the field is not an array.
// */
// std::vector<std::string> as_string_vector ( const nlohmann::json&
//           obj,
//                                            const std::vector<std::string>&
// path );

/**
 * @brief as_properties Converts the json object to a map of string properties.
 * @param obj The json object to convert.
 * @return The string properties map.
 */
std::unordered_map<std::string, std::string>
as_properties ( const nlohmann::json& obj );

/**
 * @brief to_json Converts the given string vector to the corresponding json
 * array.
 * @param vec The vector to convert.
 * @return The json array corresponding to vec.
 */
std::string to_json ( const std::vector<std::string>& vec );

/**
 * @brief to_json Converts a string to the corresponding json string.
 * @param str The string to convert.
 * @return The json array corresponding to vec.
 * @note Simply wraps the string in double quotes.
 */
std::string to_json ( const std::string& str );

/**
 * @brief to_json Converts a boolean value to a json boolean.
 * @param val The boolean to convert.
 * @return The json boolean value.
 */
std::string to_json ( bool val );

/**
 * @brief exists Checks if a field exists.
 * @param obj The object to search.
 * @param path The path to the field.
 * @return True if the field exists, false otherwise.
 */
bool exists ( const nlohmann::json&           obj,
              const std::vector<std::string>& path );

struct field_absent_exception : public std::runtime_error {
    field_absent_exception( const std::vector<std::string>& path );

    field_absent_exception( const std::vector<std::string>& path,
                            const std::string&              inner );

    virtual ~field_absent_exception() = default;
};

struct could_not_parse_exception : public std::runtime_error {
    could_not_parse_exception( const std::string& type,
                               const std::string& expected );

    could_not_parse_exception( const std::vector<std::string>& path,
                               const std::string&              type );

    could_not_parse_exception( const std::vector<std::string>& path,
                               const std::string&              type,
                               const std::string&              inner );

    virtual ~could_not_parse_exception() = default;
};
}

#endif // ifndef COMMON_JSON_H
