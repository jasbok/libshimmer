#ifndef LIBSHIMMER_CONFIGURATION_H
#define LIBSHIMMER_CONFIGURATION_H

#include "config_variables.h"

#include "common/dims.h"
#include "common/json.h"

#include <sstream>
#include <unordered_map>
#include <vector>

struct config {
    struct general {
        std::vector<std::string> config_dirs = shimmer::system::config_dirs;
        std::vector<std::string> data_dirs   = shimmer::system::data_dirs;
        std::vector<std::string> font_dirs   = shimmer::system::font_dirs;
        std::vector<std::string> image_dirs  = shimmer::system::image_dirs;
        std::vector<std::string> shader_dirs = shimmer::system::shader_dirs;

        struct logging {
            enum class level {
                trace,
                debug,
                info,
                warning,
                error,
                fatal,
                off
            };
            enum level level = level::warning;

            enum class output {
                console,
                file
            };
            enum output output = output::console;

            std::string file = "";
        };
        struct logging logging;
    };
    struct general general;

    struct input {
        bool grab = false;
    };
    struct input input;

    struct video {
        std::string font = "";

        struct shader {
            std::string vertex   = "default.vert";
            std::string fragment = "default.frag";
        };
        struct shader shader;

        enum class filter {
            nearest,
            linear
        };
        enum filter filter = filter::nearest;

        enum class aspect {
            original,
            stretch,
            zoom,
            custom
        };
        enum aspect aspect = aspect::original;

        common::dims_2u custom_aspect = { 16, 9 };

        struct limiter {
            unsigned int rate    = 0;
            unsigned int samples = 5;
        };
        struct limiter limiter;
    };
    struct video video;
};

class config_mapper
{
public:
    typedef std::unordered_map<std::string, std::string> map_t;

    config_mapper( config* conf )
        : _conf ( conf )
    {}

    std::string to_json ( const struct config::general::logging& logging ) {
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
        ss << ",\"logging\":"
           << to_json ( general.logging );
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

    std::string to_json ( const struct config::video::shader& shader ) {
        std::stringstream ss;

        ss << "{";
        ss << "\"vertex\":"
           << common::json::to_json ( shader.vertex );
        ss << ",\"fragment\":"
           << common::json::to_json ( shader.fragment );
        ss << "}";

        return ss.str();
    }

    std::string to_json ( const struct config::video::limiter& limiter ) {
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

    std::string to_json ( const struct config& config ) {
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

    void apply ( const map_t& map ) {}

    virtual ~config_mapper() = default;


    struct mapping_exception : public std::runtime_error {
        mapping_exception( const std::string&              value,
                           const std::vector<std::string>& path,
                           const std::string&              expected )
            : runtime_error ( "Could not map value to configuration: '"
                  + value + "' => '" + common::str::join ( path, "." )
                  + "'; expected '" + expected + "'." )
        {}

        mapping_exception( const std::string&              value,
                           const std::vector<std::string>& path,
                           const std::vector<std::string>& expected )
            : runtime_error ( "Could not map value to configuration: '"
                  + value + "' => '" + common::str::join ( path, "." )
                  + "'; expected one of the following: ["
                  + common::str::join ( expected, ", " ) + "]." )
        {}

        virtual ~mapping_exception() = default;
    };

private:
    config* _conf;

    typedef enum config::general::logging::level  log_level;
    typedef enum config::general::logging::output log_output;
    typedef enum config::video::filter            tex_filter;
    typedef enum config::video::aspect            vid_aspect;

    std::string _to_string ( const log_level& level ) {
        switch ( level ) {
        case log_level::debug: return "debug";

        case log_level::error: return "error";

        case log_level::fatal: return "fatal";

        case log_level::info: return "info";

        case log_level::off: return "off";

        case log_level::trace: return "trace";

        case log_level::warning: return "warning";
        }
    }

    log_level _to_log_level ( const std::string& level ) {
        if ( level.compare ( "debug"   ) == 0 ) return log_level::debug;

        if ( level.compare ( "error"   ) == 0 ) return log_level::error;

        if ( level.compare ( "fatal"   ) == 0 ) return log_level::fatal;

        if ( level.compare ( "info"    ) == 0 ) return log_level::info;

        if ( level.compare ( "off"     ) == 0 ) return log_level::off;

        if ( level.compare ( "trace"   ) == 0 ) return log_level::trace;

        if ( level.compare ( "warning" ) == 0 ) return log_level::warning;

        throw std::exception();
    }

    std::string _to_string ( const log_output& output ) {
        switch ( output ) {
        case log_output::console: return "console";

        case log_output::file: return "file";
        }
    }

    log_output _to_log_output ( const std::string& output ) {
        if ( output.compare ( "console" ) == 0 ) return log_output::console;

        if ( output.compare ( "file" ) == 0 ) return log_output::file;

        throw std::exception();
    }

    std::string _to_string ( const tex_filter& filter ) {
        switch ( filter ) {
        case tex_filter::linear: return "linear";

        case tex_filter::nearest: return "nearest";
        }
    }

    tex_filter _to_tex_filter ( const std::string& filter ) {
        if ( filter.compare ( "linear" ) == 0 ) return tex_filter::linear;

        if ( filter.compare ( "nearest" ) == 0 ) return tex_filter::nearest;

        throw std::exception();
    }

    std::string _to_string ( const vid_aspect& aspect ) {
        switch ( aspect ) {
        case vid_aspect::custom: return "custom";

        case vid_aspect::original: return "original";

        case vid_aspect::stretch: return "stretch";

        case vid_aspect::zoom: return "zoom";
        }
    }

    vid_aspect _to_vid_aspect ( const std::string& aspect ) {
        if ( aspect.compare ( "custom" ) == 0 ) return vid_aspect::custom;

        if ( aspect.compare ( "original" ) == 0 ) return vid_aspect::original;

        if ( aspect.compare ( "stretch" ) == 0 ) return vid_aspect::stretch;

        if ( aspect.compare ( "zoom" ) == 0 ) return vid_aspect::zoom;

        throw std::exception();
    }

    void _insert ( map_t&                          map,
                   const std::vector<std::string>& path,
                   const std::string&              value ) {
        map.insert ( common::str::join ( path, "." ), value );
    }

    void _insert_all ( map_t&                          map,
                       const std::vector<std::string>& path,
                       const std::vector<std::string>& values ) {
        const std::string map_path = common::str::join ( path, "." ) + ".";
        int index                  = 0;

        for ( const auto& val : values ) {
            map.insert ( map_path + std::to_string ( index ), val );
            index++;
        }
    }
};

#endif // ifndef LIBSHIMMER_CONFIGURATION_H
