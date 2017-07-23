#include "catch.hpp"
#include "gl_shader_manager.h"
#include "spdlog.h"

using namespace std;
using namespace shimmer;

TEST_CASE ( "Load, store and retrieve shaders from the shader manager.",
            "[gl_shader_manager]" )
{
    gl_shader_manager shader_manager;
    string fs_shader_path = "data/glsl/simple.fs";
    string vs_shader_path = "data/glsl/simple.vs";

    auto fs_shader = shader_manager.load(fs_shader_path, GL_FRAGMENT_SHADER);
    auto vs_shader = shader_manager.load(vs_shader_path, GL_VERTEX_SHADER);

    CHECK(fs_shader->id() == fs_shader_path);
    CHECK(fs_shader->path() == fs_shader_path);
    CHECK(fs_shader->handle() != 0);
    CHECK(fs_shader->variables().size() == 3);

    CHECK(vs_shader->id() == vs_shader_path);
    CHECK(vs_shader->path() == vs_shader_path);
    CHECK(vs_shader->handle() != 0);
    CHECK(vs_shader->variables().size() == 4);

    shader_manager.set(fs_shader->id(), fs_shader);
    shader_manager.set(vs_shader->id(), vs_shader);
    CHECK(shader_manager.exists(fs_shader->id()) == true);
    CHECK(shader_manager.exists(vs_shader->id()) == true);

    auto fs_shader_ref = shader_manager.get(fs_shader->id());
    auto vs_shader_ref = shader_manager.get(vs_shader->id());

    CHECK(fs_shader == fs_shader_ref);
    CHECK(vs_shader == vs_shader_ref);

    CHECK(fs_shader.use_count() == 3);
    CHECK(vs_shader.use_count() == 3);

    CHECK(shader_manager.evict(fs_shader->id()) == fs_shader);
    CHECK(shader_manager.exists(fs_shader->id()) == false);
    CHECK(shader_manager.exists(vs_shader->id()) == true);
    CHECK(fs_shader.use_count() == 2);
    CHECK(vs_shader.use_count() == 3);

    shader_manager.clear();
    CHECK(shader_manager.exists(fs_shader->id()) == false);
    CHECK(shader_manager.exists(vs_shader->id()) == false);
    CHECK(fs_shader.use_count() == 2);
    CHECK(vs_shader.use_count() == 2);

    fs_shader_ref = nullptr;
    vs_shader_ref = nullptr;
    CHECK(fs_shader.use_count() == 1);
    CHECK(vs_shader.use_count() == 1);
}
