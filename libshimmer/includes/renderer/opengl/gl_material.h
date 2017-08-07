#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_MATERIAL_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_MATERIAL_H

#include "gl_program.h"
#include "gl_texture.h"

#include <memory>
#include <vector>

namespace shimmer
{
class gl_material
{
public:
    gl_material( const std::shared_ptr<gl_program>&              program,
                 const std::vector<std::shared_ptr<gl_texture>>& textures );

    virtual ~gl_material();

    void use();

private:
    std::shared_ptr<gl_program> _program;

    std::vector<std::shared_ptr<gl_texture>> _textures;

    std::vector<gl_program_variable> _sampler2ds;

    typedef std::unordered_map<std::string, gl_program_variable> variable_map;

    GETTER ( variable_map, inputs );

    GETTER ( variable_map, uniforms );

    void _process_variables ( const std::vector<glsl_variable>& variables );

    void _add_input ( const glsl_variable& variable );

    void _add_uniform ( const glsl_variable& variable );

    void _add_sampler2d ( const glsl_variable& variable );

    void _bind_textures();
};
}

#endif // ifndef LIBSHIMMER_RENDERER_OPENGL_GL_MATERIAL_H
