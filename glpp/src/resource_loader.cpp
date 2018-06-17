#include "resource_loader.h"

#include "pixels.h"
#include "shader.h"

#include "common/file.h"
#include "common/img.h"

#include <fstream>
#include <iostream>

using namespace glpp;
using namespace std;

resource_loader::resource_loader()
    : _search_paths { "", "." }
{}

resource_loader::resource_loader( const std::vector<string>& paths )
    : _search_paths { "", "." }
{
    _search_paths.insert ( _search_paths.end(), paths.begin(), paths.end() );
}

resource_loader& resource_loader::search_paths ( const vector<string>& paths )
{
    _search_paths = { "", "." };
    _search_paths.insert ( _search_paths.end(), paths.begin(), paths.end() );

    return *this;
}

std::vector<string> resource_loader::search_paths() const
{
    return _search_paths;
}

string resource_loader::file_contents ( const string& path ) const
{
    for ( const auto& search_path : _search_paths ) {
        ifstream fstream ( search_path + "/" + path );

        if ( fstream.is_open() ) {
            return string ( std::istreambuf_iterator<char>( fstream ), {} );
        }
    }

    std::cerr << "Could not read file: " << path << std::endl;
    throw file_read_exception();
}

shader resource_loader::fragment_shader ( const string& path ) const
{
    shader fragment ( shader::type::fragment, file_contents ( path ) );

    if ( !fragment.compile().compile_status() ) {
        std::cerr << path << ") "
                  << "Unable to compile fragment shader:\n"
                  << fragment.info_log()
                  << std::endl;

        throw shader_compile_exception();
    }

    return fragment;
}

shader resource_loader::vertex_shader ( const string& path ) const
{
    shader vertex ( shader::type::vertex, file_contents ( path ) );

    if ( !vertex.compile().compile_status() ) {
        std::cerr << path << ") "
                  << "Unable to compile vertex shader:\n"
                  << vertex.info_log()
                  << std::endl;

        throw shader_compile_exception();
    }

    return vertex;
}

class program resource_loader::program (
        const string& vertex_shader_path,
        const string& fragment_shader_path ) const
{
    auto vertex   = vertex_shader ( vertex_shader_path );
    auto fragment = fragment_shader ( fragment_shader_path );

    class program program;
    program.attach ( vertex )
        .attach ( fragment )
        .link()
        .detach ( vertex )
        .detach ( fragment );

    if ( !program.link_status() ) {
        std::cerr << "Unable to link shaders into program:\n"
                  << program.info_log()
                  << std::endl;

        throw program_link_exception();
    }

    return program;
}

std::shared_ptr<class program> resource_loader::shared_program (
    const string& vertex_shader_path,
    const string& fragment_shader_path ) const
{
    return std::make_shared<class program>( program ( vertex_shader_path,
                                                      fragment_shader_path ) );
}

common::img::image resource_loader::image ( const string& path ) const
{
    return common::img::read ( common::file::find ( path, _search_paths ) );
}
