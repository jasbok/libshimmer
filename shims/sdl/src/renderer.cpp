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
    : _shim ( shim ),
      _flip_target ( false )
{
    _create_source_program();
    _create_target_program();
    _create_vbo();
    _create_target_vbo();
    _create_ebo();
    _create_vao();
    _create_target_vao();

    if ( shim->config.video.filter == shimmer::config::video::filter::linear ) {
        _texture_filter = glpp::texture_2d::filter::linear;
    }
    else {
        _texture_filter = glpp::texture_2d::filter::nearest;
    }
}

void renderer::source_resolution ( const common::dims_2u& dims ) {
    _source_resolution       = dims;
    _intermediate_resolution = dims * _shim->config.video.shader.scale;

    _calculate_aspect();
    _create_vbo();

    _create_texture ( _source_resolution );
    _create_fbo();

    _create_target_texture ( _intermediate_resolution );
    _create_target_fbo();
}

void renderer::target_resolution ( const common::dims_2u& dims )
{
    _target_resolution = dims;
    _calculate_aspect();
    _create_vbo();
}

// void renderer::render() {
//    GLPP_CHECK_ERROR ( "PRE RENDER" );
//    GLPP_CHECK_FRAMEBUFFER ( "PRE RENDER" );

//    glViewport ( 0, 0,
//                 static_cast<GLint>( _target_resolution.width ),
//                 static_cast<GLint>( _target_resolution.height ) );

//    _source_prog.use();
//    _vao.bind();

//    glClear ( GL_COLOR_BUFFER_BIT );
//    glDrawElements ( GL_TRIANGLES,
//                     static_cast<GLint>( _ebo.elements() ),
//                     GL_UNSIGNED_INT,
//                     nullptr );

//    _source_prog.unbind();

//    GLPP_CHECK_ERROR ( "POST RENDER" );
//    GLPP_CHECK_FRAMEBUFFER ( "POST RENDER" );
// }

void renderer::render() {
    GLPP_CHECK_ERROR ( "PRE RENDER" );
    GLPP_CHECK_FRAMEBUFFER ( "PRE RENDER" );

    _target_fbo.bind();

    glViewport ( 0, 0,
                 static_cast<GLint>( _intermediate_resolution.width ),
                 static_cast<GLint>( _intermediate_resolution.height ) );

    _source_prog.use();
    _vao.bind();

    glClear ( GL_COLOR_BUFFER_BIT );
    glDrawElements ( GL_TRIANGLES,
                     static_cast<GLint>( _ebo.elements() ),
                     GL_UNSIGNED_INT,
                     nullptr );

    _target_fbo.unbind();

    glViewport ( 0, 0,
                 static_cast<GLint>( _target_resolution.width ),
                 static_cast<GLint>( _target_resolution.height ) );

    _target_prog.use();
    _target_vao.bind();

    glClear ( GL_COLOR_BUFFER_BIT );
    glDrawElements ( GL_TRIANGLES,
                     static_cast<GLint>( _ebo.elements() ),
                     GL_UNSIGNED_INT,
                     nullptr );

    _target_prog.unbind();

    GLPP_CHECK_ERROR ( "POST RENDER" );
    GLPP_CHECK_FRAMEBUFFER ( "POST RENDER" );
}

void renderer::capture_fbo() {
    _source_fbo.bind();

    glViewport ( 0, 0,
                 static_cast<GLsizei>( _source_resolution.width ),
                 static_cast<GLsizei>( _source_resolution.height ) );
}

void renderer::reset_fbo() {
    _source_fbo.unbind();

    glViewport ( 0, 0,
                 static_cast<GLint>( _target_resolution.width ),
                 static_cast<GLint>( _target_resolution.height ) );
}

void renderer::setup_viewport()
{
    glViewport ( 0, 0,
                 static_cast<GLint>( _target_resolution.width ),
                 static_cast<GLint>( _target_resolution.height ) );
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
}

void renderer::_create_source_program() {
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

    _source_prog.attach ( vs )
        .attach ( fs )
        .link_and_throw()
        .detach ( vs )
        .detach ( fs );

    _source_prog.use()
        .uniform ( "application", 1 )
        .unbind();

    GLPP_CHECK_ERROR ( "Created Program" );
}

void renderer::_create_target_program() {
    printf ( "[DEBUG] Creating target program...\n" );

    const auto& shader_dirs = _shim->config.general.shader_dirs;

    auto vs_file = common::file::find ( "default.vert", shader_dirs );
    auto fs_file = common::file::find ( "default.frag", shader_dirs  );

    auto vs_source = common::file::read_all ( vs_file );
    auto fs_source = common::file::read_all ( fs_file );

    auto vs = glpp::shader::create().vertex ( vs_source );
    auto fs = glpp::shader::create().fragment ( fs_source );

    vs.compile_and_throw();
    fs.compile_and_throw();

    _target_prog.attach ( vs )
        .attach ( fs )
        .link_and_throw()
        .detach ( vs )
        .detach ( fs );

    _target_prog.use()
        .uniform ( "application", 2 )
        .unbind();

    GLPP_CHECK_ERROR ( "Created Target Program" );
}

void renderer::_create_vbo() {
    printf ( "[DEBUG] Creating vbo...\n" );

    int flip = _flip_target ? -1 : 1;

    const float right  = static_cast<float>( _aspect.width );
    const float left   = -1 * right;
    const float top    = static_cast<float>( flip * _aspect.height );
    const float bottom = -1 * top;

    _vbo.bind()
        .data<float>( {
        // position   // texcoords // colour
        right, top, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,   // TR
        left, top, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,    // TL
        left, bottom, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, // BL
        right, bottom, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f // BR
    } )
        .unbind();

    GLPP_CHECK_ERROR ( "Created VBO" );
}

void renderer::_create_target_vbo() {
    printf ( "[DEBUG] Creating target vbo...\n" );

    int flip = _flip_target ? -1 : 1;

    const float right  = 1.0f;
    const float left   = -1 * right;
    const float top    = flip * 1.0f;
    const float bottom = -1 * top;

    _target_vbo.bind()
        .data<float>( {
        // position   // texcoords // colour
        right, top, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,   // TR
        left, top, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,    // TL
        left, bottom, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, // BL
        right, bottom, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f // BR
    } )
        .unbind();

    GLPP_CHECK_ERROR ( "Created target VBO" );
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

    _source_prog.use();
    auto position_location = _source_prog.attribute_location ( "position" );
    auto texcoord_location = _source_prog.attribute_location ( "texcoord" );
    auto colour_location   = _source_prog.attribute_location ( "colour" );

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

    _source_prog.unbind();
    _vao.unbind();
    _vbo.unbind();
    _ebo.unbind();

    GLPP_CHECK_ERROR ( "Created VAO" );
}

void renderer::_create_target_vao()
{
    printf ( "[DEBUG] Creating target vao...\n" );

    _target_vao.bind();
    _target_vbo.bind();
    _ebo.bind();

    _target_prog.use();
    auto position_location = _target_prog.attribute_location ( "position" );
    auto texcoord_location = _target_prog.attribute_location ( "texcoord" );
    auto colour_location   = _target_prog.attribute_location ( "colour" );

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

    _target_prog.unbind();
    _target_vao.unbind();
    _target_vbo.unbind();
    _ebo.unbind();

    GLPP_CHECK_ERROR ( "Created target VAO" );
}

void renderer::_create_fbo() {
    printf ( "[DEBUG] Creating fbo...\n" );

    _source_fbo.bind()
        .attach_color ( _source_tex )
        .unbind();

    GLPP_CHECK_ERROR ( "Created FBO" );
}

void renderer::_create_target_fbo() {
    printf ( "[DEBUG] Creating target fbo...\n" );

    _target_fbo.bind()
        .attach_color ( _target_tex )
        .unbind();

    GLPP_CHECK_ERROR ( "Created target FBO" );
}

void renderer::_create_texture ( const common::dims_2u& dims ) {
    printf ( "[DEBUG] Creating texture...\n" );
    printf ( "[DEBUG] Texture size: %s\n", dims.to_json().c_str() );

    glpp::texture::active_texture ( 1 );
    _source_tex.bind();
    _source_tex.image ( glpp::texture_2d::internal_format::rgb, dims )
        .generate_mipmaps()
        .wrap ( glpp::texture_2d::texture_wrap::clamp_to_edge )
        .filters ( glpp::texture_2d::filter::nearest );

    glpp::texture::active_texture ( 0 );

    GLPP_CHECK_ERROR ( "Created TEXTURE" );
}

void renderer::_create_target_texture ( const common::dims_2u& dims ) {
    printf ( "[DEBUG] Creating target texture...\n" );
    printf ( "[DEBUG] Target texture size: %s\n", dims.to_json().c_str() );

    glpp::texture::active_texture ( 2 );
    _target_tex.bind();
    _target_tex.image ( glpp::texture_2d::internal_format::rgb, dims )
        .generate_mipmaps()
        .wrap ( glpp::texture_2d::texture_wrap::clamp_to_edge )
        .filters ( _texture_filter );

    glpp::texture::active_texture ( 0 );

    GLPP_CHECK_ERROR ( "Created target TEXTURE" );
}

void renderer::_calculate_aspect()
{
    _aspect = shimmer::video::aspect_transform ( _source_resolution,
                                                 _target_resolution,
                                                 _shim->config );
}
