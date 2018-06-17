#ifndef APIGEN_DECL_H
#define APIGEN_DECL_H

#include <string>
#include <vector>

namespace apigen
{
struct type_decl {
    std::string raw;

    std::string type;
};

struct parameter_decl {
    std::string raw;

    struct type_decl type;

    std::string name;

    std::string type_name;
};

struct function_decl {
    std::string raw;

    struct type_decl ret;

    std::string name;

    std::vector<struct parameter_decl> parameters;
};
}

#endif // ifndef APIGEN_DECL_H
