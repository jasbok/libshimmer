#ifndef SHIMMER_RENDERER_H
#define SHIMMER_RENDERER_H

#include "options.h"
#include "program.h"
#include "quad.h"
#include "resource_loader.h"

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

private:
    glpp::resource_loader _resource_loader;


    std::shared_ptr<glpp::program> _application_shader;

    std::shared_ptr<glpp::program> _background_shader;

    std::shared_ptr<glpp::program> _scaling_shader;


    std::shared_ptr<glpp::texture_2d> _application_texture;


    std::shared_ptr<glpp::quad<GLfloat>> _application_surface;

    std::shared_ptr<glpp::quad<GLfloat>> _background_surface;
};
}

#endif // ifndef SHIMMER_RENDERER_H
