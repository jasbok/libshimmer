#include "renderer.h"

#include "pixels.h"

#include "debug.h"

using namespace shimmer;

renderer::renderer(
    const std::shared_ptr<struct application>& application,
    const std::shared_ptr<struct options>&     options )
    : _resource_loader(),
      _application ( application ),
      _options ( options )
{}

void renderer::init() {
    _setup_resource_loader();
    _construct_application_surface();
    _construct_surface_phase();

    // _construct_application_phase ( application );
}

void renderer::update()
{
    auto& surface = _scene["surface"];

    surface.viewport()->dims = _application->window.dims;
    _application_quad->bind();
    _application_quad->dimensions ( _calculate_quad_dimensions() );
}

void renderer::create_application_texture_from_bound()
{
    GLint texture_handle;

    glGetIntegerv ( GL_TEXTURE_BINDING_2D, &texture_handle );

    *_application_texture =
        std::move ( glpp::texture_2d ( texture_handle,
                                       _application->surface.dims,
                                       glpp::texture::internal_format::rgba ) );

    if ( _options->video.application_linear_filter ) _application_texture->
            filters (
            glpp::texture_2d::filter::linear );
}

void renderer::render()
{
    _scene.draw();
}

void renderer::_setup_resource_loader()
{
    _resource_loader.search_paths ( _options->general.resource_paths );
}

void renderer::_construct_application_surface()
{
    auto& video              = _options->video;
    auto& application_shader = video.application_shader;

    auto application_program = _resource_loader.shared_program (
        application_shader.vertex, application_shader.fragment );

    application_program->use().uniform ( "application", 0 );

    _application_texture =
        glpp::texture_2d::make_shared ( _application->surface.dims );

    _application_quad = glpp::quad<GLfloat>::make_shared (
        video.application_viewport );

    _application_surface = std::make_shared<glpp::entity>();

    _application_surface->
        program ( application_program )
        .textures ( glpp::texture_units::make_shared (
                        { _application_texture } ) )
        .mesh ( _application_quad );

    if ( video.application_linear_filter ) _application_surface->textures()->
            filters ( glpp::texture_2d::filter::linear );
}

void renderer::_construct_surface_phase()
{
    glpp::scene_phase surface_phase (
        "surface",
        std::make_shared<glpp::camera>(),
        std::make_shared<glpp::viewport_int>() );

    surface_phase.viewport()->coords = { 0, 0 };
    surface_phase.viewport()->dims   = _application->window.dims;

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
    application_phase.viewport()->dims   = _application->surface.dims;

    application_phase
        .clear_bits ( { GL_COLOR_BUFFER_BIT } )
        .framebuffer()->bind().
        attach_color ( *_application_surface->textures()->textures()[0] );

    _scene.add ( std::move ( application_phase ) );
}

glpp::dims_2f renderer::_calculate_quad_dimensions()
{
    std::string ar_option = "original";

    auto& app_dims = _application->surface.dims;
    auto& win_dims = _application->window.dims;

    if ( ar_option.compare ( "stretch" ) == 0 ) {
        return { 1.0f, 1.0f };
    } else {
        float ar_app    = app_dims.wh_ratio();
        float ar_video  = win_dims.wh_ratio();
        float ar_factor = ar_app / ar_video;

        if ( ar_option.compare ( "original" ) != 0 ) {
            glpp::dims_2f ar = { 1.0, 1.0 };
            ar_factor = ar.wh_ratio() / win_dims.wh_ratio();
        }

        if ( ar_option.compare ( "zoom" ) == 0 ) {
            return { ar_factor < 1.0f ?  1.0f : ar_factor,
                     ar_factor < 1.0f ? 1.0f / ar_factor : 1.0f };
        } else {
            return { ar_factor > 1.0f ?  1.0f : ar_factor,
                     ar_factor > 1.0f ? 1.0f / ar_factor : 1.0f };
        }
    }
}
