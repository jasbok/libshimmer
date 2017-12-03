#ifndef GLPP_QUAD_H
#define GLPP_QUAD_H

#include "mesh.h"
#include "specs.h"

namespace glpp
{
template<typename T>
class quad : public mesh
{
public:
    explicit quad( const dims_2<T>& dimensions, bool flip_y = false )
        : _dimensions()
    {
        bind()
            .indices ( {
                0, 1, 3,
                1, 2, 3
            } )
            .template attribs<T>( {
                { "position", 3 },
                { "texcoord", 2 }
            } );

        this->dimensions ( dimensions, flip_y );
    }

    quad( quad&& move ) = default;

    quad( const quad& copy ) = delete;

    virtual ~quad() = default;

    quad& operator=( quad&& move ) = default;

    quad& operator=( const quad& copy ) = delete;


    static auto make_shared ( const dims_2<T>& dimensions,
                              bool             flip_y = false ) {
        return std::make_shared<quad>( dimensions, flip_y );
    }

    static auto make_unique ( const dims_2<T>& dimensions ) {
        return std::make_unique<quad>( dimensions );
    }

    dims_2<T> dimensions() {
        return _dimensions;
    }

    quad& dimensions ( const dims_2<T>& dimensions, bool flip_y = false ) {
        _dimensions = dimensions;

        T sign = flip_y ? -1 : 1;

        vertices<T>( {
                // Top Right
                _dimensions.width, sign * _dimensions.height, 0,
                1, 0,

                // Bottom Right
                _dimensions.width, sign * -_dimensions.height, 0,
                1, 1,

                // Bottom Left
                -_dimensions.width, sign * -_dimensions.height, 0,
                0, 1,

                // TOP Left
                -_dimensions.width, sign * _dimensions.height, 0,
                0, 0
            } );

        return *this;
    }

private:
    dims_2<T> _dimensions;
};
}

#endif // GLPP_QUAD_H
