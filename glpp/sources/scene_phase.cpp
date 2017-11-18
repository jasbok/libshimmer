#include "scene_phase.h"

#include <iostream>

using namespace glpp;
using namespace std;

scene_phase::scene_phase( const string                              id,
                          const std::shared_ptr<class camera>&      camera,
                          const std::shared_ptr<viewport_int>&      viewport,
                          const std::shared_ptr<class framebuffer>& fbo )
    : _id ( id ),
      _camera ( camera ),
      _viewport ( viewport ),
      _fbo ( fbo ),
      _entities()
{}

string scene_phase::id() const {
    return _id;
}

shared_ptr<class camera> scene_phase::camera() const {
    return _camera;
}

shared_ptr<viewport_int> scene_phase::viewport() const {
    return _viewport;
}

shared_ptr<class framebuffer> scene_phase::framebuffer() const {
    return _fbo;
}

scene_phase& scene_phase::entities ( vector<shared_ptr<entity>>&& entities )
{
    _entities = std::move ( entities );

    return *this;
}

scene_phase& scene_phase::add ( const shared_ptr<entity>& entity ) {
    auto it = std::find ( _entities.begin(), _entities.end(), entity );

    if ( it == _entities.end() ) {
        _entities.push_back ( entity );
    }

    return *this;
}

scene_phase& scene_phase::remove ( const shared_ptr<entity>& entity ) {
    auto it = std::find ( _entities.begin(), _entities.end(), entity );

    if ( it != _entities.end() ) {
        _entities.erase ( it );
    }

    return *this;
}

void scene_phase::draw() {
    std::shared_ptr<program> bound_program;
    std::shared_ptr<texture_units> bound_texture_units;
    std::shared_ptr<mesh> bound_mesh;

    for ( auto& entity : _entities ) {
        if ( entity->program() && entity->program() != bound_program ) {
            bound_program = entity->program();
            bound_program->use();
            bound_program->uniform ( "view",       _camera->view() );
            bound_program->uniform ( "projection", _camera->projection() );
        }

        if ( entity->textures() && entity->textures() != bound_texture_units ) {
            bound_texture_units = entity->textures();
            bound_texture_units->bind();
        }

        if ( entity->mesh() && entity->mesh() != bound_mesh ) {
            bound_mesh = entity->mesh();
            bound_mesh->bind();
            bound_mesh->program ( *bound_program );
        }

        bound_program->uniform ( "model", entity->model() );
        bound_mesh->draw();
    }
}
