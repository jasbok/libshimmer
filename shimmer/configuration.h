#ifndef LIBSHIMMER_CONFIGURATION_H
#define LIBSHIMMER_CONFIGURATION_H

#include "config_variables.h"

#include "common/dims.h"
#include "common/json.h"

#include <unordered_map>
#include <vector>

namespace shimmer
{
struct config {
    typedef std::pair<std::string, std::string> property;

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
            std::string  vertex   = "default.vert";
            std::string  fragment = "default.frag";
            unsigned int scale    = 1;
        };
        struct shader shader;

        enum class filter {
            linear,
            nearest
        };
        enum filter filter = filter::nearest;

        enum class aspect {
            custom,
            original,
            stretch,
            zoom
        };
        enum aspect aspect = aspect::original;

        common::dims_2u custom_aspect = { 16, 9 };

        struct limiter {
            unsigned int rate    = 0;
            unsigned int samples = 5;
        };
        struct limiter limiter;

        struct shape {
            enum class type {
                lens,
                rectangle
            };
            enum type type = type::rectangle;

            struct lens {
                unsigned int quality = 32;
                float        curve   = 0.1f;
            };
            struct lens lens;
        };
        struct shape shape;
    };
    struct video video;

    struct mapping_exception : public std::runtime_error {
        mapping_exception( const std::string&              property,
                           const std::string&              value,
                           const std::vector<std::string>& expected );

        virtual ~mapping_exception() = default;
    };

    /**
     * @brief merge Attempts to merge config a into b.
     * @param a The source json config object.
     * @param b The destination json config object.
     * @return The merged json config object.
     */
    static  nlohmann::json merge ( const nlohmann::json& a,
                                   const nlohmann::json& b );

    /**
     * @brief from_environment Loads all config properties set through
     * environment variables.
     * @return A map of all properties set through the environment.
     */
    static nlohmann::json from_environment();

    /**
     * @brief from_file Loads all config properties set through the given config
     * file.
     * @param path Path to the config file to load.
     * @return A map of all properties set through in the config file.
     */
    static nlohmann::json from_file ( const std::string& path );

    /**
     * @brief create Creates a new config by merging the default config with
     * properties set in the environment and through a config file.
     * @return The merged config.
     */
    static config create();
};

std::string to_string ( const enum config::logging::level& level );

std::string to_string ( const enum config::logging::output& output );

std::string to_string ( const enum config::video::filter& filter );

std::string to_string ( const enum config::video::aspect& aspect );

std::string to_string ( const enum config::video::shape::type& shape );


void from_string ( enum config::logging::level& level,
                   const std::string&           str );

void from_string ( enum config::logging::output& output,
                   const std::string&            str );

void from_string ( enum config::video::filter& filter,
                   const std::string&          str );

void from_string ( enum config::video::aspect& aspect,
                   const std::string&          str );

void from_string ( enum config::video::shape::type& shape,
                   const std::string&               str );


void to_json ( nlohmann::json&      json,
               const struct config& config );

void from_json ( const nlohmann::json& json,
                 struct config&        config );

void to_json ( nlohmann::json&               json,
               const struct config::general& general );

void from_json ( const nlohmann::json&   json,
                 struct config::general& general );

void to_json ( nlohmann::json&             json,
               const struct config::input& input );

void from_json ( const nlohmann::json& json,
                 struct config::input& input );

void to_json ( nlohmann::json&               json,
               const struct config::logging& logging );

void from_json ( const nlohmann::json&   json,
                 struct config::logging& logging );

void to_json ( nlohmann::json&                    json,
               const enum config::logging::level& level );

void from_json ( const nlohmann::json&        json,
                 enum config::logging::level& level );

void to_json ( nlohmann::json&                     json,
               const enum config::logging::output& output );

void from_json ( const nlohmann::json&         json,
                 enum config::logging::output& output );

void to_json ( nlohmann::json&             json,
               const struct config::video& video );

void from_json ( const nlohmann::json& json,
                 struct config::video& video );

void to_json ( nlohmann::json&                   json,
               const enum config::video::aspect& aspect );

void from_json ( const nlohmann::json&       json,
                 enum config::video::aspect& aspect );

void to_json ( nlohmann::json&                   json,
               const enum config::video::filter& filter );

void from_json ( const nlohmann::json&       json,
                 enum config::video::filter& filter );

void to_json ( nlohmann::json&                      json,
               const struct config::video::limiter& limiter );

void from_json ( const nlohmann::json&          json,
                 struct config::video::limiter& limiter );

void to_json ( nlohmann::json&                     json,
               const struct config::video::shader& shader );

void from_json ( const nlohmann::json&         json,
                 struct config::video::shader& shader );

void to_json ( nlohmann::json&                    json,
               const struct config::video::shape& shape );

void from_json ( const nlohmann::json&        json,
                 struct config::video::shape& shape );

void to_json ( nlohmann::json&                          json,
               const struct config::video::shape::lens& lens );

void from_json ( const nlohmann::json&              json,
                 struct config::video::shape::lens& lens );

void to_json ( nlohmann::json&                        json,
               const enum config::video::shape::type& type );

void from_json ( const nlohmann::json&            json,
                 enum config::video::shape::type& type );
}

namespace common
{
template<typename T>
void to_json ( nlohmann::json&          json,
               const common::dims_2<T>& dims ) {
    json = {
        { "width",  dims.width  },
        { "height", dims.height }
    };
}

template<typename T>
void from_json ( const nlohmann::json& json,
                 common::dims_2<T>&    dims ) {
    if ( common::json::exists ( json, { "width" } ) ) {
        dims.width = json.at ( "width" );
    }

    if ( common::json::exists ( json, { "height" } ) ) {
        dims.height = json.at ( "height" );
    }
}
}

#endif // ifndef LIBSHIMMER_CONFIGURATION_H
