#ifndef LIBSHIMMER_CONFIGURATION_H
#define LIBSHIMMER_CONFIGURATION_H

#include "config_variables.h"

#include "common/dims.h"

#include <sstream>
#include <unordered_map>
#include <vector>

namespace shimmer
{
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

    config_mapper( config* conf );

    virtual ~config_mapper() = default;

    std::string to_json ( const struct config::general::logging& logging );

    std::string to_json ( const struct config::general& general );

    std::string to_json ( const struct config::input& input );

    std::string to_json ( const struct config::video::shader& shader );

    std::string to_json ( const struct config::video::limiter& limiter );

    std::string to_json ( const struct config::video& video );

    std::string to_json ( const struct config& config );

    void        apply ( const map_t& map );

    std::string to_json();

    struct mapping_exception : public std::runtime_error {
        mapping_exception( const std::string&              value,
                           const std::vector<std::string>& path,
                           const std::string&              expected );

        mapping_exception( const std::string&              value,
                           const std::vector<std::string>& path,
                           const std::vector<std::string>& expected );

        virtual ~mapping_exception() = default;
    };

private:
    config* _conf;

    typedef enum config::general::logging::level  log_level;
    typedef enum config::general::logging::output log_output;
    typedef enum config::video::filter            tex_filter;
    typedef enum config::video::aspect            vid_aspect;

    std::string _to_string ( const log_level& level );

    log_level   _to_log_level ( const std::string& level );

    std::string _to_string ( const log_output& output );

    log_output  _to_log_output ( const std::string& output );

    std::string _to_string ( const tex_filter& filter );

    tex_filter  _to_tex_filter ( const std::string& filter );

    std::string _to_string ( const vid_aspect& aspect );

    vid_aspect  _to_vid_aspect ( const std::string& aspect );

    void        _insert ( map_t&                          map,
                          const std::vector<std::string>& path,
                          const std::string&              value );

    void _insert_all ( map_t&                          map,
                       const std::vector<std::string>& path,
                       const std::vector<std::string>& values );

    void _set_property ( const std::pair<std::string, std::string>& property );
};
}

#endif // ifndef LIBSHIMMER_CONFIGURATION_H
