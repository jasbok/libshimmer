#include "shader.h"

#include <vector>

using namespace glpp;
using namespace std;

GLenum glEnumFrom ( shader_type type ) {
    switch ( type ) {
    case shader_type::fragment:

        return GL_FRAGMENT_SHADER;

    case shader_type::vertex:

        return GL_VERTEX_SHADER;
    }

    return 0;
}

shader::shader( shader_type   type,
                const string& source )
    : _handle ( glCreateShader ( glEnumFrom ( type ) ) ),
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
    _handle = move._handle;
    _type   = move._type;
    _source = std::move ( move._source );

    move._handle = 0;

    return *this;
}

GLuint shader::handle() const {
    return _handle;
}

shader_type shader::type() const {
    return _type;
}

string shader::source() const {
    return _source;
}

void shader::compile() {
    const GLchar* shader_source_gl = _source.c_str();

    glShaderSource ( _handle, 1, &shader_source_gl, nullptr );
    glCompileShader ( _handle );
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
