#ifndef LIBSHIMMER_CONFIGURATION_H
#define LIBSHIMMER_CONFIGURATION_H

#include "config_variables.h"

#include "common/dims.h"

#include <unordered_map>
#include <vector>

namespace shimmer
{
struct config {
    typedef std::pair<std::string, std::string>          property;
    typedef std::unordered_map<std::string, std::string> properties;

    struct general {
        std::vector<std::string> config_dirs = shimmer::system::config_dirs;
        std::vector<std::string> data_dirs   = shimmer::system::data_dirs;
        std::vector<std::string> font_dirs   = shimmer::system::font_dirs;
        std::vector<std::string> image_dirs  = shimmer::system::image_dirs;
        std::vector<std::string> shader_dirs = shimmer::system::shader_dirs;
    };
    struct general general;

    struct input {
        bool grab = false;
    };
    struct input input;

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

    config& set_property ( const property& prop );

    config& set_properties ( const properties& props );

    struct mapping_exception : public std::runtime_error {
        mapping_exception( const property&    prop,
                           const std::string& expected );

        mapping_exception( const property&                 prop,
                           const std::vector<std::string>& expected );

        virtual ~mapping_exception() = default;
    };

    /**
     * @brief from_environment Loads all config properties set through
     * environment variables.
     * @return A map of all properties set through the environment.
     */
    static properties from_environment();

    /**
     * @brief from_file Loads all config properties set through the given config
     * file.
     * @param path Path to the config file to load.
     * @return A map of all properties set through in the config file.
     */
    static properties from_file ( const std::string& path );

    /**
     * @brief create Creates a new config by merging the default config with
     * properties set in the environment and through a config file.
     * @return The merged config.
     */
    static config create();
};

std::string to_json ( const struct config::logging& logging );
std::string to_json ( const struct config::general& general );
std::string to_json ( const struct config::input& input );
std::string to_json ( const struct config::video::shader& shader );
std::string to_json ( const struct config::video::limiter& limiter );
std::string to_json ( const struct config::video& video );
std::string to_json ( const struct config& config );

std::string to_string ( const enum config::logging::level& level );
std::string to_string ( const enum config::logging::output& output );
std::string to_string ( const enum config::video::filter& filter );
std::string to_string ( const enum config::video::aspect& aspect );


enum config::logging::level  to_log_level ( const std::string& level );
enum config::logging::output to_log_output ( const std::string& output );
enum config::video::filter   to_tex_filter ( const std::string& filter );
enum config::video::aspect   to_vid_aspect ( const std::string& aspect );
}

#endif // ifndef LIBSHIMMER_CONFIGURATION_H