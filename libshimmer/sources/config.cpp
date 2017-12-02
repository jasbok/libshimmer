#include "config.h"

#include "file_reader.h"

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
        }
        else {
            std::cout << "Unable to find config file: "
                      << env.config_path()
                      << "\nCreating default config.\n";

            save();
        }

        opts.set_env ( env );
    }
    catch ( json::exception ex ) {
        std::cerr << "Unable to parse config file (" << env.config_path()
                  << "): " << ex.what() << std::endl;
    }
    catch ( exception ex ) {
        std::cerr << "Unable to parse config file (" << env.config_path()
                  << "): " << ex.what() << std::endl;
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
            std::cerr << "Could not open config file for writing: "
                      << env.config_path() << std::endl;
        }
    }
    catch ( exception ex ) {
        std::cerr << "Unable to write config to file ("
                  << env.config_path() << "): "
                  << ex.what() << std::endl;
    }
}
}
