#include "texture_units.h"

using namespace glpp;
using namespace std;

glpp::texture_units::texture_units( const glpp::texture_units::group& textures )
    : _textures ( textures )
{}

texture_units& texture_units::textures ( const texture_units::group& textures )
{
    _textures = textures;

    return *this;
}

std::shared_ptr<texture_units> texture_units::make_shared ( group group ) {
    return std::make_shared<texture_units>( group );
}

texture_units::group& texture_units::textures() {
    return _textures;
}

texture_units& texture_units::bind()   {
    GLuint unit = 0;

    for ( auto& texture : _textures ) {
        if ( texture != nullptr ) {
            texture->bind_texture_unit ( unit );
        }
        unit++;
    }

    return *this;
}

texture_units& texture_units::filters ( const texture_2d::filter& filter )
{
    for ( auto& texture : _textures ) {
        texture->bind();
        texture->filters ( filter );
    }

    return *this;
}
