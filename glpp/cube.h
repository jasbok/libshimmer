#ifndef GLPP_CUBE_H
#define GLPP_CUBE_H

#include "mesh.h"
#include "specs.h"

#include "common/dims.h"

#include <memory>

namespace glpp
{
template<typename T>
class cube : public mesh
{
public:
    cube( const common::dims_3<T>& dimensions )
        : _dimensions()
    {
        bind()
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
            .template attribs<T>( {
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


    static auto make_shared ( const common::dims_3<T>& dimensions ) {
        return std::make_shared<cube>( dimensions );
    }

    static auto make_unique ( const common::dims_3<T>& dimensions ) {
        return std::make_unique<cube>( dimensions );
    }

    common::dims_3<T> dimensions() {
        return _dimensions;
    }

    cube& dimensions ( const common::dims_3<T>& dimensions ) {
        _dimensions = dimensions;

        vertices<T>( {
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

private:
    common::dims_3<T> _dimensions;
};
}

#endif // ifndef GLPP_CUBE_H
