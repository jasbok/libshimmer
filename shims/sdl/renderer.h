#ifndef SHIMS_SDL_RENDERER_H
#define SHIMS_SDL_RENDERER_H

#include "glpp/element_array_buffer.h"
#include "glpp/framebuffer.h"
#include "glpp/program.h"
#include "glpp/texture_2d.h"
#include "glpp/vertex_array.h"
#include "glpp/vertex_buffer.h"

class renderer
{
    class shim* _shim;

    glpp::program _source_prog;

    glpp::texture_2d _source_tex;

    glpp::framebuffer _source_fbo;

    glpp::program _target_prog;

    glpp::texture_2d _target_tex;

    glpp::framebuffer _target_fbo;

    glpp::vbo _vbo;

    glpp::vbo _target_vbo;

    glpp::ebo _ebo;

    glpp::vao _vao;

    glpp::vao _target_vao;

    glpp::texture_2d::filter _texture_filter;

    common::dims_2u _source_resolution;

    common::dims_2u _intermediate_resolution;

    common::dims_2u _target_resolution;

    common::dims_2f _aspect;

    bool _flip_target;

public:
    static void init();

    renderer( class shim* shim );

    virtual ~renderer() = default;

    void source_resolution ( const common::dims_2u& dims );

    void target_resolution ( const common::dims_2u& dims );

    void render();

    void capture_fbo();

    void reset_fbo();

    void setup_viewport();

    void copy_source ( uint8_t*               data,
                       const common::dims_2u& dims,
                       unsigned int           channels );

    void flip_target ( bool flip );

private:
    void _create_source_program();

    void _create_target_program();

    void _create_vbo();

    void _create_target_vbo();

    void _create_ebo();

    void _create_vao();

    void _create_target_vao();

    void _create_fbo();

    void _create_target_fbo();

    void _create_texture ( const common::dims_2u& dims );

    void _create_target_texture ( const common::dims_2u& dims );

    void _calculate_aspect();
};

#endif // ifndef SHIMS_SDL_RENDERER_H
