#ifndef SHIMMER_RENDERER_H
#define SHIMMER_RENDERER_H

#include "camera.h"
#include "framebuffer.h"
#include "options.h"
#include "program.h"
#include "quad.h"
#include "resource_loader.h"
#include "scene.h"
#include "texture_unit.h"

#include <memory>

namespace shimmer
{
class renderer
{
public:
    renderer( const std::shared_ptr<struct application>& application,
              const std::shared_ptr<struct options>&     options );

    virtual ~renderer() = default;


    void init();

    void update();

    void create_application_texture_from_bound();

    void render();

private:
    glpp::resource_loader _resource_loader;

    std::shared_ptr<glpp::texture_2d> _application_texture;

    std::shared_ptr<glpp::quad<GLfloat>> _application_quad;

    std::shared_ptr<glpp::entity> _application_surface;

    std::shared_ptr<glpp::entity> _background_surface;

    std::shared_ptr<glpp::entity> _scaling_surface;

    glpp::scene _scene;


    std::shared_ptr<struct application> _application;

    std::shared_ptr<struct options> _options;


    void          _setup_resource_loader();

    void          _construct_application_surface();

    void          _construct_surface_phase();

    void          _construct_application_phase();

    glpp::dims_2f _calculate_quad_dimensions();
};
}

#endif // ifndef SHIMMER_RENDERER_H
