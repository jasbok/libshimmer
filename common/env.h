#ifndef COMMON_ENV_H
#define COMMON_ENV_H

#include <regex>
#include <string>
#include <vector>

namespace common
{
/**
 * @brief evar Reads an environment variable.
 * @param evar The name of the environment variable
 * @param defaultt The default value to return if the variable is not present.
 * @return The value of the environment variable; defaultt otherwise.
 */
std::string evar ( const std::string& evar,
                   const std::string& defaultt );
}
#endif // ifndef COMMON_ENV_H
