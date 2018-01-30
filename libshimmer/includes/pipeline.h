#ifndef SHIMMER_PIPELINE_H

#include <string>
#include <vector>

namespace shimmer
{
struct texture {
    std::string id;
    std::string path;
};

struct texture_binding {
    std::string variable;
    std::string texture_id;
};

struct shader {
    std::string vertex;
    std::string fragment;
};

struct pass
{
    std::string                  blend_func;
    std::vector<texture_binding> texture_bindings;
    struct shader                shader;
};

struct stage
{
    std::vector<pass> passes;
};

struct pipeline
{
    std::vector<stage> stages;
};
}

#endif // ifndef SHIMMER_PIPELINE_H
