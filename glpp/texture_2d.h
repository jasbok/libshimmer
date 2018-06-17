#ifndef GLPP_TEXTURE_2D_H
#define GLPP_TEXTURE_2D_H

#include "specs.h"
#include "texture.h"

#include "common/img.h"

#include <memory>
#include <vector>

namespace glpp
{
class texture_2d : public texture
{
public:
    enum class min_filter : GLint {
        nearest                = GL_NEAREST,
        linear                 = GL_LINEAR,
        nearest_mipmap_nearest = GL_NEAREST_MIPMAP_NEAREST,
        linear_mipmap_nearest  = GL_LINEAR_MIPMAP_NEAREST,
        nearest_mipmap_linear  = GL_NEAREST_MIPMAP_LINEAR,
        linear_mipmap_linear   = GL_LINEAR_MIPMAP_LINEAR,
    };

    enum class mag_filter : GLint {
        nearest = GL_NEAREST,
        linear  = GL_LINEAR
    };

    enum class filter : GLint {
        nearest = GL_NEAREST,
        linear  = GL_LINEAR
    };

    enum class texture_wrap : GLint {
        clamp_to_edge   = GL_CLAMP_TO_EDGE,
        mirrored_repeat = GL_MIRRORED_REPEAT,
        repeat          = GL_REPEAT
    };

    /**
     * @brief texture_2d Generate a 2d texture.
     */
    explicit texture_2d();

    texture_2d( texture_2d&& move );

    texture_2d( const texture_2d& copy ) = delete;

    virtual ~texture_2d();

    texture_2d& operator=( texture_2d&& move );

    texture_2d& operator=( const texture_2d& copy ) = delete;

    /**
     * @brief dims Get the current dimensions of the texture.
     * @return The current dimensions of the current texture. Returns 0x0 if the
     * texture has not been initialised.
     */
    dims_2u dims() const;

    /**
     * @brief image Initialise the texture with the given format and dimensions.
     * @param internal_format The internal format of the texture.
     * @param dims The dimensions of the texture.
     * @return this
     */
    texture_2d& image ( internal_format internal_format,
                        const dims_2u&  dims );

    /**
     * @brief image Initialise the texture with the given image data, deriving
     * the internal format from the image itself.
     * @param internal_format The internal format of the texture.
     * @return this
     */
    texture_2d& image ( const common::img::image& image );

    /**
     * @brief image Initialise the texture with the given format and image data.
     * @param internal_format The internal format of the texture.
     * @param image The image data to load into the texture
     * @return this
     */
    texture_2d& image ( internal_format           internal_format,
                        const common::img::image& image );

    /**
     * @brief sub_image Loads the given image data into the texture at with an
     * offset of (0, 0).
     * @param image The image data to load in.
     * @return this
     */
    texture_2d& sub_image ( const common::img::image& image );

    /**
     * @brief sub_image Loads the given image data into the texture at the given
     * offset.
     * @param offset The offset to use when inserting the image data.
     * @param image The image data to load in.
     * @return this
     */
    texture_2d& sub_image ( const coords_2i&          offset,
                            const common::img::image& image );


    /**
     * @brief generate_mipmaps Generate the mipmaps for the texture.
     * @return this
     */
    texture_2d& generate_mipmaps();


    /**
     * @brief filters Sets the min and mag filters of this texture.
     * @param filter The filter value.
     * @return this
     */
    texture_2d& filters ( enum filter filter );

    /**
     * @brief min_filter Sets the min filter of this texture to the given value.
     * @param filter The filter value.
     * @return this
     */
    texture_2d& min_filter ( enum min_filter filter );

    /**
     * @brief mag_filter Sets the mag filter of this texture to the given value.
     * @param filter The filter value.
     * @return this
     */
    texture_2d& mag_filter ( enum mag_filter filter );


    static void set_filters ( enum filter filter );

    static void set_min_filter ( enum min_filter filter );

    static void set_mag_filter ( enum mag_filter filter );


    texture_2d& wrap ( enum texture_wrap wrap );

    texture_2d& wrap_s ( enum texture_wrap wrap );

    texture_2d& wrap_t ( enum texture_wrap wrap );

private:
    dims_2u _dims;

    internal_format _internal_format_from ( const common::img::image& image );

    GLenum          _gl_format_from ( const common::img::image& image );
};
}

#endif // ifndef GLPP_TEXTURE_2D_H
