#ifndef GLPP_ENTITY_H
#define GLPP_ENTITY_H

#include <glm/glm.hpp>

namespace glpp
{
class entity
{
public:
    entity( const glm::vec3& position = glm::vec3( 0.0f, 0.0f, 0.0f ),
            const glm::vec3& rotation = glm::vec3( 0.0f, 0.0f, 1.0f ),
            const glm::vec3& scale = glm::vec3( 1.0f, 1.0f, 1.0f ) );

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

private:
    glm::vec3 _position;

    glm::vec3 _rotation;

    glm::vec3 _scale;

    glm::mat4 _model;

    bool _requires_update;
};
}

#endif // ifndef GLPP_ENTITY_H
