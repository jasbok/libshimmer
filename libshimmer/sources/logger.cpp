#include "logger.h"

#include "common/env.h"

#include "plog/Appenders/ColorConsoleAppender.h"

namespace shimmer
{
logger::logger()
    : _level ( _env_level() ),
      _type ( _env_type() ),
      _appender ( _create_appender() )

{
    switch ( _level ) {
    case level::trace:
        plog::init ( plog::verbose, _appender.get() );
        break;

    case level::debug:
        plog::init ( plog::debug, _appender.get() );
        break;

    case level::info:
        plog::init ( plog::info, _appender.get() );
        break;

    case level::warning:
        plog::init ( plog::warning, _appender.get() );
        break;

    case level::error:
        plog::init ( plog::error, _appender.get() );
        break;

    case level::fatal:
        plog::init ( plog::fatal, _appender.get() );
        break;

    default:
        break;
    }

    LOGI << "Setup logger with level=" << ( int )_level;
}

enum logger::level logger::level() const {
    return _level;
}

enum logger::type logger::type() const {
    return _type;
}

#define RET_LEVEL_IF( LEVEL ) \
    if ( env_level.compare ( # LEVEL ) == 0 ) return level::LEVEL

enum logger::level logger::_env_level()
{
    std::string env_level =
        common::env::evar ( "SHIMMER_LOG_LEVEL", "warning" );

    RET_LEVEL_IF ( trace );
    RET_LEVEL_IF ( debug );
    RET_LEVEL_IF ( info );
    RET_LEVEL_IF ( warning );
    RET_LEVEL_IF ( error );
    RET_LEVEL_IF ( fatal );
    RET_LEVEL_IF ( off );

    return level::warning;
}

#define RET_TYPE_IF( TYPE ) \
    if ( env_type.compare ( # TYPE ) == 0 ) return type::TYPE

enum logger::type logger::_env_type()
{
    std::string env_type = common::env::evar ( "SHIMMER_LOG_TYPE", "console" );

    RET_TYPE_IF ( console );
    RET_TYPE_IF ( file );

    return type::console;
}

std::unique_ptr<plog::IAppender> logger::_create_appender()
{
    switch ( _type ) {
    case type::console:

        return std::make_unique<plog::ColorConsoleAppender<plog::TxtFormatter>>();

    case type::file:

        return std::make_unique<plog::ColorConsoleAppender<plog::TxtFormatter>>();
    }

    throw std::runtime_error (
              "Could not create logging appender: Unknown logger type." );
}
}
