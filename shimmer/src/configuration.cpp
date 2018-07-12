#include "configuration.h"

#include "common/env.h"
#include "common/file.h"
#include "common/json.h"

#include <sstream>

namespace shimmer
{
nlohmann::json config::merge ( const nlohmann::json& a,
                               const nlohmann::json& b )
{
    auto merged = b.flatten();

    for ( const auto& prop : a.items() ) {
        if ( !prop.value().is_null() ) merged[prop.key()] = prop.value();
    }

    return merged.unflatten();
}

nlohmann::json config::from_environment()
{
    nlohmann::json conf = nlohmann::json::object();

    auto evars = common::env::find_all ( std::regex ( "^SHIMMER_.*" ) );

    for ( auto& evar : evars ) {
        auto key = evar.first.substr ( 8, evar.first.length() );
        key = common::str::replace ( key, "_", "/" );
        key = common::str::lower ( key );

        conf["/" + key] = evar.second;
    }

    conf = conf.unflatten();

    printf ( "[INFO] Environment config:\n%s\n", conf.dump ( 2 ).c_str() );

    return conf;
}

nlohmann::json config::from_file ( const std::string& path )
{
    auto conf = nlohmann::json ( common::file::read_all ( path ) );

    printf ( "[INFO] File config (%s):\n%s\n",
             path.c_str(),
             conf.dump ( 2 ).c_str() );

    return nlohmann::json ( conf );
}

config config::create()
{
    config conf = from_environment();

    if ( !conf.general.config_dirs.empty() ) {
        try {
            auto config_file = common::file::find ( "shimmer.conf",
                                                    conf.general.config_dirs );

            conf = merge ( from_file ( config_file ), conf );
        }
        catch ( const std::exception& ex ) {
            printf ( "[WARN] Failed to load config file: %s\n", ex.what() );
        }
    }

    printf ( "[INFO] Shimmer configuration:\n%s\n",
             nlohmann::json ( conf ).dump ( 2 ).c_str() );

    return conf;
}

template<typename T>
void set_property ( T&                    property,
                    const nlohmann::json& json,
                    const std::string&    field ) {
    try {
        property = json.at ( field ).get<T>();
    }
    catch ( const nlohmann::json::exception& ex ) {
        if ( ex.id == 403 ) {}
        else {
            printf (
                "[ERROR] Unable to set config property: %s -> %s\nException: %s\n",
                field.c_str(),
                json.at ( field ).dump().c_str(),
                ex.what() );
        }
    }
    catch ( const std::exception& ex ) {
        printf (
            "[ERROR] Unable to set config property: %s -> %s\nException: %s\n",
            field.c_str(),
            json.at ( field ).dump().c_str(),
            ex.what() );
    }
}

template<>
void set_property ( unsigned int&         property,
                    const nlohmann::json& json,
                    const std::string&    field ) {
    try {
        auto value = json.at ( field );

        if ( value.is_string() ) {
            value = std::stof ( value.get<std::string>() );
        }

        property = value.get<unsigned int>();
    }
    catch ( const nlohmann::json::exception& jex ) {
        if ( jex.id == 403 ) {}
        else {
            printf ( "[ERROR] Unable to set config property: %s -> %s\n%s\n",
                     field.c_str(),
                     json.at ( field ).dump().c_str(),
                     jex.what() );
        }
    }
    catch ( const std::exception& ex  ) {
        printf (
            "[ERROR] Unable to set config property: %s -> %s\nExpected an unsigned integer.\nException: %s\n",
            field.c_str(),
            json.at ( field ).dump().c_str(),
            ex.what() );
    }
}

config::mapping_exception::mapping_exception(
    const std::string&              property,
    const std::string&              value,
    const std::vector<std::string>& expected )
    : runtime_error ( "Could not map value: '"
          + property + "' => '" + value
          + "'; expected one of the following: ["
          + common::str::join ( expected, ", " ) + "]." )
{}

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

    throw config::mapping_exception ( "config::logging::level", level,
                                      { "trace",
                                        "debug",
                                        "info",
                                        "warning",
                                        "error",
                                        "fatal",
                                        "off" } );
}

enum config::logging::output to_log_output (
    const std::string& output ) {
    if ( output.compare ( "console" ) ==
         0 ) return config::logging::output::console;

    if ( output.compare ( "file" ) == 0 ) return config::logging::output::file;

    throw config::mapping_exception ( "config::logging::output", output,
                                      { "console",
                                        "file" } );
}

enum config::video::filter to_tex_filter (
    const std::string& filter ) {
    if ( filter.compare ( "linear" ) ==
         0 ) return config::video::filter::linear;

    if ( filter.compare ( "nearest" ) ==
         0 ) return config::video::filter::nearest;

    throw config::mapping_exception ( "config::video::filter", filter,
                                      { "linear",
                                        "nearest" } );
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

    throw config::mapping_exception ( "config::video::aspect", aspect,
                                      { "custom",
                                        "original",
                                        "stretch",
                                        "zoom" } );
}

void to_json ( nlohmann::json& json,
               const config&   config ) {
    json = {
        { "general", config.general },
        { "input",   config.input   },
        { "logging", config.logging },
        { "video",   config.video   },
    };
}

void from_json ( const nlohmann::json& json,
                 config&               config ) {
    set_property ( config.general, json, "general" );
    set_property ( config.input,   json, "input" );
    set_property ( config.logging, json, "logging" );
    set_property ( config.video,   json, "video" );
}

void to_json ( nlohmann::json&               json,
               const struct config::general& general ) {
    json = {
        { "config_dirs",  general.config_dirs },
        { "data_dirs",    general.data_dirs   },
        { "font_dirs",    general.font_dirs   },
        { "image_dirs",   general.image_dirs  },
        { "shaders_dirs", general.shader_dirs },
    };
}

void from_json ( const nlohmann::json&   json,
                 struct config::general& general ) {
    set_property ( general.config_dirs, json, "config_dirs" );
    set_property ( general.data_dirs,   json, "data_dirs" );
    set_property ( general.font_dirs,   json, "font_dirs" );
    set_property ( general.image_dirs,  json, "image_dirs" );
    set_property ( general.shader_dirs, json, "shader_dirs" );
}

void to_json ( nlohmann::json&             json,
               const struct config::input& input ) {
    json = {
        { "grab", input.grab }
    };
}

void from_json ( const nlohmann::json& json,
                 struct config::input& input ) {
    set_property ( input.grab, json, "grab" );
}

void to_json ( nlohmann::json&               json,
               const struct config::logging& logging ) {
    json = {
        { "level",  logging.level  },
        { "output", logging.output },
        { "file",   logging.file   }
    };
}

void from_json ( const nlohmann::json&   json,
                 struct config::logging& logging ) {
    set_property ( logging.level,  json, "level" );
    set_property ( logging.output, json, "output" );
    set_property ( logging.file,   json, "file" );
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

void to_json ( nlohmann::json&             json,
               const struct config::video& video ) {
    json = {
        { "aspect",        video.aspect        },
        { "custom_aspect", video.custom_aspect },
        { "filter",        video.filter        },
        { "font",          video.font          },
        { "limiter",       video.limiter       },
        { "shader",        video.shader        }
    };
}

void from_json ( const nlohmann::json& json,
                 struct config::video& video ) {
    set_property ( video.aspect,        json, "aspect" );
    set_property ( video.custom_aspect, json, "custom_aspect" );
    set_property ( video.filter,        json, "filter" );
    set_property ( video.font,          json, "font" );
    set_property ( video.limiter,       json, "limiter" );
    set_property ( video.shader,        json, "shader" );
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
    set_property ( limiter.rate,    json, "rate" );
    set_property ( limiter.samples, json, "samples" );
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
    set_property ( shader.fragment, json, "fragment" );
    set_property ( shader.scale,    json, "scale" );
    set_property ( shader.vertex,   json, "vertex" );
}
}
