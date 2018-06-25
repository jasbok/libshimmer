#ifndef COMMON_ENV_H
#define COMMON_ENV_H

#include <stdexcept>
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

/**
 * @brief evar Reads an environment variable using a path converted to
 * upper-snakecase.
 * @param path The path with which to build the variable key.
 * @return The value of the environment variable at the given path.
 * @throws evar_not_found_exception if the environment variable does not exist.
 */
std::string evar_upper_snake ( const std::vector<std::string>& path );

struct evar_not_found_exception : public std::runtime_error {
    evar_not_found_exception( const std::string& evar );

    virtual ~evar_not_found_exception() = default;
};
}
#endif // ifndef COMMON_ENV_H
