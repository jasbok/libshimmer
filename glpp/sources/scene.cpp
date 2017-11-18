#include "scene.h"

using namespace glpp;
using namespace std;

scene& scene::add ( scene_phase&& phase ) {
    _phases.push_back ( std::move ( phase ) );

    return *this;
}

scene_phase& scene::phase ( const string& id ) {
    for ( auto& phase : _phases ) {
        if ( phase.id().compare ( id ) == 0 ) {
            return phase;
        }
    }

    std::cerr << "Could not find the specified scene phase: "
              << id << std::endl;
    throw phase_not_found_exception();
}

void scene::draw() {
    std::shared_ptr<viewport_int> current_viewport;
    std::shared_ptr<framebuffer>  current_fbo;

    for ( auto& phase : _phases ) {
        if ( phase.viewport() != current_viewport ) {
            current_viewport = phase.viewport();

            glViewport ( current_viewport->coords.x,
                         current_viewport->coords.y,
                         current_viewport->dims.width,
                         current_viewport->dims.height );
        }

        if ( phase.framebuffer() != current_fbo ) {
            if ( phase.framebuffer() ) {
                phase.framebuffer()->bind();
            }
            else {
                current_fbo->unbind();
            }

            glClear ( GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT );
            current_fbo = phase.framebuffer();
        }

        phase.draw();
    }
}
