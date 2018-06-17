#ifndef SHIMMER_RENDERER_H
#define SHIMMER_RENDERER_H

#include "dims.h"
#include "event.h"
#include "event_connector.h"
#include "image_reader.h"
#include "options.h"
#include "receiver.h"
#include "shader_reader.h"

#include "glpp/camera.h"
#include "glpp/framebuffer.h"
#include "glpp/program.h"
#include "glpp/quad.h"
#include "glpp/scene.h"
#include "glpp/texture_unit.h"

#include <memory>

namespace shimmer
{
class renderer : public receiver<event>
{
public:
    renderer( const dims_2u& application_resolution,
              const dims_2u& window_dimensions,
              const options& options );

    renderer(
        event_connector& connector,
        const dims_2u&   application_resolution,
        const dims_2u&   window_dimensions,
        const options&   options );

    virtual ~renderer();

    /**
     * @brief Send an event to the renderer.
     * @param event The event.
     */
    virtual void send ( const class event& event );

    void         update();

    void         create_application_texture_from_bound();

    void         create_application_framebuffer();

    void         bind_application_framebuffer();

    void         unbind_application_framebuffer();

    void         application_texture_flip_y ( bool flip );

    void         render();

private:
    event_connector* _connector;

    shimmer::dims_2u _application_resolution;

    shimmer::dims_2u _window_dimensions;

    options _opts;

    image_reader _images;

    shader_reader _shaders;

    bool _application_texture_flip_y;

    std::shared_ptr<glpp::framebuffer> _application_framebuffer;

    std::shared_ptr<glpp::texture_2d> _application_texture;

    std::shared_ptr<glpp::quad<GLfloat>> _application_quad;

    std::shared_ptr<glpp::entity> _application_surface;

    std::shared_ptr<glpp::entity> _background_surface;

    std::shared_ptr<glpp::entity> _scaling_surface;

    glpp::scene _scene;

    void             _construct_application_surface();

    void             _construct_surface_phase();

    void             _construct_application_phase();

    shimmer::dims_2f _calculate_quad_dimensions();


    void _application_resolution_event (
        const display_resolution_change& event );

    void _window_dimensions_event (
        const window_dims_change& event );
};
}

#endif // ifndef SHIMMER_RENDERER_H
