#ifndef GLPP_RESOURCE_LOADER_H
#define GLPP_RESOURCE_LOADER_H

#include "program.h"
#include "texture_2d.h"

#include <exception>

namespace glpp
{
class resource_loader
{
public:
    resource_loader();

    explicit resource_loader( const std::vector<std::string>& paths );

    virtual ~resource_loader() = default;


    resource_loader& search_paths (
        const std::vector<std::string>& paths );

    std::vector<std::string> search_paths() const;


    std::string   file_contents ( const std::string& path ) const;

    shader        fragment_shader ( const std::string& path ) const;

    shader        vertex_shader ( const std::string& path ) const;

    class program program ( const std::string& vertex_shader_path,
                            const std::string& fragment_shader_path ) const;

    std::shared_ptr<class program> shared_program (
        const std::string& vertex_shader_path,
        const std::string& fragment_shader_path ) const;

private:
    std::vector<std::string> _search_paths;
};

struct file_read_exception : public std::exception {
    const char* what() {
        return "Could not read file.";
    }
};

struct shader_compile_exception : public std::exception {
    const char* what() {
        return "Could not compile shader.";
    }
};

struct program_link_exception : public std::exception {
    const char* what() {
        return "Could not link program.";
    }
};
}

#endif // ifndef GLPP_RESOURCE_LOADER_H
