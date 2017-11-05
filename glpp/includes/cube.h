#ifndef GLPP_CUBE_H
#define GLPP_CUBE_H

#include "mesh.h"
#include "specs.h"

namespace glpp
{
template<typename T>
class cube
{
public:
    cube( const dims_3<T>& dimensions )
        : _dimensions(),
          _mesh()
    {
        _mesh.bind()
            .indices ( {
                // Front
                0, 1, 3,
                1, 2, 3,

                // Back
                4, 5, 7,
                5, 6, 7,

                // Top
                8, 9, 10,
                10, 11, 8,

                // Bottom
                12, 13, 14,
                14, 15, 12,

                // Left
                7, 3, 2,
                2, 6, 7,

                // Right
                0, 4, 5,
                5, 1, 0
            } )
            .attribs ( {
                { "position", 3 },
                { "texcoord", 2 }
            } );

        this->dimensions ( dimensions );
    }

    cube( cube&& move ) = default;

    cube( const cube& copy ) = delete;

    virtual ~cube() = default;

    cube& operator=( cube&& move ) = default;

    cube& operator=( const cube& copy ) = delete;


    cube& bind() {
        _mesh.bind();

        return *this;
    }

    cube& unbind() {
        _mesh.unbind();

        return *this;
    }

    dims_3<T> dimensions() {
        return _dimensions;
    }

    cube& dimensions ( const dims_3<T>& dimensions ) {
        _dimensions = dimensions;

        _mesh.vertices ( {
                // Front Top Right
                _dimensions.width, _dimensions.height, _dimensions.depth,
                1, 0,

                // Front Bottom Right
                _dimensions.width, -_dimensions.height, _dimensions.depth,
                1, 1,

                // Front Bottom Left
                -_dimensions.width, -_dimensions.height, _dimensions.depth,
                0, 1,

                // Front Top Left
                -_dimensions.width, _dimensions.height, _dimensions.depth,
                0, 0,


                // Back Top Right
                _dimensions.width, _dimensions.height, -_dimensions.depth,
                0, 0,

                // Back Bottom Right
                _dimensions.width, -_dimensions.height, -_dimensions.depth,
                0, 1,

                // Back Bottom Left
                -_dimensions.width, -_dimensions.height, -_dimensions.depth,
                1, 1,

                // Back Top Left
                -_dimensions.width, _dimensions.height, -_dimensions.depth,
                1, 0,


                // Back Top Right
                _dimensions.width, _dimensions.height, -_dimensions.depth,
                1, 1,

                // Front Top Right
                _dimensions.width, _dimensions.height, _dimensions.depth,
                1, 0,

                // Front Top Left
                -_dimensions.width, _dimensions.height, _dimensions.depth,
                0, 0,

                // Back Top Left
                -_dimensions.width, _dimensions.height, -_dimensions.depth,
                0, 1,


                // Back Bottom Right
                _dimensions.width, -_dimensions.height, -_dimensions.depth,
                1, 0,

                // Front Bottom Right
                _dimensions.width, -_dimensions.height, _dimensions.depth,
                1, 1,

                // Front Bottom Left
                -_dimensions.width, -_dimensions.height, _dimensions.depth,
                0, 1,

                // Back Bottom Left
                -_dimensions.width, -_dimensions.height, -_dimensions.depth,
                0, 0,
            } );

        return *this;
    }

    cube& program ( const program& program ) {
        _mesh.program ( program );

        return *this;
    }

    cube& draw() {
        _mesh.draw();

        return *this;
    }

private:
    dims_3<T> _dimensions;

    mesh<T> _mesh;
};
}

#endif // ifndef GLPP_CUBE_H
