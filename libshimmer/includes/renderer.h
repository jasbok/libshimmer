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
    renderer();

    virtual ~renderer() = default;


    void init ( const struct application& application,
                const struct options&     options );

    void update ( const struct application& application );

    void update ( const struct options::video& options );

    void activate_application_texture();

    void render();

private:
    glpp::resource_loader _resource_loader;

    std::shared_ptr<glpp::entity> _application_surface;

    glpp::texture_unit _application_tu;

    std::shared_ptr<glpp::entity> _background_surface;

    std::shared_ptr<glpp::entity> _scaling_surface;

    glpp::scene _scene;


    void _setup_resource_loader ( const struct options& options );

    void _construct_application_surface (
        const struct application& application,
        const struct options&     options );

    void _construct_surface_phase ( const struct application& application );

    void _construct_application_phase ( const struct application& application );
};
}

#endif // ifndef SHIMMER_RENDERER_H
