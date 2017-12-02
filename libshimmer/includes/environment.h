#ifndef SHIMMER_ENVIRONMENT_H
#define SHIMMER_ENVIRONMENT_H

#include <regex>
#include <string>
#include <vector>

namespace shimmer
{
class environment
{
public:
    environment();

    virtual ~environment() = default;


    std::string working_directory() const;

    std::string home() const;

    std::string cache_home() const;

    std::string config_home() const;

    std::string data_home() const;


    std::string              config_path() const;

    std::vector<std::string> font_paths() const;

    std::vector<std::string> image_paths() const;

    std::vector<std::string> shader_paths() const;

private:
    std::string _working_directory;

    std::string _home;

    std::string _cache_home;

    std::string _config_home;

    std::string _data_home;

    std::string _pictures_directory;


    std::string _config_path;

    std::vector<std::string> _font_paths;

    std::vector<std::string> _image_paths;

    std::vector<std::string> _shader_paths;


    std::string _read_evar ( const std::string& evar,
                             const std::string& defaultt = std::string() ) const;

    std::vector<std::string> _split_str ( const std::string& str,
                                          const std::regex&  reg ) const;

    std::vector<std::string> _read_evar_paths (
        const std::string&              evar,
        const std::vector<std::string>& defaultt =
            std::vector<std::string>( ) ) const;

    void _expand ( std::string&       str,
                   const std::string& regex,
                   const std::string& expansion ) const;

    void _expand_all ( std::string& str ) const;
};
}

#endif // ifndef SHIMMER_ENVIRONMENT_H
