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

template<>
void set_property ( float&                property,
                    const nlohmann::json& json,
                    const std::string&    field ) {
    try {
        auto value = json.at ( field );

        if ( value.is_string() ) {
            value = std::stof ( value.get<std::string>() );
        }

        property = value.get<float>();
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
            "[ERROR] Unable to set config property: %s -> %s\nExpected a float.\nException: %s\n",
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

std::string to_string ( const enum config::video::shape::type& shape ) {
    switch ( shape ) {
    case config::video::shape::type::lens: return "lens";

    case config::video::shape::type::rectangle: return "rectangle";
    }

    return "rectangle";
}

void from_string ( enum config::logging::level& level,
                   const std::string&           str ) {
    if ( str.compare ( "debug" ) == 0 ) {
        level = config::logging::level::debug;
    }
    else if ( str.compare ( "error" ) == 0 ) {
        level = config::logging::level::error;
    }
    else if ( str.compare ( "fatal" ) ==  0 ) {
        level = config::logging::level::fatal;
    }
    else if ( str.compare ( "info" ) == 0 ) {
        level = config::logging::level::info;
    }
    else if ( str.compare ( "off" ) == 0 ) {
        level = config::logging::level::off;
    }
    else if ( str.compare ( "trace" ) == 0 ) {
        level = config::logging::level::trace;
    }
    else if ( str.compare ( "warning" ) == 0 ) {
        level = config::logging::level::warning;
    }
    else {
        throw config::mapping_exception ( "config::logging::level", str,
                                          { "trace",
                                            "debug",
                                            "info",
                                            "warning",
                                            "error",
                                            "fatal",
                                            "off" } );
    }
}

void from_string ( enum config::logging::output& output,
                   const std::string&            str ) {
    if ( str.compare ( "console" ) == 0 ) {
        output = config::logging::output::console;
    }
    else if ( str.compare ( "file" ) == 0 ) {
        output = config::logging::output::file;
    }
    else {
        throw config::mapping_exception ( "config::logging::output", str,
                                          { "console",
                                            "file" } );
    }
}

void from_string ( enum config::video::filter& filter,
                   const std::string&          str ) {
    if ( str.compare ( "linear" ) == 0 ) {
        filter = config::video::filter::linear;
    }
    else if ( str.compare ( "nearest" ) == 0 ) {
        filter = config::video::filter::nearest;
    }
    else {
        throw config::mapping_exception ( "config::video::filter", str,
                                          { "linear",
                                            "nearest" } );
    }
}

void from_string ( enum config::video::aspect& aspect,
                   const std::string&          str ) {
    if ( str.compare ( "custom" ) == 0 ) {
        aspect = config::video::aspect::custom;
    }
    else if ( str.compare ( "original" ) == 0 ) {
        aspect = config::video::aspect::original;
    }
    else if ( str.compare ( "stretch" ) == 0 ) {
        aspect = config::video::aspect::stretch;
    }
    else if ( str.compare ( "zoom" ) == 0 ) {
        aspect = config::video::aspect::zoom;
    }
    else {
        throw config::mapping_exception ( "config::video::aspect", str,
                                          { "custom",
                                            "original",
                                            "stretch",
                                            "zoom" } );
    }
}

void from_string ( enum config::video::shape::type& shape,
                   const std::string&               str ) {
    if ( str.compare ( "lens" ) == 0 ) {
        shape = config::video::shape::type::lens;
    }
    else if ( str.compare ( "rectangle" ) == 0 ) {
        shape = config::video::shape::type::rectangle;
    }
    else {
        throw config::mapping_exception ( "config::video::shape::type", str,
                                          { "lens",
                                            "rectangle" } );
    }
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
    from_string ( level, json );
}

void to_json ( nlohmann::json&                     json,
               const enum config::logging::output& output ) {
    json = to_string ( output );
}

void from_json ( const nlohmann::json&         json,
                 enum config::logging::output& output ) {
    from_string ( output, json );
}

void to_json ( nlohmann::json&             json,
               const struct config::video& video ) {
    json = {
        { "aspect",        video.aspect        },
        { "custom_aspect", video.custom_aspect },
        { "filter",        video.filter        },
        { "font",          video.font          },
        { "limiter",       video.limiter       },
        { "shader",        video.shader        },
        { "shape",         video.shape         }
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
    set_property ( video.shape,         json, "shape" );
}

void to_json ( nlohmann::json&                   json,
               const enum config::video::aspect& aspect ) {
    json = to_string ( aspect );
}

void from_json ( const nlohmann::json&       json,
                 enum config::video::aspect& aspect ) {
    from_string ( aspect, json );
}

void to_json ( nlohmann::json&                   json,
               const enum config::video::filter& filter ) {
    json = to_string ( filter );
}

void from_json ( const nlohmann::json&       json,
                 enum config::video::filter& filter ) {
    from_string ( filter, json );
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

void to_json ( nlohmann::json&                    json,
               const struct config::video::shape& shape ) {
    json = {
        { "type", shape.type },
        { "lens", shape.lens }
    };
}

void from_json ( const nlohmann::json&        json,
                 struct config::video::shape& shape ) {
    set_property ( shape.lens, json, "lens" );
    set_property ( shape.type, json, "type" );
}

void to_json ( nlohmann::json&                          json,
               const struct config::video::shape::lens& lens ) {
    json = {
        { "curve",   lens.curve   },
        { "quality", lens.quality }
    };
}

void from_json ( const nlohmann::json&              json,
                 struct config::video::shape::lens& lens ) {
    set_property ( lens.curve,   json, "curve" );
    set_property ( lens.quality, json, "quality" );
}

void to_json ( nlohmann::json&                        json,
               const enum config::video::shape::type& type ) {
    json = to_string ( type );
}

void from_json ( const nlohmann::json&            json,
                 enum config::video::shape::type& type ) {
    from_string ( type, json );
}
}
