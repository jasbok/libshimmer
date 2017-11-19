#ifndef GLPP_RESOURCE_MANAGER_H
#define GLPP_RESOURCE_MANAGER_H

#include "resource_loader.h"

#include <memory>

namespace glpp
{
class resource_manager
{
public:
    resource_manager() = default;

    resource_manager( resource_manager&& move ) = default;

    resource_manager( const resource_manager& copy ) = delete;

    virtual ~resource_manager() = default;

    resource_manager& operator=( resource_manager&& move ) = default;

    resource_manager& operator=( const resource_manager& copy ) = delete;


    void resource_paths ( const std::vector<std::string>& paths );


    std::shared_ptr<program> program ( const std::string& vertex,
                                       const std::string& fragment );

    std::shared_ptr<texture_2d> texture_2d(const std::string& id);

private:
    resource_loader _resource_loader;
};
}

#endif // RESOURCE_MANAGER_H
