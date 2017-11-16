#ifndef GLPP_ENTITY_H
#define GLPP_ENTITY_H

#include "mesh.h"
#include "program.h"
#include "texture_units.h"

#include <glm/glm.hpp>

#include <memory>

namespace glpp
{
class entity
{
public:
    entity( const glm::vec3& position = glm::vec3( 0.0f, 0.0f, 0.0f ),
            const glm::vec3& rotation = glm::vec3( 0.0f, 0.0f, 1.0f ),
            const glm::vec3& scale    = glm::vec3( 1.0f, 1.0f, 1.0f ) );

    entity( entity&& move ) = default;

    entity( const entity& copy ) = default;

    virtual ~entity() = default;

    entity& operator=( entity&& move ) = default;

    entity& operator=( const entity& copy ) = default;


    entity&   position ( const glm::vec3& position );

    entity&   move ( const glm::vec3& position );

    glm::vec3 position() const;


    entity&   rotation ( const glm::vec3& rotation );

    entity&   rotate ( const glm::vec3& rotation );

    glm::vec3 rotation() const;


    entity&   scale ( const glm::vec3& scale );

    glm::vec3 scale() const;


    entity&   update_model();

    glm::mat4 model();

    entity&   program (
        const std::shared_ptr<program>& program );

    std::shared_ptr<class program> program();

    entity&                        textures (
        const std::shared_ptr<texture_units>& textures );

    std::shared_ptr<texture_units> textures();

    entity&                        mesh (
        const std::shared_ptr<mesh>& mesh );

    std::shared_ptr<class mesh> mesh();

    entity&                     draw();

private:
    glm::vec3 _position;

    glm::vec3 _rotation;

    glm::vec3 _scale;

    glm::mat4 _model;

    std::shared_ptr<class program> _program;

    std::shared_ptr<texture_units> _textures;

    std::shared_ptr<class mesh> _mesh;

    bool _requires_update;
};
}

#endif // ifndef GLPP_ENTITY_H
