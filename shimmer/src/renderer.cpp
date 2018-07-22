#include "renderer.h"

#include "common/env.h"
#include "common/file.h"
#include "common/str.h"

#include "glpp/debug.h"
#include "glpp/shader.h"
#include "glpp/shapes.h"
#include "glpp/vertex_attrib.h"
#include "glpp/viewport.h"

#include "shimmer/video.h"

namespace shimmer
{
void renderer::init() {
    glewExperimental = GL_TRUE;
    GLenum glew_err = glewInit();

    if ( glew_err ) {
        printf ( "Error) Unable to initialise GLEW: %s\n",
                 glewGetErrorString ( glew_err ) );
    }
}

renderer::renderer( struct config::config* conf )
    : _conf ( conf ),
      _flip_target ( false )
{
    _define_program ( _source_program,
                      _conf->video.shader.vertex,
                      _conf->video.shader.fragment,
                      1 );

    _define_program ( _target_program,
                      "default.vert",
                      "default.frag",
                      2 );

    _define_vbo ( _source_vbo,
                  glpp::shapes::quad()
                      .flip_y ( _flip_target )
                      .position_texcoord() );

    _define_ebo ( _source_ebo, glpp::shapes::quad::triangle_fan_indices );

    _define_vbo ( _target_vbo,
                  _shape_position_texcoords() );

    _define_ebo ( _target_ebo,
                  _shape_indices() );

    _define_vao ( _source_vao,
                  _source_vbo,
                  _source_ebo,
                  _source_program );

    _define_vao ( _target_vao,
                  _target_vbo,
                  _target_ebo,
                  _target_program );

    if ( _conf->video.filter == config::video::filter::linear ) {
        _texture_filter = glpp::texture_2d::filter::linear;
    }
    else {
        _texture_filter = glpp::texture_2d::filter::nearest;
    }
}

void renderer::source_resolution ( const common::dims_2u& dims ) {
    _source_resolution       = dims;
    _intermediate_resolution = dims * _conf->video.shader.scale;

    _calculate_aspect();
    _define_vbo ( _source_vbo,
                  glpp::shapes::quad()
                      .flip_y ( _flip_target )
                      .position_texcoord() );

    _define_texture ( _source_tex,
                      _source_resolution,
                      glpp::texture_2d::filter::nearest,
                      1 );
    _source_fbo.bind().attach_color ( _source_tex );

    _define_texture ( _target_tex,
                      _intermediate_resolution,
                      _texture_filter,
                      2 );
    _target_fbo.bind().attach_color ( _target_tex ).unbind();
}

void renderer::target_resolution ( const common::dims_2u& dims )
{
    _target_resolution = dims;
    _calculate_aspect();

    _define_vbo ( _target_vbo,
                  _shape_position_texcoords() );
}

void renderer::render() {
    GLPP_CHECK_ERROR ( "PRE RENDER" );
    GLPP_CHECK_FRAMEBUFFER ( "PRE RENDER" );

    _target_fbo.bind();
    GLPP_CHECK_ERROR ( "RENDERER: Bound target FBO" );

    glpp::viewport ( _intermediate_resolution );

    _source_program.use();
    _source_vao.bind();

    glClear ( GL_COLOR_BUFFER_BIT );
    glDrawElements ( GL_TRIANGLE_FAN,
                     static_cast<GLint>( _source_ebo.elements() ),
                     GL_UNSIGNED_INT,
                     nullptr );
    GLPP_CHECK_ERROR ( "RENDERER: Drew source entity." );

    _target_fbo.unbind();
    GLPP_CHECK_ERROR ( "RENDERER: Unbound target FBO" );

    glpp::viewport ( _target_resolution );

    _target_program.use();
    _target_vao.bind();

    glClear ( GL_COLOR_BUFFER_BIT );
    glDrawElements ( GL_TRIANGLE_FAN,
                     static_cast<GLint>( _target_ebo.elements() ),
                     GL_UNSIGNED_INT,
                     nullptr );
    GLPP_CHECK_ERROR ( "RENDERER: Drew target entity." );

    _target_program.unbind();

    GLPP_CHECK_ERROR ( "POST RENDER" );
    GLPP_CHECK_FRAMEBUFFER ( "POST RENDER" );
}

void renderer::capture_fbo() {
    _source_fbo.bind();
    glpp::viewport ( _source_resolution );
}

void renderer::reset_fbo() {
    _source_fbo.unbind();
    glpp::viewport ( _target_resolution );
}

void renderer::activate_source_texture_unit()
{
    glpp::texture::active_texture ( 1 );
}

void renderer::setup_viewport()
{
    glpp::viewport ( _target_resolution );
}

void renderer::copy_source ( uint8_t*               data,
                             const common::dims_2u& dims,
                             unsigned int           channels )
{
    _source_tex.bind();
    _source_tex.sub_image ( data, dims, channels );
}

void renderer::flip_target ( bool flip )
{
    _flip_target = flip;
    _define_vbo ( _source_vbo,
                  glpp::shapes::quad()
                      .flip_y ( _flip_target )
                      .position_texcoord() );
}

void renderer::_define_program ( glpp::program&     program,
                                 const std::string& vertex,
                                 const std::string& fragment,
                                 int                texture_unit ) {
    printf ( "[DEBUG] Creating program...\n" );

    const auto& shader_dirs = _conf->general.shader_dirs;

    auto vs_file = common::file::find ( vertex, shader_dirs );
    auto fs_file = common::file::find ( fragment, shader_dirs  );

    auto vs_source = common::file::read_all ( vs_file );
    auto fs_source = common::file::read_all ( fs_file );

    auto vs = glpp::shader::create().vertex ( vs_source );
    auto fs = glpp::shader::create().fragment ( fs_source );

    vs.compile_and_throw();
    fs.compile_and_throw();

    program.attach ( vs )
        .attach ( fs )
        .link_and_throw()
        .detach ( vs )
        .detach ( fs );

    program.use()
        .uniform ( "application", texture_unit )
        .unbind();

    GLPP_CHECK_ERROR ( "Created Program" );
}

void renderer::_define_vbo ( glpp::vbo&                vbo,
                             const std::vector<float>& data ) {
    printf ( "[DEBUG] Creating VBO...\n" );

    vbo.bind()
        .data ( data )
        .unbind();

    GLPP_CHECK_ERROR ( "Created VBO" );
}

void renderer::_define_ebo ( glpp::ebo&                      ebo,
                             const std::vector<unsigned int> indices ) {
    printf ( "[DEBUG] Creating ebo...\n" );

    ebo.bind()
        .data ( indices )
        .unbind();

    GLPP_CHECK_ERROR ( "Created EBO" );
}

void renderer::_define_vao ( glpp::vao&     vao,
                             glpp::vbo&     vbo,
                             glpp::ebo&     ebo,
                             glpp::program& program )
{
    printf ( "[DEBUG] Defining VAO...\n" );

    vao.bind();
    vbo.bind();
    ebo.bind();

    program.use();
    auto position_location = program.attribute_location ( "position" );
    auto texcoord_location = program.attribute_location ( "texcoord" );

    printf ( "[DEBUG] position location: %i\n", position_location );
    printf ( "[DEBUG] texcoord location: %i\n", texcoord_location );

    auto attribs = glpp::vertex_attrib_builder<float>::sequential ( {
            { "position", 2, position_location },
            { "texcoord", 2, texcoord_location }
        } );

    attribs[0].define_pointer().enable_array();
    attribs[1].define_pointer().enable_array();

    program.unbind();
    vao.unbind();
    vbo.unbind();
    ebo.unbind();

    GLPP_CHECK_ERROR ( "Defined VAO" );
}

void renderer::_define_texture ( glpp::texture_2d&        tex,
                                 const common::dims_2u&   dims,
                                 glpp::texture_2d::filter filter,
                                 unsigned int             texture_unit ) {
    printf ( "[DEBUG] Creating texture...\n" );
    printf ( "[DEBUG] Texture size: %s\n", dims.to_json().c_str() );

    glpp::texture::active_texture ( texture_unit );
    tex.bind();
    tex.image ( glpp::texture_2d::internal_format::rgb, dims )
        .generate_mipmaps()
        .wrap ( glpp::texture_2d::texture_wrap::clamp_to_edge )
        .filters ( filter );

    glpp::texture::active_texture ( 0 );

    GLPP_CHECK_ERROR ( "Created TEXTURE" );
}

void renderer::_calculate_aspect()
{
    _aspect = video::aspect_transform ( _source_resolution,
                                        _target_resolution,
                                        *_conf );
}

std::vector<float> renderer::_shape_position_texcoords()
{
    typedef enum config::video::shape::type type;
    auto& shape = _conf->video.shape;

    switch ( shape.type ) {
    case type::lens:

        return glpp::shapes::lens()
                   .dims ( _aspect )
                   .curve_factor ( shape.lens.curve )
                   .curve_detail ( shape.lens.quality )
                   .position_texcoord();

    case type::rectangle:

        return glpp::shapes::quad()
                   .dims ( _aspect )
                   .position_texcoord();
    }

    throw std::exception();
}

std::vector<unsigned int> renderer::_shape_indices()
{
    typedef enum config::video::shape::type type;
    auto& shape = _conf->video.shape;

    switch ( shape.type ) {
    case type::lens:

        return glpp::shapes::lens()
                   .curve_factor ( shape.lens.curve )
                   .curve_detail ( shape.lens.quality )
                   .indices();

    case type::rectangle:

        return glpp::shapes::quad().triangle_fan_indices;
    }

    throw std::exception();
}
} // namespace shimmer
