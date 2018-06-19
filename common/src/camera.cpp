#include "camera.h"

namespace common {

static const glm::vec3 WORLD_UP = { 0.0f, 1.0f, 0.0f };

camera::camera()
    : _position ( 0, 0, 0 ),
      _rotation ( 0, 0, 0 ),
      _projection ( glm::mat4 ( 1.0f ) ),
      _require_update ( false )
{
    update();
}

camera::camera( const glm::vec3& position,
                      const glm::vec3& rotation,
                      const glm::mat4& projection )
    : _position ( position ),
      _rotation ( rotation ),
      _projection ( projection ),
      _require_update ( false )
{
    update();
}

camera& camera::move ( const glm::vec3& position )
{
    _position += position.x * _right
                 + position.y * _up
                 + position.z * _direction;

    _require_update = true;

    return *this;
}

camera& camera::position ( const glm::vec3& position )
{
    _position       = position;
    _require_update = true;

    return *this;
}

glm::vec3 camera::position() const
{
    return _position;
}

camera& camera::rotate ( const glm::vec3& rotation )
{
    _rotation      -= rotation;
    _require_update = true;

    _clip_rotation();

    return *this;
}

camera& camera::rotation ( const glm::vec3& rotation )
{
    _rotation       = rotation;
    _require_update = true;

    _clip_rotation();

    return *this;
}

glm::vec3 camera::rotation() const
{
    return _rotation;
}

camera& camera::update()
{
    glm::vec3 front;
    front.z = cosf ( glm::radians ( _rotation.x ) ) *
              cosf ( glm::radians ( _rotation.y ) );

    front.y = sinf ( glm::radians ( _rotation.x ) );

    front.x = cosf ( glm::radians ( _rotation.x ) ) *
              sinf ( glm::radians ( _rotation.y ) );

    _direction = glm::normalize ( front );

    _right = glm::normalize ( glm::cross ( WORLD_UP, _direction ) );
    _up    = glm::normalize ( glm::cross ( _direction, _right ) );

    _view = glm::lookAt ( _position, _position + _direction, WORLD_UP );

    return *this;
}

glm::mat4 camera::view()
{
    if ( _require_update ) {
        update();
    }

    return _view;
}

camera& camera::perspective ( float fov,
                                          float aspect,
                                          float near,
                                          float far ) {
    _projection = glm::perspective ( glm::radians ( fov ),
                                     aspect,
                                     near,
                                     far );

    return *this;
}

camera& camera::ortho ( float left,
                                    float right,
                                    float bottom,
                                    float top ) {
    _projection = glm::ortho ( left,
                               right,
                               bottom,
                               top );

    return *this;
}

camera& camera::ortho ( float left,
                                    float right,
                                    float bottom,
                                    float top,
                                    float near,
                                    float far ) {
    _projection = glm::ortho ( left,
                               right,
                               bottom,
                               top,
                               near,
                               far );

    return *this;
}

camera& camera::screen ( const dims_2u& dims )
{
    return ortho ( 0, dims.width, dims.height, 0 );
}

camera& camera::projection ( const glm::mat4& projection ) {
    _projection = projection;

    return *this;
}

glm::mat4 camera::projection() {
    return _projection;
}

void camera::_clip_rotation()
{
    _rotation.x = _rotation.x > 89.9f ? 89.9f : _rotation.x;
    _rotation.x = _rotation.x < -89.9f ? -89.9f : _rotation.x;
}
}
