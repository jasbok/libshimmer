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

    _application_texture = glpp::texture_2d::make_shared (
        application.surface.dims );
    _application_texture->filters ( glpp::texture_2d::filter::linear );


    _application_surface = glpp::quad<GLfloat>::make_shared ( { 1.0f, 1.0f } );
}
