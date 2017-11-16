#ifndef GLPP_SCENE_PHASE_H
#define GLPP_SCENE_PHASE_H

#include "camera.h"
#include "entity.h"
#include "framebuffer.h"
#include "specs.h"

#include <algorithm>
#include <memory>

namespace glpp
{
class scene_phase
{
public:
    scene_phase( const std::string                    id,
                 const std::shared_ptr<camera>&       camera,
                 const std::shared_ptr<viewport_int>& viewport,
                 const std::shared_ptr<framebuffer>&  fbo = 0 );

    scene_phase( scene_phase&& move ) = default;

    scene_phase( const scene_phase& copy ) = delete;

    virtual ~scene_phase() = default;

    scene_phase& operator=( scene_phase&& move ) = default;

    scene_phase& operator=( const scene_phase& copy ) = delete;


    std::string                        id() const;

    std::shared_ptr<class camera>      camera() const;

    std::shared_ptr<viewport_int>      viewport() const;

    std::shared_ptr<class framebuffer> framebuffer() const;

    scene_phase&                       entities (
        std::vector<std::shared_ptr<entity>>&& entities );


    scene_phase& add ( const std::shared_ptr<entity>& entity );

    scene_phase& remove (
        const std::shared_ptr<entity>& entity );


    void draw();

private:
    std::string _id;

    std::shared_ptr<class camera> _camera;

    std::shared_ptr<viewport_int> _viewport;

    std::shared_ptr<class framebuffer> _fbo;

    std::vector<std::shared_ptr<entity>> _entities;

    void _setup();
};
}

#endif // ifndef GLPP_SCENE_PHASE_H
