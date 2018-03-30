#include "config.h"

#include "file_reader.h"
#include "logger.h"

#include <iostream>

using json = nlohmann::json;
using namespace std;

namespace shimmer
{
config::config() {
    using json = nlohmann::json;

    try {
        ifstream fstream ( env.config_path() );

        if ( fstream.is_open() ) {
            json options_json;
            fstream >> options_json;
            opts = options_json;

            LOGI << "Loaded config from file: " << env.config_path();
        }
        else {
            LOGW << "Unable to find config file: " << env.config_path()
                 << "\nCreating default config.\n";

            save();
        }

        opts.set_env ( env );
    }
    catch ( json::exception ex ) {
        LOGE << "Unable to parse config file (" << env.config_path() << "): "
             << ex.what();
    }
    catch ( exception ex ) {
        LOGE << "Unable to parse config file (" << env.config_path() << "): "
             << ex.what();
    }
}

void config::save() const
{
    try {
        ofstream fstream ( env.config_path() );

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
    catch ( exception ex ) {
        LOGE << "Unable to write config to file (" << env.config_path() << "): "
             << ex.what();
    }
}
}
