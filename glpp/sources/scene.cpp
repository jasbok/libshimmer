#include "scene.h"

#include "debug.h"

using namespace glpp;
using namespace std;

scene& scene::add ( scene_phase&& phase ) {
    operator[]( phase.id() ) = std::move ( phase );

    return *this;
}

scene_phase& scene::find ( const string& id ) {
    for ( auto& phase : _phases ) {
        if ( phase.id().compare ( id ) == 0 ) {
            return phase;
        }
    }

    throw phase_not_found_exception();
}

scene_phase& scene::operator[]( const string& id )
{
    for ( auto& phase : _phases ) {
        if ( phase.id().compare ( id ) == 0 ) return phase;
    }

    _phases.push_back ( scene_phase ( id ) );

    return _phases.back();
}

void scene::draw() {
    std::shared_ptr<viewport_int> current_viewport;
    std::shared_ptr<framebuffer>  current_fbo;

    for ( auto& phase : _phases ) {
        if ( phase.viewport() && ( phase.viewport() != current_viewport ) ) {
            current_viewport = phase.viewport();

            printf ( "Setting viewport: %s, %s\n",
                     current_viewport->coords.to_json().c_str(),
                     current_viewport->dims.to_json().c_str() );

            glViewport ( current_viewport->coords.x,
                         current_viewport->coords.y,
                         current_viewport->dims.width,
                         current_viewport->dims.height );
        }
        GLPP_CHECK_ERROR ( "Phase: Set Viewports" );


        if ( phase.framebuffer() != current_fbo ) {
            if ( phase.framebuffer() ) {
                phase.framebuffer()->bind();
                GLPP_CHECK_ERROR ( "Phase: Bound FBO" );
            }
            else if ( current_fbo ) {
                current_fbo->unbind();
                GLPP_CHECK_ERROR ( "Phase: Unbound FBO" );
            }

            current_fbo = phase.framebuffer();
        }
        GLPP_CHECK_ERROR ( "Phase: Set FBO" );

        phase.draw();
        GLPP_CHECK_ERROR ( "Phase: Rendered" );
    }
}
