#ifndef TEXTURE_UNITS_H
#define TEXTURE_UNITS_H

#include "texture_2d.h"

#include <memory>
#include <vector>

namespace glpp
{
class texture_units
{
public:
    typedef std::vector<std::shared_ptr<texture_2d>> group;

    texture_units() = default;

    texture_units( const group& textures );

    texture_units( texture_units&& move ) = default;

    texture_units( const texture_units& copy ) = default;

    virtual ~texture_units() = default;

    static std::shared_ptr<texture_units> make_shared ( group group );

    texture_units&                        operator=( texture_units&& move ) =
        default;

    texture_units& operator=( const texture_units& copy )
        = default;


    texture_units& textures ( const group& textures );

    group&         textures();


    texture_units& filters ( const texture_2d::filter& filter );

    texture_units& bind();

private:
    group _textures;
};
}

#endif // ifndef TEXTURE_UNITS_H
