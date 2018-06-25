#ifndef COMMON_JSON_H
#define COMMON_JSON_H

#include "external/json/json.hpp"

namespace common::json
{
/**
 * @brief as_string Gets the value of the field at the given path as a string.
 * @param obj The json object to get the value from.
 * @param path A vector representing the path to the field.
 * @return The value of the field as a string.
 * @throws field_absent_exception if the field does not exist.
 */
std::string as_string ( const nlohmann::json&           obj,
                        const std::vector<std::string>& path );

struct field_absent_exception : public std::runtime_error {
    field_absent_exception( const std::vector<std::string>& path );

    field_absent_exception( const std::vector<std::string>& path,
                            const std::string&              inner );

    virtual ~field_absent_exception() = default;
};

struct could_not_parse_exception : public std::runtime_error {
    could_not_parse_exception( const std::vector<std::string>& path,
                               const std::string&              type );

    could_not_parse_exception( const std::vector<std::string>& path,
                               const std::string&              type,
                               const std::string&              inner );

    virtual ~could_not_parse_exception() = default;
};
}

#endif // ifndef COMMON_JSON_H
