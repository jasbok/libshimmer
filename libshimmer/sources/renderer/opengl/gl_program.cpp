#include "gl_program.h"

using namespace shimmer;
using namespace std;

gl_program::gl_program(
    GLuint                            handle,
    const std::vector<glsl_variable>& variables )
    : _handle ( handle ),
      _variables ( variables )
{}

gl_program::~gl_program()
{
    glDeleteProgram ( _handle );
}

void gl_program::bind() const
{
    glUseProgram ( _handle );
}

void gl_program::unbind() const
{
    glUseProgram ( 0 );
}

GLint gl_program::attribute_location ( const std::string& name ) const {
    return glGetAttribLocation ( _handle, name.c_str() );
}

GLint gl_program::uniform_location ( const std::string& name ) const {
    return glGetUniformLocation ( _handle, name.c_str() );
}

void gl_program::set_sampler ( const std::string& name,
                               int                value ) {
    glUniform1i ( uniform_location ( name ), value );
}

void gl_program::bind_samplers()
{
    auto sampler2ds = variables ( { glsl::type::SAMPLER2D } );

    for ( unsigned int i = 0; i < sampler2ds.size(); i++ ) {
        if ( sampler2ds[i].location() >= 0 ) {
            set_sampler ( sampler2ds[i].name(), i );
        }
    }
}

vector<gl_program_variable> gl_program::variables (
    const vector<glsl::qualifier>& qualifiers )
{
    vector<gl_program_variable> filtered;

    for ( auto var : variables() ) {
        for ( auto qualifier : qualifiers ) {
            if ( var.qualifier() == qualifier ) {
                auto location = uniform_location ( var.name() );
                filtered.push_back ( gl_program_variable ( var, location ) );
                break;
            }
        }
    }

    return filtered;
}

vector<gl_program_variable> gl_program::variables (
    const vector<glsl::type>& types )
{
    vector<gl_program_variable> filtered;

    for ( auto var : variables() ) {
        for ( auto type : types ) {
            if ( var.type() == type ) {
                auto location = uniform_location ( var.name() );
                filtered.push_back ( gl_program_variable ( var, location ) );
                break;
            }
        }
    }

    return filtered;
}
