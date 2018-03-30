#ifndef SHIMMER_CONFIG_H
#define SHIMMER_CONFIG_H

#include "environment.h"
#include "options.h"

#include <string>
#include <vector>

namespace shimmer
{
class config
{
public:
    const environment env;

    options opts;

    config();

    virtual ~config() = default;

    void save() const;
};
}

#endif // ifndef SHIMMER_CONFIG_H
