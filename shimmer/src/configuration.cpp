#include "configuration.h"

#include "common/env.h"
#include "common/file.h"
#include "common/json.h"

#include <sstream>

namespace shimmer
{
std::vector<std::string> as_file_vector ( const config::property& prop ) {
    static std::regex file_sep ( ":" );

    return common::str::split ( prop.second, file_sep );
}

bool as_bool ( const config::property& prop ) {
    std::string val = common::str::lower ( prop.second );

    if ( val.compare ( "true" ) == 0 ) return true;
    else if ( val.compare ( "false" ) == 0 ) return false;

    throw config::mapping_exception ( prop, "boolean" );
}

enum config::logging::level as_logging_level ( const config::property& prop ) {
    try {
        return to_log_level ( prop.second );
    }
    catch ( const std::exception& ) {
        throw config::mapping_exception ( prop, { "trace",
                                                  "debug",
                                                  "info",
                                                  "warning",
                                                  "error",
                                                  "fatal",
                                                  "off" } );
    }
}

enum config::logging::output as_logging_output ( const config::property& prop )
{
    try {
        return to_log_output ( prop.second );
    }
    catch ( const std::exception& ) {
        throw config::mapping_exception ( prop,
                                          std::vector<std::string>{ "console",
                                                                    "file" } );
    }
}

enum config::video::filter as_texture_filter ( const config::property& prop ) {
    try {
        return to_tex_filter ( prop.second );
    }
    catch ( const std::exception& ) {
        throw config::mapping_exception ( prop,
                                          std::vector<std::string>{ "linear",
                                                                    "nearest" } );
    }
}

enum config::video::aspect as_video_aspect ( const config::property& prop ) {
    try {
        return to_vid_aspect ( prop.second );
    }
    catch ( const std::exception& ) {
        throw config::mapping_exception ( prop, { "original",
                                                  "stretch",
                                                  "zoom",
                                                  "custom" } );
    }
}

unsigned int as_uint ( const config::property& prop ) {
    try {
        return static_cast<unsigned int>( std::stoi ( prop.second ) );
    }
    catch ( const std::exception& ) {
        throw config::mapping_exception ( prop, "unsigned integer" );
    }
}

config& config::set_property ( const property& prop )
{
    if ( prop.first.compare ( "general.config.dirs" ) == 0 ) {
        general.config_dirs = as_file_vector ( prop );
    }
    else if ( prop.first.compare ( "general.data_dirs" ) == 0 ) {
        general.data_dirs = as_file_vector ( prop );
    }
    else if ( prop.first.compare ( "general.font_dirs" ) == 0 ) {
        general.font_dirs = as_file_vector ( prop );
    }
    else if ( prop.first.compare ( "general.image_dirs" ) == 0 ) {
        general.image_dirs = as_file_vector ( prop );
    }
    else if ( prop.first.compare ( "general.shader_dirs" ) == 0 ) {
        general.shader_dirs = as_file_vector ( prop );
    }
    else if ( prop.first.compare ( "input.grab" ) == 0 ) {
        input.grab = as_bool ( prop );
    }
    else if ( prop.first.compare ( "logging.level" ) == 0 ) {
        logging.level = as_logging_level ( prop );
    }
    else if ( prop.first.compare ( "logging.output" ) == 0 ) {
        logging.output = as_logging_output ( prop );
    }
    else if ( prop.first.compare ( "logging.file" ) == 0 ) {
        logging.file = prop.second;
    }
    else if ( prop.first.compare ( "video.font" ) == 0 ) {
        video.font = prop.second;
    }
    else if ( prop.first.compare ( "video.shader.vertex" ) == 0 ) {
        video.shader.vertex = prop.second;
    }
    else if ( prop.first.compare ( "video.shader.fragment" ) == 0 ) {
        video.shader.fragment = prop.second;
    }
    else if ( prop.first.compare ( "video.shader.scale" ) == 0 ) {
        video.shader.scale = as_uint ( prop );
    }
    else if ( prop.first.compare ( "video.filter" ) == 0 ) {
        video.filter = as_texture_filter ( prop );
    }
    else if ( prop.first.compare ( "video.aspect" ) == 0 ) {
        video.aspect = as_video_aspect ( prop );
    }
    else if ( prop.first.compare ( "video.custom_aspect.width" ) == 0 ) {
        video.custom_aspect.width = as_uint ( prop );
    }
    else if ( prop.first.compare ( "video.custom_aspect.height" ) == 0 ) {
        video.custom_aspect.height = as_uint ( prop );
    }
    else if ( prop.first.compare ( "video.custom.aspect.width" ) == 0 ) {
        video.custom_aspect.width = as_uint ( prop );
    }
    else if ( prop.first.compare ( "video.custom.aspect.height" ) == 0 ) {
        video.custom_aspect.height = as_uint ( prop );
    }
    else if ( prop.first.compare ( "video.limiter.rate" ) == 0 ) {
        video.limiter.rate = as_uint ( prop );
    }
    else if ( prop.first.compare ( "video.limiter.samples" ) == 0 ) {
        video.limiter.samples = as_uint ( prop );
    }
    else {
        printf ( "[WARN] Unknown config property: %s\n", prop.first.c_str() );
    }

    return *this;
}

config& config::set_properties ( const config::properties& props )
{
    for ( const auto& prop: props ) {
        set_property ( prop );
    }

    return *this;
}

config::mapping_exception::mapping_exception(
    const property&    prop,
    const std::string& expected )
    : runtime_error ( "Could not map value to configuration: '"
          + prop.second + "' => '" + prop.first
          + "'; expected '" + expected + "'." ) {}

config::mapping_exception::mapping_exception(
    const property&                 prop,
    const std::vector<std::string>& expected )
    : runtime_error ( "Could not map value to configuration: '"
          + prop.second + "' => '" + prop.first
          + "'; expected one of the following: ["
          + common::str::join ( expected, ", " ) + "]." )
{}

std::string to_json ( const struct config::general& general ) {
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
    ss << "}";

    return ss.str();
}

std::string to_json ( const struct config::input& input ) {
    std::stringstream ss;

    ss << "{";
    ss << "\"grab\":"
       << common::json::to_json ( input.grab );
    ss << "}";

    return ss.str();
}

std::string to_json (
    const struct config::logging& logging ) {
    std::stringstream ss;

    ss << "{";
    ss << "\"level\":"
       << common::json::to_json ( to_string ( logging.level ) );
    ss << ",\"output\":"
       << common::json::to_json ( to_string ( logging.output ) );
    ss << ",\"file\":"
       << common::json::to_json ( logging.file );
    ss << "}";

    return ss.str();
}

std::string to_json ( const struct config::video::shader& shader )
{
    std::stringstream ss;

    ss << "{";
    ss << "\"vertex\":"
       << common::json::to_json ( shader.vertex );
    ss << ",\"fragment\":"
       << common::json::to_json ( shader.fragment );
    ss << ",\"scale\":"
       << common::json::to_json ( shader.scale );
    ss << "}";

    return ss.str();
}

std::string to_json (
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

std::string to_json ( const struct config::video& video ) {
    std::stringstream ss;

    ss << "{";
    ss << "\"font\":"
       << common::json::to_json ( video.font );
    ss << ",\"shader\":"
       << to_json ( video.shader );
    ss << ",\"filter\":"
       << common::json::to_json ( to_string ( video.filter ) );
    ss << ",\"aspect\":"
       << common::json::to_json ( to_string ( video.aspect ) );
    ss << ",\"custom_aspect\":"
       << video.custom_aspect.to_json();
    ss << ",\"limiter\":"
       << to_json ( video.limiter );
    ss << "}";

    return ss.str();
}

std::string to_json ( const struct config& config ) {
    std::stringstream ss;

    ss << "{";
    ss << "\"general\":"
       << to_json ( config.general );
    ss << ",\"input\":"
       << to_json ( config.input );
    ss << ",\"logging\":"
       << to_json ( config.logging );
    ss << ",\"video\":"
       << to_json ( config.video );
    ss << "}";

    return ss.str();
}

std::string to_string ( const enum config::logging::level& level )
{
    switch ( level ) {
    case config::logging::level::debug: return "debug";

    case config::logging::level::error: return "error";

    case config::logging::level::fatal: return "fatal";

    case config::logging::level::info: return "info";

    case config::logging::level::off: return "off";

    case config::logging::level::trace: return "trace";

    case config::logging::level::warning: return "warning";
    }

    return "warning";
}

std::string to_string ( const enum config::logging::output& output )
{
    switch ( output ) {
    case config::logging::output::console: return "console";

    case config::logging::output::file: return "file";
    }

    return "console";
}

std::string to_string ( const enum config::video::filter& filter )
{
    switch ( filter ) {
    case config::video::filter::linear: return "linear";

    case config::video::filter::nearest: return "nearest";
    }

    return "nearest";
}

std::string to_string ( const enum config::video::aspect& aspect )
{
    switch ( aspect ) {
    case config::video::aspect::custom: return "custom";

    case config::video::aspect::original: return "original";

    case config::video::aspect::stretch: return "stretch";

    case config::video::aspect::zoom: return "zoom";
    }

    return "original";
}

enum config::logging::level to_log_level (
    const std::string& level )
{
    if ( level.compare ( "debug" ) == 0 ) return config::logging::level::debug;

    if ( level.compare ( "error" ) == 0 ) return config::logging::level::error;

    if ( level.compare ( "fatal" ) == 0 ) return config::logging::level::fatal;

    if ( level.compare ( "info" ) == 0 ) return config::logging::level::info;

    if ( level.compare ( "off" ) == 0 ) return config::logging::level::off;

    if ( level.compare ( "trace" ) == 0 ) return config::logging::level::trace;

    if ( level.compare ( "warning" ) ==
         0 ) return config::logging::level::warning;

    throw std::exception();
}

enum config::logging::output to_log_output (
    const std::string& output ) {
    if ( output.compare ( "console" ) ==
         0 ) return config::logging::output::console;

    if ( output.compare ( "file" ) == 0 ) return config::logging::output::file;

    throw std::exception();
}

enum config::video::filter to_tex_filter (
    const std::string& filter ) {
    if ( filter.compare ( "linear" ) ==
         0 ) return config::video::filter::linear;

    if ( filter.compare ( "nearest" ) ==
         0 ) return config::video::filter::nearest;

    throw std::exception();
}

enum config::video::aspect to_vid_aspect (
    const std::string& aspect ) {
    if ( aspect.compare ( "custom" ) ==
         0 ) return config::video::aspect::custom;

    if ( aspect.compare ( "original" ) ==
         0 ) return config::video::aspect::original;

    if ( aspect.compare ( "stretch" ) ==
         0 ) return config::video::aspect::stretch;

    if ( aspect.compare ( "zoom" ) == 0 ) return config::video::aspect::zoom;

    throw std::exception();
}

config::properties config::from_environment()
{
    config::properties props;
    auto evars = common::env::find_all ( std::regex ( "^SHIMMER_.*" ) );

    for ( auto& evar : evars ) {
        std::string key = evar.first.substr ( 8, evar.first.length() );
        key = common::str::lower ( common::str::replace ( key, "_", "." ) );
        props.insert ( { key, evar.second } );
    }

    return props;
}

config::properties config::from_file ( const std::string& path )
{
    auto config = common::file::read_all ( path );
    auto json   = nlohmann::json ( config );

    return common::json::as_properties ( json );
}

config config::create()
{
    config conf;

    config::properties environment_props = from_environment();
    config::properties file_props;

    auto environment_configs = environment_props.find ( "general.config_dirs" );

    if ( environment_configs != environment_props.end() ) {
        conf.set_property ( *environment_configs );
    }

    if ( !conf.general.config_dirs.empty() ) {
        try {
            file_props = from_file (
                common::file::find ( "shimmer.conf",
                                     conf.general.config_dirs ) );
        }
        catch ( const std::exception& ex ) {
            printf ( "[WARN] Failed to load config file: %s\n", ex.what() );
        }
    }

    conf.set_properties ( file_props )
        .set_properties ( environment_props );

    return conf;
}

void to_json ( nlohmann::json& j,
               const config&   config ) {
    j = {
        { "general", config.general },
        { "input",   config.input   },
        { "logging", config.logging },
        { "video",   config.video   },
    };
}

void from_json ( const nlohmann::json& j,
                 config&               config ) {
    if ( common::json::exists ( j, { "general" } ) ) {
        config.general = j.at ( "general" );
    }

    if ( common::json::exists ( j, { "input" } ) ) {
        config.input = j.at ( "input" );
    }

    if ( common::json::exists ( j, { "logging" } ) ) {
        config.logging = j.at ( "logging" );
    }

    if ( common::json::exists ( j, { "video" } ) ) {
        config.video = j.at ( "video" );
    }
}

void to_json ( nlohmann::json&               j,
               const struct config::general& g ) {
    j = {
        { "config_dirs",  g.config_dirs },
        { "data_dirs",    g.data_dirs   },
        { "font_dirs",    g.font_dirs   },
        { "image_dirs",   g.image_dirs  },
        { "shaders_dirs", g.shader_dirs },
    };
}

void from_json ( const nlohmann::json&   j,
                 struct config::general& g ) {
    typedef std::vector<std::string> strings;

    if ( common::json::exists ( j, { "config_dirs" } ) ) {
        g.config_dirs = j.at ( "config_dirs" ).get<strings>();
    }

    if ( common::json::exists ( j, { "data_dirs" } ) ) {
        g.data_dirs = j.at ( "data_dirs" ).get<strings>();
    }

    if ( common::json::exists ( j, { "font_dirs" } ) ) {
        g.font_dirs =  j.at ( "font_dirs" ).get<strings>();
    }

    if ( common::json::exists ( j, { "image_dirs" } ) ) {
        g.image_dirs = j.at ( "image_dirs" ).get<strings>();
    }

    if ( common::json::exists ( j, { "shader_dirs" } ) ) {
        g.shader_dirs = j.at ( "shader_dirs" ).get<strings>();
    }
}

void to_json ( nlohmann::json&             j,
               const struct config::input& i ) {
    j = {
        { "grab", i.grab }
    };
}

void from_json ( const nlohmann::json& j,
                 struct config::input& i ) {
    if ( common::json::exists ( j, { "input" } ) ) {
        i.grab = j.at ( "input" );
    }
}

void to_json ( nlohmann::json&               j,
               const struct config::logging& l ) {
    j = {
        { "level",  l.level  },
        { "output", l.output },
        { "file",   l.file   }
    };
}

void from_json ( const nlohmann::json&   j,
                 struct config::logging& l ) {
    if ( common::json::exists ( j, { "level" } ) ) {
        l.level = j.at ( "level" );
    }

    if ( common::json::exists ( j, { "output" } ) ) {
        l.output = j.at ( "output" );
    }

    if ( common::json::exists ( j, { "file" } ) ) {
        l.file = j.at ( "file" );
    }
}

void to_json ( nlohmann::json&                    json,
               const enum config::logging::level& level ) {
    json = to_string ( level );
}

void from_json ( const nlohmann::json&        json,
                 enum config::logging::level& level ) {
    level = to_log_level ( json.get<std::string>() );
}

void to_json ( nlohmann::json&                     json,
               const enum config::logging::output& output ) {
    json = to_string ( output );
}

void from_json ( const nlohmann::json&         json,
                 enum config::logging::output& output ) {
    output = to_log_output ( json.get<std::string>() );
}

void to_json ( nlohmann::json&             j,
               const struct config::video& v ) {
    j = {
        { "aspect",        v.aspect        },
        { "custom_aspect", v.custom_aspect },
        { "filter",        v.filter        },
        { "font",          v.font          },
        { "limiter",       v.limiter       },
        { "shader",        v.shader        }
    };
}

void from_json ( const nlohmann::json& j,
                 struct config::video& v ) {
    if ( common::json::exists ( j, { "aspect" } ) ) {
        v.aspect = j.at ( "aspect" );
    }

    if ( common::json::exists ( j, { "custom_aspect" } ) ) {
        v.custom_aspect = j.at ( "custom_aspect" );
    }

    if ( common::json::exists ( j, { "filter" } ) ) {
        v.filter = j.at ( "filter" );
    }

    if ( common::json::exists ( j, { "font" } ) ) {
        v.font = j.at ( "font" );
    }

    if ( common::json::exists ( j, { "limiter" } ) ) {
        v.limiter = j.at ( "limiter" );
    }

    if ( common::json::exists ( j, { "shader" } ) ) {
        v.shader = j.at ( "shader" );
    }
}

void to_json ( nlohmann::json&                   json,
               const enum config::video::aspect& aspect ) {
    json = to_string ( aspect );
}

void from_json ( const nlohmann::json&       json,
                 enum config::video::aspect& aspect ) {
    aspect = to_vid_aspect ( json.get<std::string>() );
}

void to_json ( nlohmann::json&                   json,
               const enum config::video::filter& filter ) {
    json = to_string ( filter );
}

void from_json ( const nlohmann::json&       json,
                 enum config::video::filter& filter ) {
    filter = to_tex_filter ( json.get<std::string>() );
}

void to_json ( nlohmann::json&                      json,
               const struct config::video::limiter& limiter ) {
    json = {
        { "rate",    limiter.rate    },
        { "samples", limiter.samples }
    };
}

void from_json ( const nlohmann::json&          json,
                 struct config::video::limiter& limiter ) {
    if ( common::json::exists ( json, { "rate" } ) ) {
        limiter.rate = json.at ( "rate" );
    }

    if ( common::json::exists ( json, { "samples" } ) ) {
        limiter.rate = json.at ( "samples" );
    }
}

void to_json ( nlohmann::json&                     json,
               const struct config::video::shader& shader ) {
    json = {
        { "fragment", shader.fragment },
        { "scale",    shader.scale    },
        { "vertex",   shader.vertex   }
    };
}

void from_json ( const nlohmann::json&         json,
                 struct config::video::shader& shader ) {
    if ( common::json::exists ( json, { "fragment" } ) ) {
        shader.fragment = json.at ( "fragment" );
    }

    if ( common::json::exists ( json, { "scale" } ) ) {
        shader.scale = json.at ( "scale" );
    }

    if ( common::json::exists ( json, { "vertex" } ) ) {
        shader.vertex = json.at ( "vertex" );
    }
}
}
