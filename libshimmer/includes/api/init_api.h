#ifndef LIBSHIMMER_API_INIT_API_H
#define LIBSHIMMER_API_INIT_API_H

#include <string>

namespace shimmer
{
class init_api
{
public:
    virtual ~init_api () {}

    virtual void shim_name(const std::string& name);

    virtual void shim_description(const std::string& description);

    virtual void shim_version(const std::string& version);

    virtual void render_mode ( int mode ) = 0;
};
}

#endif
