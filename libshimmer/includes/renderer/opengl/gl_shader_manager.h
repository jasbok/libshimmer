#ifndef LIBSHIMMER_RENDERER_OPENGL_GL_SHADER_MANAGER_H
#define LIBSHIMMER_RENDERER_OPENGL_GL_SHADER_MANAGER_H

#include "gl_shader.h"
#include "cache.hpp"
#include <GL/glew.h>
#include <memory>
#include <string>

namespace shimmer
{
class gl_shader_manager
    :  public cache<std::string, std::shared_ptr<gl_shader>>
{
public:
    gl_shader_manager();

    virtual ~gl_shader_manager() {}

    void clear () override;

    std::shared_ptr<gl_shader> evict (const std::string& id) override;

    bool exists (const std::string& id) override;

    std::shared_ptr<gl_shader> get ( const std::string& id ) override;

    std::shared_ptr<gl_shader> load ( const std::string& path, GLuint type);

    void set (
        const std::string& id,
        const std::shared_ptr<gl_shader>& shader ) override;

private:
    std::shared_ptr<cache<std::string, std::shared_ptr<gl_shader>>> _cache;
};
}

#endif
