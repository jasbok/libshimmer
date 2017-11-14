#ifndef GLPP_PHASE_H
#define GLPP_PHASE_H

#include "camera.h"
#include "entity.h"
#include "mesh.h"
#include "program.h"
#include "texture_2d.h"

#include <algorithm>
#include <memory>
#include <vector>

namespace glpp
{
template<typename T, typename THIS>
class phase
{
public:
    virtual ~phase() {}

    phase& add ( T&& phase ) {
        _phases.push_back ( std::move ( phase ) );

        return static_cast<THIS&>( *this );
    }

    phase& sort() {
        std::sort ( _phases.begin(), _phases.end() );

        return static_cast<THIS&>( *this );
    }

    void draw() {
        setup();

        for ( auto& phase : _phases ) {
            phase.draw();
        }
    }

    virtual void setup() = 0;

private:
    std::vector<T> _phases;
};

class mesh_phase : public phase<entity, mesh_phase>
{
public:
    void setup() override {
        _mesh->bind();
    }

private:
    std::shared_ptr<mesh> _mesh;
};

class texture_phase : public phase<mesh_phase, texture_phase>
{
public:
    void setup() override {}

private:
    std::shared_ptr<texture_2d> _texture;
};

class program_phase : public phase<texture_phase, program_phase>
{
public:
    void setup() override {}

private:
    std::shared_ptr<program> _program;
};

class scene_phase : public phase<program_phase, scene_phase>
{
public:
    void setup() override {}

private:
    camera _camera;
};

class scene : public phase<scene_phase, scene>
{
public:
    void setup() override {}

private:
};
}


#endif // ifndef GLPP_PHASE_H
