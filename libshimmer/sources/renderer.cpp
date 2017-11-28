#include "renderer.h"

#include "pixels.h"

#include "debug.h"

using namespace shimmer;

renderer::renderer()
    : _resource_loader()
{}

void renderer::init ( const struct application& application,
                      const struct options&     options ) {
    _setup_resource_loader ( options );
    _construct_application_surface ( application, options );
    _construct_surface_phase ( application );

    // _construct_application_phase ( application );
}

void renderer::update ( const struct application& application )
{
    auto& surface = _scene["surface"];

    surface.viewport()->dims = application.window.dims;
}

void renderer::update ( const struct options::video& options )
{}

void renderer::create_application_texture_from_bound (
    const struct application& application,
    const struct options&     options )
{
    GLint texture_handle;

    glGetIntegerv ( GL_TEXTURE_BINDING_2D, &texture_handle );

    *_application_texture =
        std::move ( glpp::texture_2d ( texture_handle,
                                       application.surface.dims,
                                       glpp::texture::internal_format::rgba ) );

    if ( options.video.application_linear_filter ) _application_texture->
            filters (
            glpp::texture_2d::filter::linear );
}

void renderer::render()
{
    _scene.draw();
}

void renderer::_setup_resource_loader ( const options& options )
{
    _resource_loader.search_paths ( options.general.resource_paths );
}

void renderer::_construct_application_surface (
    const struct application& application,
    const struct options&     options )
{
    auto& video              = options.video;
    auto& application_shader = video.application_shader;

    auto application_program = _resource_loader.shared_program (
        application_shader.vertex, application_shader.fragment );

    application_program->use().uniform ( "application", 0 );

    _application_texture =
        glpp::texture_2d::make_shared ( application.surface.dims );

    _application_surface = std::make_shared<glpp::entity>();

    _application_surface->
        program ( application_program )
        .textures ( glpp::texture_units::make_shared (
                        { _application_texture } ) )
        .mesh ( glpp::quad<GLfloat>::make_shared ( { 1.0f, 1.0f } ) );

    if ( video.application_linear_filter ) _application_surface->textures()->
            filters ( glpp::texture_2d::filter::linear );
}

void renderer::_construct_surface_phase ( const struct application& application )
{
    glpp::scene_phase surface_phase (
        "surface",
        std::make_shared<glpp::camera>(),
        std::make_shared<glpp::viewport_int>() );

    surface_phase.viewport()->coords = { 0, 0 };
    surface_phase.viewport()->dims   = application.window.dims;

    surface_phase.camera()->rotate ( {
        0.0, 180.0, 0.0
    } );

    surface_phase
        .clear_bits ( { GL_COLOR_BUFFER_BIT } )
        .add ( _application_surface );

    _scene.add ( std::move ( surface_phase ) );
}

void renderer::_construct_application_phase (
    const struct application& application )
{
    glpp::scene_phase application_phase (
        "application",
        std::make_shared<glpp::camera>(),
        std::make_shared<glpp::viewport_int>(),
        std::make_shared<glpp::framebuffer>() );

    application_phase.viewport()->coords = { 0, 0 };
    application_phase.viewport()->dims   = application.surface.dims;

    application_phase
        .clear_bits ( { GL_COLOR_BUFFER_BIT } )
        .framebuffer()->bind().
        attach_color ( *_application_surface->textures()->textures()[0] );

    _scene.add ( std::move ( application_phase ) );
}
