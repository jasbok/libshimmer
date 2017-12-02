#include "shader_reader.h"

using namespace shimmer;
using namespace std;

shader_reader::shader_reader( const std::vector<string>& paths )
    : file_reader ( paths )
{}

glpp::shader shader_reader::shader ( const string&           path,
                                     enum glpp::shader::type type ) const
{
    glpp::shader shader ( type, read_str ( path ) );

    if ( shader.compile().compile_status() ) return shader;

    throw shader_read_exception ( "Unable to compile shader:\n"
                                  + shader.info_log() );
}

glpp::shader shader_reader::fragment_shader ( const string& path ) const
{
    return shader ( path, glpp::shader::type::fragment );
}

glpp::shader shader_reader::vertex_shader ( const string& path ) const
{
    return shader ( path, glpp::shader::type::vertex );
}

glpp::program shader_reader::program ( const string& vertex_path,
                                       const string& fragment_path ) const
{
    auto vertex   = vertex_shader (  vertex_path );
    auto fragment = fragment_shader (  fragment_path );

    glpp::program program;
    program.attach ( vertex )
        .attach ( fragment )
        .link()
        .detach ( vertex )
        .detach ( fragment );

    if ( program.link_status() ) {
        return program;
    }

    throw program_read_exception ( "Unable to link read program:\n"
                                   + program.info_log() );
}

shared_ptr<glpp::program> shader_reader::shared_program (
    const string& vertex_path,
    const string& fragment_path ) const
{
    return std::make_shared<glpp::program>( program ( vertex_path,
                                                      fragment_path ) );
}
