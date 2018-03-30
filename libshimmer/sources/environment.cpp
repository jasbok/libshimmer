#include "environment.h"

#include "common/env.h"
#include "common/str.h"
#include "config_variables.h"

#include <cstdlib>

using namespace shimmer;
using namespace std;

const static string working_directory_evar = "PWD";

const static string home_evar = "HOME";

const static string cache_home_evar = "XDG_CACHE_HOME";

const static string config_home_evar = "XDG_CONFIG_HOME";

const static string data_home_evar = "XDG_DATA_HOME";

const static string pictures_dir_evar = "XDG_PICTURES_DIR";


const static string config_path_evar = "SHIMMER_CONFIG";

const static string config_paths_evar = "SHIMMER_CONFIGS";

const static string font_paths_evar = "SHIMMER_FONTS";

const static string image_paths_evar = "SHIMMER_IMAGES";

const static string shader_paths_evar = "SHIMMER_SHADERS";


const static string shimmer_directory = "/shimmer";

const static string paths_split_regex = ":";

const static string home_regex = "~|$HOME";


environment::environment()
    : _working_directory ( common::evar ( working_directory_evar, "." ) ),

      _home ( common::evar ( home_evar, _working_directory ) ),

      _cache_home ( common::evar ( cache_home_evar, _home + "/.cache" ) ),

      _config_home ( common::evar ( config_home_evar,
              _home + "/.config" ) ),

      _data_home ( common::evar ( config_home_evar,
              _home + "/.local/share" ) ),

      _pictures_directory (
          common::evar ( pictures_dir_evar, _home + "/Pictures" ) ),


      _config_path ( common::evar ( config_path_evar,
              _config_home + "/shimmer.config" ) ),

      _font_paths (
          _read_evar_paths ( font_paths_evar,
              { _data_home + shimmer_directory + "/fonts",
                SHIMMER_INSTALL_FONTS } ) ),

      _image_paths (
          _read_evar_paths ( image_paths_evar,
                             { _data_home + shimmer_directory + "/images",
                               _pictures_directory,
                               SHIMMER_INSTALL_IMAGES } ) ),

      _shader_paths (
          _read_evar_paths ( shader_paths_evar,
                             { _data_home + shimmer_directory + "/shaders",
                               SHIMMER_INSTALL_SHADERS } ) )
{}

string environment::working_directory() const
{
    return _working_directory;
}

string environment::home() const
{
    return _home;
}

string environment::cache_home() const
{
    return _cache_home;
}

string environment::config_home() const
{
    return _config_home;
}

string environment::data_home() const
{
    return _data_home;
}

string environment::config_path() const
{
    return _config_path;
}

std::vector<string> environment::font_paths() const
{
    return _font_paths;
}

std::vector<string> environment::image_paths() const
{
    return _image_paths;
}

std::vector<string> environment::shader_paths() const
{
    return _shader_paths;
}

std::vector<string> environment::_read_evar_paths (
    const string&                   evar,
    const std::vector<std::string>& defaultt ) const
{
    auto val   = common::evar ( evar, "" );
    auto paths = common::split ( val, regex ( paths_split_regex ) );

    paths.insert ( paths.end(), defaultt.begin(), defaultt.end() );

    return paths;
}

void environment::_expand ( string&       str,
                            const string& regex,
                            const string& expansion ) const
{
    smatch match;

    if ( regex_search ( str, match, std::regex ( regex ) )
         && ( match.position() > 0 ) ) {
        str.replace ( static_cast<unsigned long>( match.position() ),
                      match.size(),
                      expansion );
    }
}

void environment::_expand_all ( std::string& str ) const
{
    _expand ( str, home_regex, _home );
}
