#ifndef GLPP_CAMERA_H
#define GLPP_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace glpp
{
class camera
{
public:
    camera() = default;

    camera( glm::vec3 position,
            glm::vec3 rotation );

    camera( camera&& move ) = default;

    camera( const camera& copy ) = default;

    virtual ~camera() = default;

    camera& operator=( camera&& move ) = default;

    camera& operator=( const camera& copy ) = default;


    camera&   position ( const glm::vec3& position );

    camera&   move ( const glm::vec3& position );

    glm::vec3 position() const;

    camera&   rotation ( const glm::vec3& rotation );

    camera&   rotate ( const glm::vec3& rotation );

    glm::vec3 rotation() const;

    camera&   update();

    glm::mat4 view();

private:
    glm::vec3 _position;

    glm::vec3 _rotation;

    glm::vec3 _direction;

    glm::vec3 _up;

    glm::vec3 _right;

    glm::mat4 _view;

    bool _require_update;

    void _clip_rotation();
};
}

#endif // ifndef GLPP_CAMERA_H
