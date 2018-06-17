#ifndef SHIMMER_LOG_H
#define SHIMMER_LOG_H

#include "external/plog/Log.h"

#include <memory>

namespace shimmer
{
/**
 * @brief Configures the logging framework using environment variables.
 */
class logger
{
public:
    enum class level {
        trace,
        debug,
        info,
        warning,
        error,
        fatal,
        off
    };

    enum class type {
        console,
        file
    };

    logger();

    virtual ~logger() = default;

    /**
     * @brief level Gets the current logging level.
     * @return The current logging level.
     */
    enum level level() const;

    /**
     * @brief type Gets the current logger type.
     * @return The current logger type.
     */
    enum type type() const;

private:
    enum level _level;

    enum type _type;

    std::unique_ptr<plog::IAppender> _appender;

    /**
     * @brief _env_level Gets the loggging level from environment variables.
     * @return Logging level as specified by environment variables.
     */
    enum level _env_level();

    /**
     * @brief _env_type Gets the loggger type from environment variables.
     * @return Logger type as specified by environment variables.
     */
    enum type _env_type();

    /**
     * @brief _create_appender Creates an appender using the current logger
     * type.
     * @return A new appender.
     */
    std::unique_ptr<plog::IAppender> _create_appender();
};
}

#endif // ifndef SHIMMER_LOG_H
