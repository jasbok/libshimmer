#include "renderer.h"

#include "debug.h"
#include "logger.h"
#include "logger.h"
#include "pixels.h"

using namespace shimmer;

renderer::renderer(
    const dims_2u& application_resolution,
    const dims_2u& window_dimensions,
    const options& options )
    : _connector ( nullptr ),
      _application_resolution ( application_resolution ),
      _window_dimensions ( window_dimensions ),
      _opts ( options ),
      _images ( _opts.general.image_paths ),
      _shaders ( _opts.general.shader_paths ),
      _application_texture_flip_y ( false )
{
    _construct_application_surface();
    _construct_surface_phase();
}

renderer::renderer(
    event_connector& connector,
    const dims_2u&   application_resolution,
    const dims_2u&   window_dimensions,
    const options&   options )
    : _connector ( &connector ),
      _application_resolution ( application_resolution ),
      _window_dimensions ( window_dimensions ),
      _opts ( options ),
      _images ( _opts.general.image_paths ),
      _shaders ( _opts.general.shader_paths ),
      _application_texture_flip_y ( false )
{
    _connector->connect ( display_resolution_change::type(), *this );
    _connector->connect ( window_dims_change::type(),        *this );

    _construct_application_surface();
    _construct_surface_phase();
}

renderer::~renderer()
{
    if ( _connector ) {
        LOGD << "Disconnecting render system from events connector.";
        _connector->disconnect ( display_resolution_change::type(), *this );
        _connector->disconnect ( window_dims_change::type(),        *this );
    }
}

void renderer::send ( const event& event ) {
    switch ( event.type() ) {
    case event::type::display_resolution_change:
        _application_resolution_event ( event );
        break;

    case event::type::window_dims_change:
        _window_dimensions_event ( event );
        break;

    default:
        break;
    }
}

void renderer::update()
{
    auto& surface = _scene["surface"];

    surface.viewport()->dims = _window_dimensions;
    _application_quad->bind();
    _application_quad->dimensions ( _calculate_quad_dimensions(),
                                    _application_texture_flip_y );
}

void renderer::create_application_texture_from_bound()
{
    GLint texture_handle;

    glGetIntegerv ( GL_TEXTURE_BINDING_2D, &texture_handle );

    //    *_application_texture =
    //        glpp::texture_2d ( static_cast<GLuint>( texture_handle ),
    //                           _application_resolution,
    //                           glpp::texture::internal_format::rgba );

    if ( !_opts.video.application_shader.linear_filter ) {
        _application_texture->filters ( glpp::texture_2d::filter::nearest );
    }
}

void renderer::create_application_framebuffer()
{
    _application_framebuffer = std::make_shared<glpp::framebuffer>();
    _application_framebuffer->bind();
    _application_framebuffer->attach_color ( *_application_texture );

    GLPP_CHECK_FRAMEBUFFER ( "Create Application Framebuffer" );
}

void renderer::bind_application_framebuffer()
{
    _application_framebuffer->bind();

    glViewport ( 0, 0,
                 static_cast<GLsizei>( _application_resolution.width ),
                 static_cast<GLsizei>( _application_resolution.height ) );

    GLPP_CHECK_FRAMEBUFFER ( "Bind Application Framebuffer" );
}

void renderer::unbind_application_framebuffer()
{
    _application_framebuffer->unbind();

    GLPP_CHECK_FRAMEBUFFER ( "Unbind Application Framebuffer" );
}

void renderer::application_texture_flip_y ( bool flip_y )
{
    _application_texture_flip_y = flip_y;

    _application_quad->bind();
    _application_quad->dimensions ( _calculate_quad_dimensions(),
                                    _application_texture_flip_y );
}

void renderer::render()
{
    _scene.draw();
}

void renderer::_construct_application_surface()
{
    auto& video              = _opts.video;
    auto& application_shader = video.application_shader;

    auto application_program = _shaders.shared_program (
        application_shader.vertex,
        application_shader.fragment );

    application_program->use().uniform ( "application", 0 );

    _application_texture =
        std::make_shared<glpp::texture_2d>(
            glpp::texture_2d::internal_format::rgb,
            _application_resolution );
    _application_texture->bind();
    _application_texture->generate_mipmaps();

    if ( !_opts.video.application_shader.linear_filter ) {
        _application_texture->filters ( glpp::texture_2d::filter::nearest );
    }

    _application_quad =
        glpp::quad<GLfloat>::make_shared ( _calculate_quad_dimensions() );

    _application_surface = std::make_shared<glpp::entity>();

    _application_surface->
        program ( application_program )
        .textures ( glpp::texture_units::make_shared (
                        { _application_texture } ) )
        .mesh ( _application_quad );
}

void renderer::_construct_surface_phase()
{
    glpp::scene_phase surface_phase (
        "surface",
        std::make_shared<glpp::camera>(),
        std::make_shared<glpp::viewport_int>() );

    surface_phase.viewport()->coords = { 0, 0 };
    surface_phase.viewport()->dims   = _window_dimensions;

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
    application_phase.viewport()->dims   = _application_resolution;

    application_phase
        .clear_bits ( { GL_COLOR_BUFFER_BIT } )
        .framebuffer()->bind().
        attach_color ( *_application_surface->textures()->textures()[0] );

    _scene.add ( std::move ( application_phase ) );
}

dims_2f renderer::_calculate_quad_dimensions()
{
    auto& app_dims = _application_resolution;
    auto& win_dims = _window_dimensions;

    if ( _opts.video.aspect_ratio != aspect_ratio::stretch ) {
        float ar_factor = app_dims.wh_ratio() / win_dims.wh_ratio();

        if ( _opts.video.aspect_ratio == aspect_ratio::zoom ) {
            return { ar_factor < 1.0f ?  1.0f : ar_factor,
                     ar_factor < 1.0f ? 1.0f / ar_factor : 1.0f };
        } else {
            return { ar_factor > 1.0f ?  1.0f : ar_factor,
                     ar_factor > 1.0f ? 1.0f / ar_factor : 1.0f };
        }
    }

    return { 1.0f, 1.0f };
}

void renderer::_application_resolution_event (
    const display_resolution_change& event ) {
    _application_resolution = event.data();
}

void renderer::_window_dimensions_event ( const window_dims_change& event ) {
    _window_dimensions = event.data();
}
