#include "renderer.h"

#include "shim.h"

#include "common/env.h"
#include "common/file.h"
#include "common/str.h"

#include "glpp/debug.h"
#include "glpp/shader.h"
#include "glpp/vertex_attrib.h"

#include "shimmer/video.h"

void renderer::init() {
    glewExperimental = GL_TRUE;
    GLenum glew_err = glewInit();

    if ( glew_err ) {
        printf ( "Error) Unable to initialise GLEW: %s\n",
                 glewGetErrorString ( glew_err ) );
    }
}

renderer::renderer( class shim* shim )
    : _shim ( shim )
{
    _create_program();
    _create_vbo();
    _create_ebo();
    _create_vao();

    if ( shim->config.video.filter == shimmer::config::video::filter::linear ) {
        _texture_filter = glpp::texture_2d::filter::linear;
    }
    else {
        _texture_filter = glpp::texture_2d::filter::nearest;
    }
}

void renderer::source_resolution ( const common::dims_2u& dims ) {
    _source_resolution = dims;
    _calculate_aspect();
    _create_vbo();

    _create_texture ( _source_resolution );
    _create_fbo();
}

void renderer::target_resolution ( const common::dims_2u& dims )
{
    _target_resolution = dims;
    _calculate_aspect();
    _create_vbo();
}

void renderer::render() {
    GLPP_CHECK_ERROR ( "PRE RENDER" );
    GLPP_CHECK_FRAMEBUFFER ( "PRE RENDER" );

    _fbo.unbind();

    glViewport ( 0,
                 0,
                 static_cast<GLint>( _target_resolution.width ),
                 static_cast<GLint>( _target_resolution.height ) );

    _prog.use();
    _vao.bind();

    glClear ( GL_COLOR_BUFFER_BIT );
    glDrawElements ( GL_TRIANGLES,
                     static_cast<GLint>( _ebo.elements() ),
                     GL_UNSIGNED_INT,
                     nullptr );

    _prog.unbind();

    GLPP_CHECK_ERROR ( "POST RENDER" );
    GLPP_CHECK_FRAMEBUFFER ( "POST RENDER" );
}

void renderer::capture() {
    _fbo.bind();

    glViewport ( 0, 0,
                 static_cast<GLsizei>( _tex.dims().width ),
                 static_cast<GLsizei>( _tex.dims().height ) );
}

void renderer::_create_program() {
    printf ( "[DEBUG] Creating program...\n" );

    const auto& shader      = _shim->config.video.shader;
    const auto& shader_dirs = _shim->config.general.shader_dirs;

    auto vs_file = common::file::find ( shader.vertex, shader_dirs );
    auto fs_file = common::file::find ( shader.fragment, shader_dirs  );

    auto vs_source = common::file::read_all ( vs_file );
    auto fs_source = common::file::read_all ( fs_file );

    auto vs = glpp::shader::create().vertex ( vs_source );
    auto fs = glpp::shader::create().fragment ( fs_source );

    vs.compile_and_throw();
    fs.compile_and_throw();

    _prog.attach ( vs )
        .attach ( fs )
        .link_and_throw()
        .detach ( vs )
        .detach ( fs );

    _prog.use()
        .uniform ( "application", 1 )
        .unbind();

    GLPP_CHECK_ERROR ( "Created Program" );
}

void renderer::_create_vbo() {
    printf ( "[DEBUG] Creating vbo...\n" );

    _vbo.bind()
        .data<float>( {
        // position   // texcoords // colour
        _aspect.width, _aspect.height, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,   // TR
        -_aspect.width, _aspect.height, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,  // TL
        -_aspect.width, -_aspect.height, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, // BL
        _aspect.width, -_aspect.height, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f   // BR
    } )
        .unbind();

    GLPP_CHECK_ERROR ( "Created VBO" );
}

void renderer::_create_ebo() {
    printf ( "[DEBUG] Creating ebo...\n" );

    _ebo.bind()
        .data ( {
        0, 1, 2,
        2, 3, 0
    } )
        .unbind();

    GLPP_CHECK_ERROR ( "Created EBO" );
}

void renderer::_create_vao()
{
    printf ( "[DEBUG] Creating vao...\n" );

    _vao.bind();
    _vbo.bind();
    _ebo.bind();

    _prog.use();
    auto position_location = _prog.attribute_location ( "position" );
    auto texcoord_location = _prog.attribute_location ( "texcoord" );
    auto colour_location   = _prog.attribute_location ( "colour" );

    printf ( "[DEBUG] position location: %i\n", position_location );
    printf ( "[DEBUG] texcoord location: %i\n", texcoord_location );
    printf ( "[DEBUG] colour location: %i\n",   colour_location );

    auto attribs = glpp::vertex_attrib_builder<float>::sequential ( {
        { "position", 2, position_location },
        { "texcoord", 2, texcoord_location },
        { "colour", 3, colour_location }
    } );

    attribs[0].define_pointer().enable_array();
    attribs[1].define_pointer().enable_array();
    attribs[2].define_pointer().enable_array();

    _prog.unbind();
    _vao.unbind();
    _vbo.unbind();
    _ebo.unbind();

    GLPP_CHECK_ERROR ( "Created VAO" );
}

void renderer::_create_fbo() {
    printf ( "[DEBUG] Creating fbo...\n" );

    _fbo.bind()
        .attach_color ( _tex )
        .unbind();

    GLPP_CHECK_ERROR ( "Created FBO" );
}

void renderer::_create_texture ( const common::dims_2u& dims ) {
    printf ( "[DEBUG] Creating texture...\n" );
    printf ( "[DEBUG] Texture size: %s\n", dims.to_json().c_str() );

    glpp::texture::active_texture ( 1 );
    _tex.bind();
    _tex.image ( glpp::texture_2d::internal_format::rgb, dims )
        .generate_mipmaps()
        .wrap ( glpp::texture_2d::texture_wrap::clamp_to_edge )
        .filters ( _texture_filter );

    glpp::texture::active_texture ( 0 );

    GLPP_CHECK_ERROR ( "Created TEXTURE" );
}

void renderer::_calculate_aspect()
{
    _aspect = shimmer::video::aspect_transform ( _source_resolution,
                                                 _target_resolution,
                                                 _shim->config );
}
