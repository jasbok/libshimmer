#include "renderer.h"

#include "pixels.h"

using namespace shimmer;

renderer::renderer(
    const std::shared_ptr<config>& config )
    : _config ( config ),
      _shaders ( config->opts.general.shader_paths )
{
    _construct_application_surface();
    _construct_surface_phase();
}

void renderer::update()
{
    auto& surface = _scene["surface"];

    surface.viewport()->dims = _config->app.window.dims;
    _application_quad->bind();
    _application_quad->dimensions ( _calculate_quad_dimensions() );
}

void renderer::create_application_texture_from_bound()
{
    GLint texture_handle;

    glGetIntegerv ( GL_TEXTURE_BINDING_2D, &texture_handle );

    *_application_texture =
        std::move ( glpp::texture_2d ( texture_handle,
                                       _config->app.surface.dims,
                                       glpp::texture::internal_format::rgba ) );

    if ( _config->opts.video.application_shader.linear_filter ) {
        _application_texture->filters ( glpp::texture_2d::filter::linear );
    }
}

void renderer::render()
{
    _scene.draw();
}

void renderer::_construct_application_surface()
{
    auto& video              = _config->opts.video;
    auto& application_shader = video.application_shader;

    auto application_program = _shaders.shared_program (
        application_shader.vertex,
        application_shader.fragment );

    application_program->use().uniform ( "application", 0 );

    _application_texture =
        glpp::texture_2d::make_shared ( _config->app.surface.dims );

    _application_quad = glpp::quad<GLfloat>::make_shared ( { 1.0f, 1.0f } );

    _application_surface = std::make_shared<glpp::entity>();

    _application_surface->
        program ( application_program )
        .textures ( glpp::texture_units::make_shared (
                        { _application_texture } ) )
        .mesh ( _application_quad );

    if ( _config->opts.video.application_shader.linear_filter ) {
        _application_texture->filters ( glpp::texture_2d::filter::linear );
    }
}

void renderer::_construct_surface_phase()
{
    glpp::scene_phase surface_phase (
        "surface",
        std::make_shared<glpp::camera>(),
        std::make_shared<glpp::viewport_int>() );

    surface_phase.viewport()->coords = { 0, 0 };
    surface_phase.viewport()->dims   = _config->app.window.dims;

    surface_phase.camera()->rotate ( {
        0.0, 180.0, 0.0
    } );

    surface_phase
        .clear_bits ( { GL_COLOR_BUFFER_BIT } )
        .add ( _application_surface );

    _scene.add ( std::move ( surface_phase ) );
}

void renderer::_construct_application_phase()
{
    glpp::scene_phase application_phase (
        "application",
        std::make_shared<glpp::camera>(),
        std::make_shared<glpp::viewport_int>(),
        std::make_shared<glpp::framebuffer>() );

    application_phase.viewport()->coords = { 0, 0 };
    application_phase.viewport()->dims   = _config->app.surface.dims;

    application_phase
        .clear_bits ( { GL_COLOR_BUFFER_BIT } )
        .framebuffer()->bind().
        attach_color ( *_application_surface->textures()->textures()[0] );

    _scene.add ( std::move ( application_phase ) );
}

glpp::dims_2f renderer::_calculate_quad_dimensions()
{
    auto& app_dims = _config->app.surface.dims;
    auto& win_dims = _config->app.window.dims;

    if ( _config->opts.video.aspect_ratio == aspect_ratio::stretch ) {
        return { 1.0f, 1.0f };
    } else {
        float ar_factor = app_dims.wh_ratio() / win_dims.wh_ratio();

        if ( _config->opts.video.aspect_ratio == aspect_ratio::zoom ) {
            return { ar_factor < 1.0f ?  1.0f : ar_factor,
                     ar_factor < 1.0f ? 1.0f / ar_factor : 1.0f };
        } else {
            return { ar_factor > 1.0f ?  1.0f : ar_factor,
                     ar_factor > 1.0f ? 1.0f / ar_factor : 1.0f };
        }
    }
}
