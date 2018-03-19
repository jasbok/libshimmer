#ifndef SHIMMER_CONFIG_H
#define SHIMMER_CONFIG_H

#include "application.h"
#include "environment.h"
#include "options.h"
#include "pipeline.h"

#include <string>
#include <vector>

namespace shimmer
{
class config
{
public:
    config();

    virtual ~config() = default;

    void save() const;

    const environment env;

    application app;

    options opts;

    struct pipeline pipeline;
};
}

#endif // ifndef SHIMMER_CONFIG_H
