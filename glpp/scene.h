#ifndef GLPP_SCENE_H
#define GLPP_SCENE_H

#include "scene_phase.h"

#include <iostream>

namespace glpp
{
class scene
{
public:
    scene() = default;

    scene( scene&& move ) = default;

    scene( const scene& copy ) = delete;

    virtual ~scene() = default;

    scene&       operator=( scene&& move ) = default;

    scene&       operator=( const scene& copy ) = delete;

    scene_phase& operator[]( const std::string& id );


    scene&       add ( scene_phase&& phase );

    scene_phase& find ( const std::string& id );

    void         draw();

private:
    std::vector<scene_phase> _phases;
};

struct phase_not_found_exception : public std::exception {
    const char* what() const throw( ) {
        return "Could not find the specified scene phase.";
    }
};
}

#endif // ifndef GLPP_SCENE_H
