#ifndef GLPP_QUAD_H
#define GLPP_QUAD_H

#include "mesh.h"
#include "specs.h"

namespace glpp
{
template<typename T>
class quad
{
public:
    quad( const dims_2<T>& dimensions )
        : _dimensions(),
          _mesh()
    {
        _mesh.bind()
            .indices ( {
                0, 1, 3,
                1, 2, 3
            } )
            .attribs ( {
                { "position", 3 },
                { "texcoord", 2 }
            } );

        this->dimensions ( dimensions );
    }

    quad( quad&& move ) = default;

    quad( const quad& copy ) = delete;

    virtual ~quad() = default;

    quad& operator=( quad&& move ) = default;

    quad& operator=( const quad& copy ) = delete;


    quad& bind() {
        _mesh.bind();

        return *this;
    }

    quad& unbind() {
        _mesh.unbind();

        return *this;
    }

    dims_2<T> dimensions() {
        return _dimensions;
    }

    quad& dimensions ( const dims_2<T>& dimensions ) {
        _dimensions = dimensions;

        _mesh.vertices ( {
                // Top Right
                _dimensions.width, _dimensions.height, 0,
                1, 0,

                // Bottom Right
                _dimensions.width, -_dimensions.height, 0,
                1, 1,

                // Bottom Left
                -_dimensions.width, -_dimensions.height, 0,
                0, 1,

                // TOP Left
                -_dimensions.width, _dimensions.height, 0,
                0, 0
            } );

        return *this;
    }

    quad& program ( const program& program ) {
        _mesh.program ( program );

        return *this;
    }

    quad& draw() {
        _mesh.draw();

        return *this;
    }

private:
    dims_2<T> _dimensions;

    mesh<T> _mesh;
};
}

#endif // GLPP_QUAD_H
