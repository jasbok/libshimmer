#include "entity.h"

#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

using namespace glpp;

entity::entity( const glm::vec3& position,
                const glm::vec3& rotation,
                const glm::vec3& scale )
    : _position ( position ),
      _rotation ( rotation ),
      _scale ( scale ),
      _model ( 1.0f ),
      _program(),
      _textures(),
      _mesh(),
      _requires_update ( false )
{
    update_model();
}

entity& entity::position ( const glm::vec3& position )
{
    _position        = position;
    _requires_update = true;

    return *this;
}

entity& entity::move ( const glm::vec3& position )
{
    _position       += position;
    _requires_update = true;

    return *this;
}

glm::vec3 entity::position() const
{
    return _position;
}

entity& entity::rotation ( const glm::vec3& rotation )
{
    _rotation        = rotation;
    _requires_update = true;

    return *this;
}

entity& entity::rotate ( const glm::vec3& rotation )
{
    _rotation       += rotation;
    _requires_update = true;

    return *this;
}

glm::vec3 entity::rotation() const
{
    return _rotation;
}

entity& entity::scale ( const glm::vec3& scale )
{
    _scale           = scale;
    _requires_update = true;

    return *this;
}

glm::vec3 entity::scale() const
{
    return _scale;
}

entity& entity::update_model()
{
    _model = glm::translate ( glm::mat4 ( 1.0f ), _position );

    _model = glm::rotate ( _model,
                           glm::radians ( _rotation.z ),
                           { 0.0f, 0.0f, 1.0f } );

    _model = glm::rotate ( _model,
                           glm::radians ( _rotation.x ),
                           { 1.0f, 0.0f, 0.0f } );

    _model = glm::rotate ( _model,
                           glm::radians ( _rotation.y ),
                           { 0.0f, 1.0f, 0.0f } );

    _model = glm::scale ( _model, _scale );

    _requires_update = false;

    return *this;
}

glm::mat4 entity::model()
{
    if ( _requires_update ) update_model();

    return _model;
}

entity& entity::program ( const std::shared_ptr<class program>& program ) {
    _program = program;

    return *this;
}

std::shared_ptr<program> entity::program() {
    return _program;
}

entity& entity::textures (
    const std::shared_ptr<texture_units>& textures )
{
    _textures = textures;

    return *this;
}

std::shared_ptr<texture_units> entity::textures() {
    return _textures;
}

entity& entity::mesh ( const std::shared_ptr<class mesh>& mesh ) {
    _mesh = mesh;

    return *this;
}

std::shared_ptr<mesh> entity::mesh() {
    return _mesh;
}

entity& entity::draw()
{
    return *this;
}
