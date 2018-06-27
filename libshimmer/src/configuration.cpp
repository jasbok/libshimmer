#include "configuration.h"

#include "common/json.h"

namespace shimmer
{
config_mapper::config_mapper( config* conf )
    : _conf ( conf )
{}

std::string config_mapper::to_json (
    const struct config::general::logging& logging ) {
    std::stringstream ss;

    ss << "{";
    ss << "\"level\":"
       << common::json::to_json ( _to_string ( logging.level ) );
    ss << ",\"output\":"
       << common::json::to_json ( _to_string ( logging.output ) );
    ss << ",\"file\":"
       << common::json::to_json ( logging.file );
    ss << "}";

    return ss.str();
}

std::string config_mapper::to_json ( const struct config::general& general ) {
    std::stringstream ss;

    ss << "{";
    ss << "\"config_dirs\":"
       << common::json::to_json ( general.config_dirs );
    ss << ",\"data_dirs\":"
       << common::json::to_json ( general.data_dirs );
    ss << ",\"font_dirs\":"
       << common::json::to_json ( general.font_dirs );
    ss << ",\"image_dirs\":"
       << common::json::to_json ( general.image_dirs );
    ss << ",\"shader_dirs\":"
       << common::json::to_json ( general.shader_dirs );
    ss << ",\"logging\":"
       << to_json ( general.logging );
    ss << "}";

    return ss.str();
}

std::string config_mapper::to_json ( const struct config::input& input ) {
    std::stringstream ss;

    ss << "{";
    ss << "\"grab\":"
       << common::json::to_json ( input.grab );
    ss << "}";

    return ss.str();
}

std::string config_mapper::to_json ( const struct config::video::shader& shader )
{
    std::stringstream ss;

    ss << "{";
    ss << "\"vertex\":"
       << common::json::to_json ( shader.vertex );
    ss << ",\"fragment\":"
       << common::json::to_json ( shader.fragment );
    ss << "}";

    return ss.str();
}

std::string config_mapper::to_json (
    const struct config::video::limiter& limiter ) {
    std::stringstream ss;

    ss << "{";
    ss << "\"rate\":"
       << limiter.rate;
    ss << ",\"samples\":"
       << limiter.samples;
    ss << "}";

    return ss.str();
}

std::string config_mapper::to_json ( const struct config::video& video ) {
    std::stringstream ss;

    ss << "{";
    ss << "\"font\":"
       << common::json::to_json ( video.font );
    ss << ",\"shader\":"
       << to_json ( video.shader );
    ss << ",\"filter\":"
       << common::json::to_json ( _to_string ( video.filter ) );
    ss << ",\"aspect\":"
       << common::json::to_json ( _to_string ( video.aspect ) );
    ss << ",\"custom_aspect\":"
       << video.custom_aspect.to_json();
    ss << ",\"limiter\":"
       << to_json ( video.limiter );
    ss << "}";

    return ss.str();
}

std::string config_mapper::to_json ( const struct config& config ) {
    std::stringstream ss;

    ss << "{";
    ss << "\"general\":"
       << to_json ( config.general );
    ss << ",\"input\":"
       << to_json ( config.input );
    ss << ",\"video\":"
       << to_json ( config.video );
    ss << "}";

    return ss.str();
}

void config_mapper::apply ( const config_mapper::map_t& map ) {
    for ( const auto& entry : map ) {
        _set_property ( entry );
    }
}

std::string config_mapper::to_json()
{
    return to_json ( *_conf );
}

std::string config_mapper::_to_string ( const config_mapper::log_level& level )
{
    switch ( level ) {
    case log_level::debug: return "debug";

    case log_level::error: return "error";

    case log_level::fatal: return "fatal";

    case log_level::info: return "info";

    case log_level::off: return "off";

    case log_level::trace: return "trace";

    case log_level::warning: return "warning";
    }

    return "warning";
}

config_mapper::log_level config_mapper::_to_log_level ( const std::string& level )
{
    if ( level.compare ( "debug"   ) == 0 ) return log_level::debug;

    if ( level.compare ( "error"   ) == 0 ) return log_level::error;

    if ( level.compare ( "fatal"   ) == 0 ) return log_level::fatal;

    if ( level.compare ( "info"    ) == 0 ) return log_level::info;

    if ( level.compare ( "off"     ) == 0 ) return log_level::off;

    if ( level.compare ( "trace"   ) == 0 ) return log_level::trace;

    if ( level.compare ( "warning" ) == 0 ) return log_level::warning;

    throw std::exception();
}

std::string config_mapper::_to_string ( const config_mapper::log_output& output )
{
    switch ( output ) {
    case log_output::console: return "console";

    case log_output::file: return "file";
    }

    return "console";
}

config_mapper::log_output config_mapper::_to_log_output (
    const std::string& output ) {
    if ( output.compare ( "console" ) == 0 ) return log_output::console;

    if ( output.compare ( "file" ) == 0 ) return log_output::file;

    throw std::exception();
}

std::string config_mapper::_to_string ( const config_mapper::tex_filter& filter )
{
    switch ( filter ) {
    case tex_filter::linear: return "linear";

    case tex_filter::nearest: return "nearest";
    }

    return "nearest";
}

config_mapper::tex_filter config_mapper::_to_tex_filter (
    const std::string& filter ) {
    if ( filter.compare ( "linear" ) == 0 ) return tex_filter::linear;

    if ( filter.compare ( "nearest" ) == 0 ) return tex_filter::nearest;

    throw std::exception();
}

std::string config_mapper::_to_string ( const config_mapper::vid_aspect& aspect )
{
    switch ( aspect ) {
    case vid_aspect::custom: return "custom";

    case vid_aspect::original: return "original";

    case vid_aspect::stretch: return "stretch";

    case vid_aspect::zoom: return "zoom";
    }

    return "original";
}

config_mapper::vid_aspect config_mapper::_to_vid_aspect (
    const std::string& aspect ) {
    if ( aspect.compare ( "custom" ) == 0 ) return vid_aspect::custom;

    if ( aspect.compare ( "original" ) == 0 ) return vid_aspect::original;

    if ( aspect.compare ( "stretch" ) == 0 ) return vid_aspect::stretch;

    if ( aspect.compare ( "zoom" ) == 0 ) return vid_aspect::zoom;

    throw std::exception();
}

void config_mapper::_insert ( config_mapper::map_t&           map,
                              const std::vector<std::string>& path,
                              const std::string&              value ) {
    map.insert ( { common::str::join ( path, "." ), value } );
}

void config_mapper::_insert_all ( config_mapper::map_t&           map,
                                  const std::vector<std::string>& path,
                                  const std::vector<std::string>& values ) {
    const std::string map_path = common::str::join ( path, "." ) + ".";
    int index                  = 0;

    for ( const auto& val : values ) {
        map.insert ( { map_path + std::to_string ( index ), val } );
        index++;
    }
}

void config_mapper::_set_property ( const std::pair<std::string,
                                                    std::string>& prop )
{
    using namespace common::str;
    static std::regex file_sep ( ":" );

    if ( prop.first.compare ( "general.config.dirs" ) == 0 ) {
        _conf->general.config_dirs = split ( prop.second, file_sep );
    }
    else if ( prop.first.compare ( "general.data_dirs" ) == 0 ) {
        _conf->general.data_dirs = split ( prop.second, file_sep );
    }
    else if ( prop.first.compare ( "general.font_dirs" ) == 0 ) {
        _conf->general.font_dirs = split ( prop.second, file_sep );
    }
    else if ( prop.first.compare ( "general.image_dirs" ) == 0 ) {
        _conf->general.image_dirs = split ( prop.second, file_sep );
    }
    else if ( prop.first.compare ( "general.shader_dirs" ) == 0 ) {
        _conf->general.shader_dirs = split ( prop.second, file_sep );
    }
    else if ( prop.first.compare ( "general.logging.level" ) == 0 ) {
        _conf->general.logging.level = _to_log_level ( prop.second );
    }
    else if ( prop.first.compare ( "general.logging.output" ) == 0 ) {
        _conf->general.logging.output = _to_log_output ( prop.second );
    }
    else if ( prop.first.compare ( "general.logging.file" ) == 0 ) {
        _conf->general.logging.file = prop.second;
    }
    else if ( prop.first.compare ( "input.grab" ) == 0 ) {
        _conf->general.logging.file = prop.second;
    }
    else if ( prop.first.compare ( "video.font" ) == 0 ) {
        _conf->video.font = prop.second;
    }
    else if ( prop.first.compare ( "video.font" ) == 0 ) {
        _conf->video.font = prop.second;
    }
    else if ( prop.first.compare ( "video.shader.vertex" ) == 0 ) {
        _conf->video.shader.vertex = prop.second;
    }
    else if ( prop.first.compare ( "video.shader.fragment" ) == 0 ) {
        _conf->video.shader.fragment = prop.second;
    }
    else if ( prop.first.compare ( "video.filter" ) == 0 ) {
        _conf->video.filter = _to_tex_filter ( prop.second );
    }
    else if ( prop.first.compare ( "video.aspect" ) == 0 ) {
        _conf->video.aspect = _to_vid_aspect ( prop.second );
    }
    else if ( prop.first.compare ( "video.custom_aspect.width" ) == 0 ) {
        _conf->video.custom_aspect.width =
            static_cast<unsigned int>( std::stoi ( prop.second ) );
    }
    else if ( prop.first.compare ( "video.custom_aspect.height" ) == 0 ) {
        _conf->video.custom_aspect.height =
            static_cast<unsigned int>( std::stoi ( prop.second ) );
    }
    else if ( prop.first.compare ( "video.limiter.rate" ) == 0 ) {
        _conf->video.limiter.rate =
            static_cast<unsigned int>( std::stoi ( prop.second ) );
    }
    else if ( prop.first.compare ( "video.limiter.samples" ) == 0 ) {
        _conf->video.limiter.samples =
            static_cast<unsigned int>( std::stoi ( prop.second ) );
    }
}

config_mapper::mapping_exception::mapping_exception(
    const std::string&              value,
    const std::vector<std::string>& path,
    const std::string&              expected )
    : runtime_error ( "Could not map value to configuration: '"
          + value + "' => '" + common::str::join ( path, "." )
          + "'; expected '" + expected + "'." )
{}


config_mapper::mapping_exception::mapping_exception(
    const std::string&              value,
    const std::vector<std::string>& path,
    const std::vector<std::string>& expected )
    : runtime_error ( "Could not map value to configuration: '"
          + value + "' => '" + common::str::join ( path, "." )
          + "'; expected one of the following: ["
          + common::str::join ( expected, ", " ) + "]." )
{}
}
