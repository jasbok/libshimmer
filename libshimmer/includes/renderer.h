#ifndef SHIMMER_RENDERER_H
#define SHIMMER_RENDERER_H

#include "camera.h"
#include "config.h"
#include "framebuffer.h"
#include "program.h"
#include "quad.h"
#include "scene.h"
#include "shader_reader.h"
#include "texture_unit.h"

#include <memory>

namespace shimmer
{
class renderer
{
public:
    renderer( const std::shared_ptr<config>& config );

    virtual ~renderer() = default;

    void update();

    void create_application_texture_from_bound();

    void render();

private:
    std::shared_ptr<config> _config;

    shader_reader _shaders;

    std::shared_ptr<glpp::texture_2d> _application_texture;

    std::shared_ptr<glpp::quad<GLfloat>> _application_quad;

    std::shared_ptr<glpp::entity> _application_surface;

    std::shared_ptr<glpp::entity> _background_surface;

    std::shared_ptr<glpp::entity> _scaling_surface;

    glpp::scene _scene;

    void          _construct_application_surface();

    void          _construct_surface_phase();

    void          _construct_application_phase();

    glpp::dims_2f _calculate_quad_dimensions();
};
}

#endif // ifndef SHIMMER_RENDERER_H
