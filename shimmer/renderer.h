#ifndef SHIMMER_RENDERER_H
#define SHIMMER_RENDERER_H

#include "configuration.h"

#include "common/logger.h"

#include "glpp/element_array_buffer.h"
#include "glpp/framebuffer.h"
#include "glpp/program.h"
#include "glpp/texture_2d.h"
#include "glpp/vertex_array.h"
#include "glpp/vertex_buffer.h"

namespace shimmer
{
class renderer
{
    struct shimmer::config::config* _conf;

    glpp::program _source_program;

    glpp::texture_2d _source_tex;

    glpp::framebuffer _source_fbo;

    glpp::program _target_program;

    glpp::texture_2d _target_tex;

    glpp::framebuffer _target_fbo;

    glpp::vbo _source_vbo;

    glpp::vbo _target_vbo;

    glpp::ebo _source_ebo;

    glpp::ebo _target_ebo;

    glpp::vao _source_vao;

    glpp::vao _target_vao;

    glpp::texture_2d::filter _texture_filter;

    common::dims_2u _source_resolution;

    common::dims_2u _intermediate_resolution;

    common::dims_2u _target_resolution;

    common::dims_2f _aspect;

    bool _flip_target;

public:
    static const common::logger& logger;

    static void init();

    renderer( struct shimmer::config::config* conf );

    virtual ~renderer() = default;

    void source_resolution ( const common::dims_2u& dims );

    void target_resolution ( const common::dims_2u& dims );

    void render();

    void capture_fbo();

    void reset_fbo();

    void activate_source_texture_unit();

    void setup_viewport();

    void copy_source ( uint8_t*               data,
                       const common::dims_2u& dims,
                       unsigned int           channels );

    void flip_target ( bool flip );

private:
    void _define_program ( glpp::program&     program,
                           const std::string& vertex,
                           const std::string& fragment,
                           int                texture_unit );

    void _define_vbo ( glpp::vbo&                vbo,
                       const std::vector<float>& data );

    void _define_ebo ( glpp::ebo&                      ebo,
                       const std::vector<unsigned int> indices );

    void _define_vao ( glpp::vao&     vao,
                       glpp::vbo&     vbo,
                       glpp::ebo&     ebo,
                       glpp::program& program );

    void _define_texture ( glpp::texture_2d&        tex,
                           const common::dims_2u&   dims,
                           glpp::texture_2d::filter filter,
                           unsigned int             texture_unit );

    void                      _calculate_aspect();

    std::vector<float>        _shape_position_texcoords();

    std::vector<unsigned int> _shape_indices();
};
} // namespace shimmer

#endif // ifndef SHIMMER_RENDERER_H
