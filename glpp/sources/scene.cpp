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
    for ( auto& phase : _phases ) {
        phase.draw();
    }
}
