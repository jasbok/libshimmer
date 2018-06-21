#ifndef COMMON_ENV_H
#define COMMON_ENV_H

#include <regex>
#include <string>
#include <vector>

namespace common::env
{
/**
 * @brief evar Reads an environment variable.
 * @param evar The name of the environment variable
 * @param defaultt The default value to return if the variable is not present.
 * @return The value of the environment variable; defaultt otherwise.
 * @throws evar_not_found_exception if the environment variable does not exist.
 */
std::string evar ( const std::string& evar );

/**
 * @brief evar Reads an environment variable.
 * @param evar The name of the environment variable
 * @param defaultt The default value to return if the variable is not present.
 * @return The value of the environment variable; defaultt otherwise.
 */
std::string evar ( const std::string& evar,
                   const std::string& defaultt );

struct evar_not_found_exception : public std::runtime_error {
    evar_not_found_exception( const std::string& evar );

    virtual ~evar_not_found_exception() = default;
};
}
#endif // ifndef COMMON_ENV_H
