#include "renderer.h"

#include "pixels.h"

using namespace shimmer;

renderer::renderer()
    : _resource_loader()
{}

void renderer::init ( const struct application& application,
                      const struct options&     options ) {
    auto& resource_paths = options.general.resource_paths;

    if ( resource_paths.has_value() ) {
        _resource_loader.search_paths ( resource_paths.value() );
    }

    auto& video = options.video;

    auto& application_shader = video.application_shader;

    if ( application_shader.has_value() ) {
        auto& shader = application_shader.value();
        _application_shader = std::make_shared<glpp::program>(
            _resource_loader.program (
                shader.vertex,
                shader.fragment ) );
    }

    _application_texture = std::make_shared<glpp::texture_2d>(
        glpp::texture_2d::internal_format::rgb );

    _application_texture->bind();
    _application_texture->
        min_filter ( glpp::texture_2d::min_filter::nearest )
        .mag_filter ( glpp::texture_2d::mag_filter::nearest )
        .image ( glpp::pixels ( nullptr,
                                application.surface.dims,
                                glpp::pixels::format::rgb,
                                glpp::pixels::type::gl_unsigned_byte ) );

    _application_surface = glpp::quad<GLfloat>::make_shared ( { 1.0f, 1.0f } );
    _background_surface  = glpp::quad<GLfloat>::make_shared ( { 1.0f, 1.0f } );
}
