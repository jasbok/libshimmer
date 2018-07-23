#ifndef COMMON_LOGGER_H
#define COMMON_LOGGER_H

#include "external/fmt/format.h"
#include "external/fmt/time.h"

#include <regex>
#include <string>
#include <unordered_map>

namespace common
{
class logger
{
public:
    static logger& get ( const std::string& name );

    enum class level {
        off = 0,
        fatal,
        error,
        warning,
        info,
        debug,
        trace
    };

    enum class output {
        console,
        file
    };

    logger();

    virtual ~logger() = default;

    template<typename ... ARGS>
    void trace ( const std::string& mesg, const ARGS& ... args ) const {
        if ( _level < level::trace ) return;

        _print_coloured ( level::trace, mesg, args ... );
    }

    template<typename ... ARGS>
    void debug ( const std::string& mesg, const ARGS& ... args ) const {
        if ( _level < level::debug ) return;

        _print_coloured ( level::debug, mesg, args ... );
    }

    template<typename ... ARGS>
    void info ( const std::string& mesg, const ARGS& ... args ) const {
        if ( _level < level::info ) return;

        _print_coloured ( level::info, mesg, args ... );
    }

    template<typename ... ARGS>
    void warn ( const std::string& mesg, const ARGS& ... args ) const {
        if ( _level < level::warning ) return;

        _print_coloured ( level::warning, mesg, args ... );
    }

    template<typename ... ARGS>
    void error ( const std::string& mesg, const ARGS& ... args ) const {
        if ( _level < level::error ) return;

        _print_coloured ( level::error, mesg, args ... );
    }

    template<typename ... ARGS>
    void fatal ( const std::string& mesg, const ARGS& ... args ) const {
        if ( _level < level::fatal ) return;

        _print_coloured ( level::fatal, mesg, args ... );
    }

    std::string name() const;

    logger&     level ( level level );

    logger&     output ( output output );

    logger&     file ( const std::string& file );

    logger&     format ( const std::string& format );

private:
    const static std::regex _level_regex;

    const static std::regex _logger_regex;
    const static std::regex _message_regex;

    std::string _name;

    enum level _level;

    enum output _output;

    std::string _file;

    std::string _format;

    static std::string _to_string ( enum level level );

    static fmt::Color  _to_colour ( enum level level );

    std::string        _compile ( const std::string& level ) const;

    template<typename ... ARGS>
    void _print_coloured ( enum level         level,
                           const std::string& mesg,
                           const ARGS& ...    args ) const {
        fmt::print_colored ( _to_colour ( level ),
                             _compile ( _to_string ( level ) ) + "\n",
                             fmt::format ( mesg, args ... ),
                             args ... );
    }

    static std::unordered_map<std::string, logger> _global;
};
} // namespace common

#endif // ifndef COMMON_LOGGER_H
