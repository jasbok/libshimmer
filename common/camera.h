#ifndef COMMON_CAMERA_H
#define COMMON_CAMERA_H

#include "dims.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace common
{
class camera
{
public:
    camera();

    camera( const glm::vec3& position,
            const glm::vec3& rotation,
            const glm::mat4& projection );

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


    camera& projection ( const glm::mat4& projection );

    camera& perspective ( float fov,
                          float aspect,
                          float near,
                          float far );

    camera& ortho ( float left,
                    float right,
                    float bottom,
                    float top );

    camera& ortho ( float left,
                    float right,
                    float bottom,
                    float top,
                    float near,
                    float far );

    camera&   screen ( const dims_2u& dims );

    glm::mat4 projection();

private:
    glm::vec3 _position;

    glm::vec3 _rotation;

    glm::vec3 _direction;

    glm::vec3 _up;

    glm::vec3 _right;

    glm::mat4 _view;

    glm::mat4 _projection;

    bool _require_update;

    void _clip_rotation();
};
}

#endif
