#include "shader.h"

#include <vector>

using namespace glpp;
using namespace std;

shader::shader( enum type     type,
                const string& source )
    : _handle ( glCreateShader ( static_cast<GLenum>( type ) ) ),
      _type ( type ),
      _source ( source )
{}

shader::shader( shader&& move )
    : _handle ( move._handle ),
      _type ( move._type ),
      _source ( std::move ( move._source ) )
{
    move._handle = 0;
}

shader::~shader() {
    glDeleteShader ( _handle );
}

shader& shader::operator=( shader&& move ) {
    glDeleteShader ( _handle );

    _handle = move._handle;
    _type   = move._type;
    _source = std::move ( move._source );

    move._handle = 0;

    return *this;
}

GLuint shader::handle() const {
    return _handle;
}

enum shader::type shader::type() const {
    return _type;
}

string shader::source() const {
    return _source;
}

shader& shader::compile() {
    const GLchar* shader_source_gl = _source.c_str();

    glShaderSource ( _handle, 1, &shader_source_gl, nullptr );
    glCompileShader ( _handle );

    return *this;
}

bool shader::compile_status() const {
    GLint success;

    glGetShaderiv ( _handle, GL_COMPILE_STATUS, &success );

    return success;
}

string shader::info_log ( size_t size ) const {
    vector<GLchar> buffer ( size );
    glGetShaderInfoLog ( _handle, size, nullptr, &buffer[0] );

    return string ( &buffer[0] );
}

shader& shader::compile_and_throw ( size_t log_size ) {
    if ( compile().compile_status() ) return *this;

    throw compile_exception ( _source, info_log ( log_size ) );
}

shader::builder shader::create() {
    return builder();
}

shader shader::builder::compute ( const string& source ) {
    return shader ( type::compute, source );
}

shader shader::builder::fragment ( const string& source ) {
    return shader ( type::fragment, source );
}

shader shader::builder::geometry ( const string& source ) {
    return shader ( type::geometry, source );
}

shader shader::builder::tess_control ( const string& source ) {
    return shader ( type::tess_control, source );
}

shader shader::builder::tess_evaluation ( const string& source ) {
    return shader ( type::tess_evaluation, source );
}

shader shader::builder::vertex ( const string& source ) {
    return shader ( type::vertex, source );
}

shader::compile_exception::compile_exception( const string& source,
                                              const string& log )
    : runtime_error (
          std::string ( "Failed to compile shader." )
          + std::string ( "\nSource: " ) + source
          + std::string ( "\nLog: " ) + log )
{}

shader::compile_exception::~compile_exception() {}
