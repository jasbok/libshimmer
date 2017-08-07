#include "gl_material.h"

using namespace shimmer;
using namespace std;

gl_material::gl_material(
    const std::shared_ptr<gl_program>&              program,
    const std::vector<std::shared_ptr<gl_texture>>& textures )
    :  _program ( program ),
       _textures ( textures ),
       _inputs(),
       _uniforms()
{
    _process_variables ( program->variables() );
    _bind_textures();
}

gl_material::~gl_material() {}

void shimmer::gl_material::use()
{
    _program->use();

    auto texture_unit = GL_TEXTURE0;

    for ( const auto& texture : _textures ) {
        glActiveTexture ( texture_unit++ );
        texture->bind();
    }
}

void gl_material::_process_variables (
    const std::vector<glsl_variable>& variables ) {
    for ( const auto& var : variables ) {
        switch ( var.qualifier() ) {
        case glsl::qualifier::ATTRIBUTE:
        case glsl::qualifier::INPUT:
            _add_input ( var );
            break;

        case glsl::qualifier::UNIFORM:
            _add_uniform ( var );

            if ( var.type() == glsl::type::SAMPLER2D ) {
                _add_sampler2d ( var );
            }
            break;

        default:
            break;
        }
    }
}

void gl_material::_add_input ( const glsl_variable& variable )
{
    auto location = _program->attribute_location ( variable.name() );

    if ( location >= 0 ) {
        _inputs.emplace ( variable.name(),
                          gl_program_variable ( variable, location ) );
    }
}

void gl_material::_add_uniform ( const glsl_variable& variable )
{
    auto location = _program->uniform_location ( variable.name() );

    if ( location >= 0 ) {
        _uniforms.emplace ( variable.name(),
                            gl_program_variable ( variable, location ) );
    }
}

void gl_material::_add_sampler2d ( const glsl_variable& variable ) {
    auto location = _program->uniform_location ( variable.name() );

    _sampler2ds.push_back ( gl_program_variable ( variable, location ) );
}

void gl_material::_bind_textures() {
    std::vector<std::shared_ptr<gl_texture>> active_textures;
    std::vector<gl_program_variable> active_sampler2ds;
    unsigned int min = std::min ( _textures.size(), _sampler2ds.size() );

    _program->use();

    for ( unsigned int i = 0; i < min; i++ ) {
        if ( _sampler2ds[i].location() >=  0 ) {
            active_sampler2ds.push_back ( _sampler2ds[i] );
            active_textures.push_back ( _textures[i] );
            _program->set_sampler ( _sampler2ds[i].name(), i );
        }
    }

    _textures   = active_textures;
    _sampler2ds = active_sampler2ds;
}
