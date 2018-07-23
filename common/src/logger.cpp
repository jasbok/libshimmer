#include "logger.h"

namespace common
{
std::unordered_map<std::string, logger> logger::_global;

const std::regex logger::_level_regex   = std::regex ( "\\{level\\}" );
const std::regex logger::_logger_regex  = std::regex ( "\\{logger\\}" );
const std::regex logger::_message_regex = std::regex ( "\\{message\\}" );

logger::logger()
    : _level ( level::debug ),
      _output ( output::console ),
      _format ( "[{level}] ({:%FT%T%z}) {logger} - {message}" )
{}

logger& logger::get ( const std::string& name )
{
    auto& instance = _global[name];

    instance._name = name;

    return instance;
}

std::string logger::name() const {
    return _name;
}

logger& logger::level ( enum logger::level level ) {
    _level = level;

    return *this;
}

logger& logger::output ( enum logger::output output ) {
    _output = output;

    return *this;
}

logger& logger::file ( const std::string& file ) {
    _file = file;

    return *this;
}

logger& logger::format ( const std::string& format ) {
    _format = format;

    return *this;
}

std::string logger::_to_string ( enum logger::level level ) {
    switch ( level ) {
    case level::debug: return "debug";

    case level::error: return "error";

    case level::fatal: return "fatal";

    case level::info: return "info";

    case level::off: return "off";

    case level::trace: return "trace";

    case level::warning: return "warning";
    }

    return "unknown";
}

fmt::Color logger::_to_colour ( enum logger::level level ) {
    switch ( level ) {
    case level::debug: return fmt::Color::CYAN;

    case level::error: return fmt::Color::RED;

    case level::fatal: return fmt::Color::MAGENTA;

    case level::info: return fmt::Color::GREEN;

    case level::off: return fmt::Color::WHITE;

    case level::trace: return fmt::Color::WHITE;

    case level::warning: return fmt::Color::YELLOW;
    }

    return fmt::Color::WHITE;
}

std::string logger::_compile ( const std::string& level ) const  {
    std::string str = std::regex_replace ( _format, _level_regex, level );

    str = std::regex_replace ( str, _logger_regex, _name );

    str = std::regex_replace ( str, _message_regex, "{}" );

    std::time_t t = std::time ( nullptr );
    str = fmt::format ( str, *std::localtime ( &t ), "{}" );

    return str;
}
} // namespace common
