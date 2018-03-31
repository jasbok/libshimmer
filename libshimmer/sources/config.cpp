#include "config.h"

#include "file_reader.h"
#include "logger.h"

#include <iostream>

namespace shimmer
{
config::config( event_connector& connector )
    : _connector ( &connector )
{}

void config::load()
{
    using json = nlohmann::json;

    try {
        std::ifstream fstream ( env.config_path() );

        if ( fstream.is_open() ) {
            json options_json;
            fstream >> options_json;

            LOGI << "Loaded config from file: " << env.config_path();
            LOGD << std::setw ( 4 ) << options_json;
            opts = options_json;
        }
        else {
            LOGW << "Unable to find config file: " << env.config_path();
            LOGW << "Creating default config.";
            save();
        }

        opts.set_env ( env );
        general ( opts.general );
        video ( opts.video );
    }
    catch ( json::exception ex ) {
        LOGE << "Unable to parse config file (" << env.config_path() << "): "
             << ex.what();
    }
    catch ( std::exception ex ) {
        LOGE << "Unable to parse config file (" << env.config_path() << "): "
             << ex.what();
    }
}

void config::save() const
{
    try {
        std::ofstream fstream ( env.config_path() );

        if ( fstream.is_open() ) {
            using json = nlohmann::json;
            json options_json = opts;
            fstream << std::setw ( 4 ) << options_json;
        }
        else {
            LOGE << "Could not open config file for writing: "
                 << env.config_path();
        }
    }
    catch ( std::exception ex ) {
        LOGE << "Unable to write config to file (" << env.config_path() << "): "
             << ex.what();
    }
}

const general_options& config::general() const {
    return _general;
}

const video_options& config::video() const {
    return _video;
}

config& config::general ( const general_options& general ) {
    _general = general;
    _connector->send ( general_options_change ( _general ) );

    return *this;
}

config& config::video ( const video_options& video ) {
    _video = video;
    _connector->send ( video_options_change ( _video ) );

    return *this;
}
}
